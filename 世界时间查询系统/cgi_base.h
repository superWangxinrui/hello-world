#pragma
//此处实现的可执行程序就是CGI程序
///////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

//分get post 两种情况来读取计算的参数
//1. GET 从 query_string读取
//2. post 从body中读取
//读取结果就放在buf这个输出缓冲区中
static int GetQueryString(char buf[]){
//1. 从环境变量中获取到方法是什么
char * method=getenv("REQUEST_METHOD");
if(method==NULL){
//由于当前的CGI程序对应的标准输出已经被重定向
//到官道上了，而这部分数据又会被返回给客户端
//避免让程序内部的错误暴露给用户，通过 stderr来
//作为输入日志的手段
fprintf(stderr,"method==NULL\n");
return -1;
}
// 2. 判断方法是 GET 还是 POST。
// 如果是GET，就从环境变量里面读取 QUERY_STRING
// 如果是 POST，就需要从环境变量里读取 CONTENT_LENGTH
if(strcasecmp(method,"GET")==0){
		char *query_string=getenv("QUERY_STRING");
		if(query_string==NULL){
		fprintf(stderr,"query_string is NULL\n");
		return -1;
		}
		//拷贝完成后，buf里边的内容形如 a=10&b=20
		strcpy(buf,query_string);
		}else{
		char *content_length_str=getenv("CONTENT_LENGTH");
		if(content_length_str==NULL){
		fprintf(stderr,"content_length is NULL\n");
		return -1;
		}
int content_length=atoi(content_length_str);
int i=0;
for(;i<content_length;i++){
//此处由于父进程把body 已经写入管道
//子进程又把0号文件描述符重定向到了管道
//此时从标准输入来读数据，也就读到了管道中的数据
read(0,&buf[i],1);
}
buf[i]='\0';
//此循环读完后，buf里面的内容就形如
//a=10&b=20
}
return 0;
}
