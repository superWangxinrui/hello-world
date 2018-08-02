//此处实现的可执行程序就是CGI程序
///////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<mysql/mysql.h>
#include<fcntl.h>
#include"cgi_base.h"
void RenderHtml(struct tm*tp){
// 1 打开 index.html 文件
int fd=open("./wwwroot/cgi-bin/index.html",O_RDONLY);
if(fd<0){
fprintf(stderr,"文件打开失败！\n");
return;
}
// 2 逐个字符读取文件中的内容
char c='\0';
while(read(fd,&c,1)>0){
if(c=='\1'){
//这个位置需要替换成时间
printf("%02d:%02d",tp->tm_hour,tp->tm_min);
fflush(stdout);
}
else{
write(1,&c,1);
}
}
close(fd);
}
int main(){
	//1 获取city
char buf[1024*10]={0};
int ret= GetQueryString(buf);
if(ret<0){
fprintf(stderr,"[CGI] Getquerystring failed!\n");
return 1;
}
char city[1024*4]={0};
sscanf(buf,"city=%s",city);
//2   从数据库中获取时差
//a) 连接到数据库
//有了一个空遥控器
MYSQL * connect_fd=mysql_init(NULL);
//拿遥控器和数据库进行配对
MYSQL* connect_ret=mysql_real_connect(connect_fd,"127.0.0.1","root","","TestDB",3306,NULL,0);
if(connect_ret==NULL){
fprintf(stderr,"mysql connect failed!\n");
return 1;
}
fprintf(stderr,"mysql connect ok!\n");
//b)拼装sql语句
//组织命令
char sql[1024*4]={0};
sprintf(sql,"select timediff from WorldTime where city='%s'",city);
// c) 把sql语句发送到服务器，使用遥控器把命令发给服务器
ret=mysql_query(connect_fd,sql);
if(ret<0){
fprintf(stderr,"mysql_query failed! %s\n",sql);
mysql_close(connect_fd);
return 1;
}
//d) 读取并遍历服务器返回的结果
MYSQL_RES* result=mysql_store_result(connect_fd); 
if(result==NULL){
fprintf(stderr,"mysql_store_result failed! \n");
return 1;
}
//获取到表有几行几列
//  int rows=mysql_num_rows(result);
  //int fields=mysql_num_fields(result);
// 获取到结果集合的表结构
//MYSQL_FIELD* field=mysql_fetch_field(result);
//while(field!=NULL){
//printf("%s\t",field->name);
//field=mysql_fetch_field(result);
//}
//printf("<br>");
//获取每个元素的具体值

MYSQL_ROW row=mysql_fetch_row(result);
if(row==NULL){
printf("<h1>The city you query does not exit!</h1>!\n");
mysql_close(connect_fd);
return 1;
}
double time_diff=atof(row[0]);
mysql_close(connect_fd);
//3 获取系统时间，根据时差进行计算，得到对方城市时间
time_t t=time(NULL);//当前时间戳
t+=time_diff*3600;
struct tm* tp= localtime(&t);
//4 响应结果
 RenderHtml(tp);
//printf 输出的结果就会被返回到客户端上
//作为 HTTP服务器，每次给客户端返回的字符串必须
//符合HTTP协议的格式
//由于父进程已经把 首行 header 空行 都已经写回给客户端
//因此此时 CGI 程序只返回 body 部分即可，就是html格式的数据
return 0;
}
