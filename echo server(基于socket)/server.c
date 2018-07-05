#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<signal.h>
#include <sys/types.h>
void ProcessConnect(int newsock,struct sockaddr_in client){
 int ret=fork();
 if(ret>0){//让父进程去执行accept,不能用wait
	 //!!如果直接返回，会产生僵尸进程
	 //！！如果直接在此处wait，由于wait是阻塞等待子进程结束，才返回，就不能达到快速调用第二次accept的效果。
	 //！！如果采用非阻塞式调用，此时，如果调用一次，相当于子进程还没有结束，waitpid快速返回，虽然能够快速调用到第二次accept
	 //,但由于waitpid没有真正回收子进程资源，此时还会出现僵尸进程。
	 //如果采用轮询方式调用，虽然能保证没有僵尸进程，但不能达到快速调用accept的目的
	 //合理的方式就是采用捕捉信号，或者忽略SIGCHILD
close(newsock);//父进程关闭文件描述符
return;
 
}
else if(ret==0){//子进程
	while(1){
		char buf[1024]={0};
		ssize_t len=read(newsock,buf,sizeof(buf)-1);
		if(len<0){
			perror("read");
			return;
		}
		if(len==0){
printf("client disconnect\n");
close(newsock);//子进程关闭文件描述符
exit(0);
	}
printf("client[%s] [%d] say#%s\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port),buf);
write(newsock,buf,strlen(buf));
}
}
else{
	perror("fork");
}
}

int main(int argc,char* argv[]){
	if(argc!=3){
		printf("./server [ip] [port]\n");
		return 1;
	}
	signal(SIGCHLD,SIG_IGN);
	int sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock<0){
		perror("socket");
		return 2;
	}
	struct sockaddr_in server;
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr(argv[1]);
	server.sin_port=htons(atoi(argv[2]));
	int ret=bind(sock,(struct sockaddr*)&server,sizeof(server));
	if(ret<0){
		perror("bind");
		return 3;
	}
	ret=listen(sock,5);
	if(ret<0){
		perror("listen");
		return 4;
	}
while(1){
	struct sockaddr_in client;
	int len=sizeof(client);
int newsock=accept(sock,(struct sockaddr*)&client,&len);
if(newsock<0){
	perror("accept");
	continue;
}
//创建子进程，让父进程能快速的调用accept,等待第二个客户端的连接，让子进程来处理当前这个连接的读写
ProcessConnect(newsock,client);
}
close(sock);
return 0;
}
