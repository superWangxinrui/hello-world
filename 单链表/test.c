#define _CRT_SECURE_NO_WARNINGS
#include "标头.h"
int main(){
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	PNode pHead2;
	SListInit(&pHead2);
	SListPushBack(&pHead2, 1);
	PNode ret2 = SListFind(pHead2, 1);
	PNode ret=SListFind(pHead, 2);
	ret2->_pNext = ret;
	if(IsCrossWithoutCircle(pHead, pHead2)){
		printf("相交 ");
	}
	else {
		printf("不相交");
	}
	PNode crossnode = GetCrossNode(pHead, pHead2);
	printf("交点是%d", crossnode->_data);
	test();
	test2();
	test3();
	test4();
  	getchar();
	return 0;
}