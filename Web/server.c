#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<pthread.h>
#include"server.h"
#include <sys/stat.h>
#include<fcntl.h>
#include<sys/sendfile.h>
#include<sys/wait.h>
typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
//一次从socket中读取一行数据
//把数据放到buf缓冲区中
//如果读取失败，返回-1
//\n \r \r\n
int ReadLine(int sock,char buf[],ssize_t size){
	//从socket中一次读取一个字符
	char c='\0';
	ssize_t i=0;//当前读了多少字符
	//结束条件：
	//a) 读的长度太长，达到了缓冲区长度的上限
	//b) 读到了\n(此处我们要兼容\r \r\n的情况，如果遇到\r\n或者\r 想办法换成\n
	while(i<size-1&&c!='\n'){
		ssize_t read_size=recv(sock,&c,1,0);
		if(read_size<=0){
			//预期是读到\n这样的换行符，结果还没读到呢，
			//就先读到了EOF,这种情况我们也暂时认为是失败
			return -1;
		}
		if(c=='\r'){
			//当前遇到了\r,但是还需要确定下一个字符是不是\n
			//MSG_PEEK 选项从内核的缓冲区中读数据
			//但是读到的数据不会从缓冲区中删除掉
			recv(sock,&c,1,MSG_PEEK);
            if(c=='\n'){
				recv(sock,&c,1,0);
			}else{
				c='\n';
			}
		}
       buf[i++]=c;
	}
	buf[i]='\0';
	return i;//实际读到的字符个数
	//如果读到\n就返回
}
int split(char input[],char*split_char,char *output[],int output_size){
	 // strtok不是一个线程安全的函数。因为根据其定义，它必须使用
	 // 内部静态变量来记录字符串中下一个需要解析的标记的当前位置。
	 // 但是，由于指示这个位置的变量只有一个，那么，在同一个程序中出	
         // 现多个解析不同字符串的strtok调用时，各自的字符串的解析就会互相干扰。所以使用strtok_r
        //strtok_r会破坏待分解字符串的完整性，但是将剩余字符串保存在手动传入的缓冲区中。保证了安全性。
	int i=0;
	char *pch;
	char*tmp=NULL;//strtok_r需要手动传入缓冲区
	pch=strtok_r(input,split_char,&tmp);
	while(pch!=NULL){
    if(i>=output_size){
		return i;
	}
	output[i++]=pch;
	pch=strtok_r(NULL,split_char,&tmp);
	} 
	return i;
}
int ParseFirstLine(char first_line[],char**p_url,char**p_method){
	//把首行按照空格进行字符串切分
	char *tok[10];
	//切分得到的每一个部分，就放到tok数组之中
	//返回值就是tok数组中包含几个元素
	//最后一个参数10表示tok数组中最多能放几个元素
	int tok_size=split(first_line," ",tok,10);
	if(tok_size!=3){//切分出来的是 方法 url 版本号
		printf("Split failed! tok_size=%d\n",tok_size);
		return -1;
	}
	*p_method=tok[0];
	*p_url=tok[1];
	return 0;
}
int ParseQueryString(char*url,char**p_url_path,char**p_query_string){
	*p_url_path=url;
	char*p=url;
	for(;*p!='\0';++p){
		if(*p=='?'){
			*p='\0';
			*p_query_string=p+1;
			return 0;
		}
	}
	//循环结束都没找到？，说明这个请求不带query_string
	*p_query_string=NULL;
	return 0;
}
int ParseHeader(int sock,int *content_length){
	char buf[SIZE]={0};
	while(1){
		//1循环从socket中读取一行
		size_t read_size=ReadLine(sock,buf,sizeof(buf));
		//处理读失败的情况
		if(read_size<=0){
	     return -1;
		}
		//处理读完的情况，读到空行
		if(strcmp(buf,"\n")==0){
	      return 0;
		}
		//2 判定当前行是不是Content-Length
		//如果是，就直接把value读出来
		//如果不是就丢弃
		//strncmp比较字符串前n个字符是否相等
		const char*content_length_str="Content-Length: ";
		if(content_length!=NULL&&strncmp(buf,content_length_str,strlen(content_length_str))==0){
	     *content_length=atoi(buf+strlen(content_length_str));//只把value的值赋给content_length
		}
	}
return 0;
}
void Handler404(int sock){
//构造一个完整的HTTP响应
//状态码就是404
//body部分应该也是一个404页面
const char * first_line="HTTP/1.1 404 NOT Found\n";
const char* blank_line="\n";
const char* type_line="\" Content-Type:\"\" text/html;charset=utf-8\"\n";//在headler部分也加上，增强代码的健壮性，保证
//任何浏览器都不乱码
const char* html="<head><meta http-equiv=\"Content-Type\" content=\"text/html;charset=utf-8\"> </head>"
	"<h1>404 Nou Found   您的页面不小心走丢了了！！！！</h1>";
send(sock,first_line,strlen(first_line),0);
send(sock,type_line,strlen(type_line),0);
send(sock,blank_line,strlen(blank_line),0);
send(sock,html,strlen(html),0);
return;
}
int IsDir(const char* file_path){//判断是文件还是目录
struct stat st;
int ret=stat(file_path,&st);//stat可以获取到file_path的详细信息，存放在结构体st中
if(ret<0){//文件不存在，表示不是目录
	return 0;
}
if(S_ISDIR(st.st_mode)){//通过S_ISDIR这个宏来判定file_path是否是一个目录，st.mode保存的是文件类型
return 1;
}
return 0;
}
void HandlerFilePath(const char*url_path,char file_path[]){
//HTTP服务器的根目录：用户指定的任意一个存在的目录
//url_path =>/index.html
//file_path=>./wwwroot/index.html
//a)给 url_path 加上前缀
sprintf(file_path,"./wwwroot%s",url_path);//字符串拼接
//b)例如：url_path => /  请求的是一个目录，想办法给目录中追加上一个 index.html文件（取一个默认文件）
if(file_path[strlen(file_path)-1]=='/'){//判断file_path最后一个字符是否是‘\’
strcat(file_path,"index.html");
}
//c) 例如 url_path => /image无法确定是文件还是目录，需要判定
if(IsDir(file_path)){
strcat(file_path,"/index.html");
}
return;
}
ssize_t GetFileSize(const char*file_path){
struct stat st;
int ret=stat(file_path,&st);
if(ret<0){
//打开文件失败，很可能文件不存在
//此时返回的文件长度为0
return 0;
}
return st.st_size;
}
int WriteStaticFile(int sock,const char*file_path){
//1 打开文件
//什么情况下会打开文件失败   a) 文件描述符不够用     b) 文件不存在
int fd=open(file_path,O_RDONLY);
if(fd<0){
perror("open");
return 404;
}
//2 把构造出的HTTP响应写入到socket之中
//a)写入首行
const char* first_line="HTTP/1.1 200 OK\n";
send(sock,first_line,strlen(first_line),0);
//b)写入header
//可根据扩展名来显示类型，但现在绝大多数浏览器都能自动匹配类型，根据扩展名自动匹配类型
const char* type_line=" Content-Type: text/html;charset=utf-8\n";//文本类型
//const char* type_line="\" Content-Type:\"\" image/jpg;charset=utf-8\"\n";//图片类型
send(sock,type_line,strlen(type_line),0);
//c)写入空行
const char* blank_line="\n";
send(sock,blank_line,strlen(blank_line),0);
//d)写入body(文件内容）
/*不够高效
//把文件中所有的文件一个字节一个字节的读取出来再一个字节一个字节写入sock
ssize_t file_size=GetFileSize(file_path);//获取到文件的总字节数
ssize_t i=0;
for(;i<file_size;i++){
	char c;
read(fd,&c,1);//系统调用不够高效，设计从内核向用户缓存拷贝数据
send(sock,&c,1,0);//涉及从用户缓存向网卡中拷贝数据
}
*/
sendfile(sock,fd,NULL,GetFileSize(file_path));//直接从内核到内核的拷贝
//避免了内核和用户之间得来回拷贝，从fd拷贝到网卡上，NULL表示从起始
//位置开始拷贝
//3 关闭文件
close(fd);
return 200;
}
int HandlerStaticFile(int sock,Request*req){//静态生成页面
	//1 根据 url_path 获取到文件在服务器上的真实路径
	char file_path[SIZE]={0};//用来保存文件的真实路径
	HandlerFilePath(req->url_path,file_path);//利用url来找到文件的真实路径
	//2 读取文件，把文件的内容直接写回到socket之中
	int err_code=WriteStaticFile(sock,file_path);
return err_code;
}
int HandlerCGIFather(int new_sock,int father_read,int father_write,int child_pid,Request*req){
//如果是post请求，就把body写入到管道
if(strcasecmp(req->method,"POST")==0){
int i=0;
char c='\0';
for(;i<req->content_length;i++){
read(new_sock,&c,1);
write(father_write,&c,1);
}
}
//2 构造HTTP响应
const char*first_line="HTTP/1.1 200 OK\n";
send(new_sock,first_line,strlen(first_line),0);
const char* type_line="\" Content-Type:\"\" text/html;charset=utf-8\"\n";
send(new_sock,type_line,strlen(type_line),0);
const char* blank_line="\n";                                                                                                
send(new_sock,blank_line,strlen(blank_line),0);
//循环从管道中读取数据，并写入到socket
char c='\0';
while(read(father_read,&c,1)>0){//读管道，读到EOF返回0，什么
	//时候读到EOF,写端全部关闭，再尝试继续读，会读到EOF，管道读端
	//关闭，再尝试写，会产生SIDPIPE信号，导致进程异常终止
send(new_sock,&c,1,0);
}
//4.回收子进程的资源
waitpid(child_pid,NULL,0);//回收对应的子进程
return 200;
}
int HandlerCGIChild(int child_read,int child_write,Request*req){
//1.设置环境变量
char method_env[SIZE]={0};
sprintf(method_env,"REQUEST_METHOD=%s",req->method);
putenv(method_env);
//还需要设置 QUERY_STRING 或者 CONTENT_LENGTH
if(strcasecmp(req->method,"GET")==0){
char query_string_env[SIZE]={0};
sprintf(query_string_env,"QUERY_STRING=%s",req->query_string);
putenv(query_string_env);
}else{
char content_length_env[SIZE]={0};
	sprintf(content_length_env,"CONTENT_LENGTH=%d",req->content_length);
putenv(content_length_env);
}
//2.把标准输入，标准输出重定向到管道中
dup2(child_read,0);
dup2(child_write,1);
//3.对子进程进行程序替换
// url_path: /cgi-bin/test
// file_path: ./wwwroot/cgi-bin/test
char file_path[SIZE]={0};
HandlerFilePath(req->url_path,file_path);
//l
//lp
//le
//v
//vp
//ve
execl(file_path,file_path,NULL);
return 200;
}

