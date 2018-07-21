//此处实现的可执行程序就是CGI程序
///////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"cgi_base.h"
int main(){
char buf[1024*10]={0};
int ret= GetQueryString(buf);
if(ret<0){
fprintf(stderr,"[CGI] Getquerystring failed!\n");
}
int a,b;
sscanf(buf,"a=%d&b=%d",&a,&b);
int sum=a+b;
//printf 输出的结果就会被返回到客户端上
//作为 HTTP服务器，每次给客户端返回的字符串必须
//符合HTTP协议的格式
//由于父进程已经把 首行 header 空行 都已经写回给客户端
//因此此时 CGI 程序只返回 body 部分即可，就是html格式的数据
printf("<h1>sum=%d</h1>",sum);
return 0;
}
