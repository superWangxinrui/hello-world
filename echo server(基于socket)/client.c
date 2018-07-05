#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
int main(int argc,char* argv[]){
	if(argc!=3){
		printf("Usage ./client [ip] [port]");
		return 1;
	}
	int sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock<0){
		perror("socket");
		return 2;
	}
	char buf[1024];
	char bufout[1024];
	struct sockaddr_in server_sock;
	server_sock.sin_family=AF_INET;
	server_sock.sin_port=htons(atoi(argv[2]));
	server_sock.sin_addr.s_addr=inet_addr(argv[1]);
	if(connect(sock,(struct sockaddr*)&server_sock,sizeof(server_sock))<0){
		perror("connect");
		return 2;
	}
	printf("connect successed\n");
	while(1){
		printf("please Enter#:");
		fflush(stdout);
		ssize_t s=read(0,buf,sizeof(buf)-1);
		if(s>0){
		buf[s-1]=0;
		write(sock,buf,strlen(buf));
		ssize_t _s=read(sock,bufout,sizeof(bufout)-1);
		if(_s<0){
			perror("read sock");
			return 3;
		}
		if(_s=0){
			printf("server close\n");
			close(sock);
		}
		printf("server echo#:%s\n",bufout);
	}
}
}



