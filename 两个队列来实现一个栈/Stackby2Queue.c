#define _CRT_SECURE_NO_WARNINGS 
#include "Queue.h"
typedef struct StackBy2Queue{
	Queue q1;
	Queue q2;
}StackBy2Queue;
int StackByQueueEmpty(StackBy2Queue*s){
	return QueueEmpty(&(s->q2)) && QueueEmpty(&(s->q1));
}
void StackByQueueInit(StackBy2Queue*s){
	QueueInit(&(s->q1));
	QueueInit(&(s->q2));
}
void StackByQueuePush(StackBy2Queue*s, int data){//直接往q1里边入
	QueuePush(&(s->q1), data);
}
void StackByQueuePop(StackBy2Queue*s){//出栈
	if (StackByQueueEmpty(s)){
		return;
	}
	if (!QueueEmpty(&(s->q1))){
		while (QueueSize(&(s->q1)) > 1){
			int ret = QueueFront(&(s->q1));
			QueuePop(&(s->q1));
			QueuePush((&(s->q2)), ret);
		}
		QueuePop(&(s->q1));
	}
	else{//如果q1为空的情况
		int ret = QueueFront(&(s->q2));
		QueuePop(&(s->q2));
		QueuePush((&(s->q1)), ret);
		QueuePop(&(s->q2));
	}
	
}
int StackByQueueTop(StackBy2Queue*s){
	if (!QueueEmpty(&(s->q1))){
		return QueueBack(&(s->q1));
	}
	else{
		return QueueBack(&(s->q2));
	}
}
void StackByQueuesize(StackBy2Queue*s){
	return  QueueSize(&(s->q1)) + QueueSize(&(s->q2));
}
void test(){
	StackBy2Queue s;
	StackByQueueInit(&s);
	StackByQueuePush(&s, 1);
	StackByQueuePush(&s, 2);
	StackByQueuePush(&s, 3);
	int ret = StackByQueueTop(&s);
	printf("%d ", ret);
	StackByQueuePop(&s);
	ret = StackByQueueTop(&s);
	printf("%d ", ret);
}