int HandlerCGI(int new_sock,Request*req){//动态生成页面
//1.创建一对匿名管道
int fd1[2],fd2[2];
int ret=pipe(fd1);
if(ret<0){
	return 404;
}
ret=pipe(fd2);
if(ret<0){
	//第二个管道创建失败，记得要关闭第一个管道
	//的读端和写端
	close(fd1[0]);
	close(fd2[1]);
	return 404;
}
// fd1 fd2 这样的变量名描述性太差，后边直接使用的话
// 是非常容易弄混淆的，所以直接在此处定义几个更加明确
// 的变量来描述该文件描述符的用途。
int father_read=fd1[0];
int child_write=fd1[1];
int father_write=fd2[1];
int child_read=fd2[0];
//2.创建子进程
ret=fork();
//3.父子进程各自执行不同的逻辑
if(ret>0){
//farther
//注意关掉父进程不用的文件描述符
//此处父进程优先关闭这俩个管道的文件描述符
//是为了后续父进程从子进程这里读数据的时候
//能够读到EOF,对于管道来说，所有的写端关闭
//，继续读，才有EOF,而此处所有的写端，一方面
//是父进程需要关闭，另一方面子进程也需要关闭
//所以此处父进程先关闭不必要的写端置之后，后
//续子进程用完了，直接关闭，父进程也就直接读到了
//EOF
close(child_read);
close(child_write);
int err_code=HandlerCGIFather(new_sock,father_read,father_write,ret,req);
}else if(ret==0){
//child
//注意关掉子进程不用的文件描述符
close(father_read);
close(father_write);
int err_code=HandlerCGIChild(child_read,child_write,req);
}else{
perror("fork");
close(fd1[0]);
close(fd1[1]);
close(fd2[0]);
close(fd2[1]);
return 404;
}
//4.收尾工作和错误处理
}

