#pragma once

#define SIZE 10240

typedef struct Request{
	char first_line[SIZE];
	char *method;
	char* url;
	char* url_path;//重点关注的内容1
	char *query_string;//重点关注的内容2（参数）
	// char* version;
	// 接下来是 header部分，如果要完整的解析下来，
	// 此处需要使用二叉搜索树或者Hash表
	// 这里我们偷个懒，其它header都不要了，只保留一个
	// content-length
	int content_length;
}Request;
