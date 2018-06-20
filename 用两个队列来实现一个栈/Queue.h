#include<malloc.h>
#include<stdio.h>
#include<Windows.h>
#define NULL 0
typedef int DataType;
typedef struct Node
{
	DataType _data;
	struct Node* _pNext;
}Node, *PNode;

typedef struct Queue 
{
	PNode _pHead;
	PNode _pTail;
}Queue;

// 队列的初始化
void QueueInit(Queue* q){
	q->_pHead = q->_pTail=NULL;
}
PNode buynode(DataType data){
	PNode temp;
	temp = (PNode)malloc(sizeof(Node));
	if (NULL == temp){
		return;
	}
	temp->_data = data;
	return temp;
}
// 入队列
void QueuePush(Queue* q, DataType data){
	if (q->_pHead == NULL){
		q->_pHead = buynode(data);
		q->_pTail = q->_pHead;
		q->_pHead->_pNext = NULL;
	}
	else{
		PNode temp;
		temp = q->_pHead;
		while (temp != q->_pTail){
			temp = temp->_pNext;
		}
		q->_pTail = buynode(data);
		temp->_pNext = q->_pTail;
		q->_pTail->_pNext = NULL;
	}
}

// 出队列
void QueuePop(Queue* q){
	if (NULL == q)
	{
		return;
	}
	q->_pHead = q->_pHead->_pNext;
}

// 取队头元素
DataType QueueFront(Queue* q){
	if (NULL == q)
	{
		return NULL;
	}
	return q->_pHead->_data;
}

// 取队尾元素
DataType QueueBack(Queue* q){
	if (NULL == q){
		return NULL;
	}
	return q->_pTail->_data;
}

// 获取队列中元素的个数
int QueueSize(Queue* q){
	if (NULL == q){
		return 0;
	}
	int count = 1;
	PNode temp ;
	temp = q->_pHead;
	while (temp!=q->_pTail){
		count++;
		temp = temp->_pNext;
	}
	return count;
}

// 检测队列是否为空
int QueueEmpty(Queue* q){//空返回1，不空返回0.
	if (q->_pHead ==NULL){
		return 1;
	}
	return 0;
}