void HandlerRequest(int new_sock){
	int err_code=200;
	//1.读取并解析请求
	Request req;
	memset(&req,0,sizeof(req));
	//a)从socket中读取首行
	if(ReadLine(new_sock,req.first_line,sizeof(req.first_line))<=0){
		//todo失败处理
		err_code=404;
		goto END;
	}
	//b）从首行中解析出url和method
	if(ParseFirstLine(req.first_line,&req.url,&req.method)<0){
		//todo失败处理
		err_code=404;
		goto END;
	}
	//c)解析url,从url中解析出url_path,query_string
	if(ParseQueryString(req.url,&req.url_path,&req.query_string)<0){
		//todo失败处理
		err_code=404;
		goto END;
	}
//处理header,丢弃了大部分header,只处理content-length
if(ParseHeader(new_sock,&req.content_length)<0){
	//todo失败处理
	err_code=404;
	goto END;
}
    printf("method:  %s\n",req.method);
	printf("url_path: %s\n",req.url_path);
	printf("query_string: %s\n",req.query_string);
	printf("content_length: %d\n",req.content_length);
	//2.静态、动态生成页面，把生成页面写回客户端
	//假如浏览器发送的请求方法叫“get”/"GET"，不区分大小写的比较
	//如果请求是get请求并且没有query_string，那么就返回静态页面
	if(strcasecmp(req.method,"GET")==0
			&&req.query_string==NULL){
		err_code=HandlerStaticFile(new_sock,&req);
	}
	//如果是get请求，有query_string,那么就返回动态页面
else if(strcasecmp(req.method,"GET")==0
			&&req.query_string!=NULL){
		err_code=HandlerCGI(new_sock,&req);
	}
	//如果是post请求（一定是带参数的，参数是通过body来传给服务器的），那么也返回动态页面
else if(strcasecmp(req.method,"POST")==0){
err_code=HandlerCGI(new_sock,&req);
}else{//收到其他方法
	//todo错误处理
	err_code=404;
	goto END;
}
//错误处理：直接返回一个404的HTTP响应
END:
if(err_code!=200){
Handler404(new_sock);
}
close(new_sock);
return;
}

