#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<arpa/inet.h>
#include<netinet/in.h>
typedef struct Arg{
	int newsock1;
	struct sockaddr_in client1;
        int newsock2;
        struct sockaddr_in client2;
}Arg;

void* ThreadEntry(void*arg1){
	Arg* arg=(Arg*)arg1;
while(1){
	char buf[1024]={0};
	ssize_t size=read(arg->newsock1,buf,sizeof(buf)-1);
	if(size<0){
		perror("read");
		return NULL;
	}
	if(size==0){
       printf("client1 disconnect!\n");
	   close(arg->newsock1);
//	   free(arg);
}
write(arg->newsock2,buf,strlen(buf));
         size=read(arg->newsock2,buf,sizeof(buf)-1);
	if(size<0){
		perror("read");
		return NULL;
	}
	if(size==0){
       printf("client2 disconnect!\n");
	   close(arg->newsock2);
	   free(arg);
}
write(arg->newsock1,buf,strlen(buf));
//printf("client[%s][%d] say#:%s\n",inet_ntoa(arg->client.sin_addr),ntohs(arg->client.sin_port),buf);
//printf("请回复:");
 //fflush(stdout);
 //ssize_t s=read(0,buf,sizeof(buf)-1);
//	 if(s>0){
//		 buf[s-1]=0;
//}
}
}
void Processconnect(int newsock1,struct sockaddr_in client1,int newsock2,struct sockaddr_in client2){
	//创建线程，新线程来循环读写，主线程去调用accept
	Arg *arg=(Arg*)malloc(sizeof(Arg));//为什么要申请堆上的内存，而不用栈上的内存，因为如果使用栈上开辟的内存
	//processconnect函数执行完之后arg的空间会销毁，此时在ThreadEntry函数中arg就成了野指针。如果定义为全局变量
	//，可能产生数据覆盖。
	arg->newsock1=newsock1;
	arg->client1=client1;
	arg->newsock2=newsock2;
	arg->client2=client2;
	pthread_t tid;
	pthread_create(&tid,NULL,ThreadEntry,(void*)arg);//创建新线程
	pthread_detach(tid);
}

int main(int argc,char* argv[]){
	if(argc!=3){//判断参数的合法性
		printf("./server [ip] [port]\n");
		return 1;
	}
	int sock=socket(AF_INET,SOCK_STREAM,0);//定义sock文件描述符
	if(sock<0){
		perror("sock");
		return 2;
	}
	struct sockaddr_in server;
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr(argv[1]);
	server.sin_port=htons(atoi(argv[2]));
int ret=bind(sock,(struct sockaddr*)&server,sizeof(server));//绑定ip地址端口号
if(ret<0){
perror("bind");
return 3;
}
ret=listen(sock,5);//设置为监听模式
if(ret<0){
	perror("listen");
	return 4;
}
printf("------------------------------------chat_room聊天室服务器启动完成------------------------------------------\n");
while(1){
	struct sockaddr_in client1;
	int len1=sizeof(client1);
int newsock1=accept(sock,(struct sockaddr*)&client1,&len1);
if(newsock1<0){
	perror("accept");
	continue;
}
printf("client1 connect success!\n");
	struct sockaddr_in client2;
	int len2=sizeof(client2);
int newsock2=accept(sock,(struct sockaddr*)&client2,&len2);
if(newsock2<0){
	perror("accept");
	continue;
}
printf("client2 connect success!\n");
Processconnect(newsock1,client1,newsock2,client2);
}
}