void * ThreadEntry(void * arg){
	int64_t new_sock=(int64_t)arg;
	//此处HandlerRequest作用是为了解耦合，一旦需要把服务器改成多进程或者IO多路复用
	//整体代码的改动都是比较小的
	HandlerRequest(new_sock);
		return NULL;
}
//服务器启动
void HttpServerStart(const char*ip,short port){
int listen_sock=socket(AF_INET,SOCK_STREAM,0);
if(listen_sock<0){
	perror("socket");
	return;
}
//设置，使得可重用Time-wait状态
int opt=1;
setsockopt(listen_sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
sockaddr_in addr;
addr.sin_family=AF_INET;
addr.sin_addr.s_addr=inet_addr(ip);//将点分十进制的ip地址转换成32位的
addr.sin_port=htons(port);//主机序的字节序转换为网络序的字节序
int ret=bind(listen_sock,(sockaddr*)&addr,sizeof(addr));
if(ret<0){
	perror("bind");
	return;
}
ret=listen(listen_sock,5);
if(ret<0){
	perror("listern");
	return;
}
printf("Server Init Ok\n");
while(1){
	sockaddr_in peer;//对端ip,端口号
	socklen_t len=sizeof(peer);
int64_t new_sock=accept(listen_sock,(sockaddr*)&peer,&len);
	if(new_sock<0){
		perror("accept");
		continue;
}
//使用多线程来实现Tcp服务器
pthread_t tid;
pthread_create(&tid,NULL,ThreadEntry,(void *)new_sock);
pthread_detach(tid);
}
}

//./server [ip] [port]
int main(int argc,char*argv[]){
	if(argc!=3){
		printf("Usage ./server [ip] [port]\n");
		return 1;
	}
	HttpServerStart(argv[1],atoi(argv[2]));
}

