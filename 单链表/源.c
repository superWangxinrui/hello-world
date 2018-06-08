#define _CRT_SECURE_NO_WARNINGS 
#include "标头.h";
void SListInit(PNode* ppHead){// 链表初始化
	assert(ppHead);
	*ppHead = NULL;
}
//新节点的申请
PNode NewNode(DataType data){
	PNode PNewnode = (PNode)malloc(sizeof(Node));
	if (NULL == PNewnode){
		return NULL;
	}
	PNewnode->_pNext = NULL;
	PNewnode->_data = data;
	return PNewnode;
}
// 尾插 
void SListPushBack(PNode* ppHead, DataType data){
	assert(ppHead);
	PNode pnewnode = NULL;
	pnewnode = NewNode(data);
	if (NULL == pnewnode){
		return NULL;
	}
	if (NULL == *ppHead){
		*ppHead = pnewnode;
	}
	else{
		PNode pcurnode = *ppHead;
		while (pcurnode->_pNext != NULL){
			pcurnode = pcurnode->_pNext;
		}
		pcurnode->_pNext = pnewnode;
	}
}
// 尾删 
void SListPopBack(PNode* ppHead){
	assert(ppHead);
	if (NULL == *ppHead){
		return NULL;
	}
	else if ((*ppHead)->_pNext == NULL)
	{
		free(*ppHead);
		*ppHead = NULL;
	}
	else{
		PNode pcurnode = *ppHead;
		while (NULL != pcurnode->_pNext->_pNext){
			pcurnode = pcurnode->_pNext;
		}
		free(pcurnode->_pNext);
		pcurnode = NULL;
	}
}
// 头插 
void SListPushFront(PNode* ppHead, DataType data){
	assert(ppHead);
	PNode pnewnode = NULL;
	pnewnode = NewNode(data);
	if (NULL == pnewnode){
		return NULL;
	}
	pnewnode->_pNext = *ppHead;
	*ppHead = pnewnode;
}
// 头删 
void SListPopFront(PNode* ppHead){
	assert(ppHead);
	if (NULL == *ppHead){
		return NULL;
	}
	else{
		DataType deldata = *ppHead;
		*ppHead = (*ppHead)->_pNext;
		free(deldata);
	}

}
// 查找值为data的结点，返回该结点在链表中的位置 
PNode SListFind(PNode pHead, DataType data){
	if (NULL == pHead){
		return NULL;
	}
	PNode pcurnode = pHead;
	while (pcurnode!=NULL)
	{
		if (pcurnode->_data == data)
		{
			return pcurnode;
		}
		pcurnode = pcurnode->_pNext;
	}
	return NULL;
}
// 在链表pos位置后插入结点data 
void SListInsert(PNode* ppHead, PNode pos, DataType data){
	assert(ppHead);
	if (*ppHead == NULL || pos == NULL)
	{
		return;
	}
	PNode pnewnode = NULL;
	pnewnode = NewNode(data);
	if (NULL == pnewnode){
		return NULL;
	}
	pnewnode->_pNext = pos->_pNext;
	pos->_pNext = pnewnode;

}
// 删除链表pos位置上的结点 
void SListErase(PNode* ppHead, PNode pos){
	assert(ppHead);
	if (*ppHead == NULL || pos == NULL)
	{
		return;
	}
	if (pos == *ppHead){
		SListPopFront(ppHead);
	}
	else{
		PNode pcurnode = *ppHead;
		while (pcurnode->_pNext != pos){
			pcurnode = pcurnode->_pNext;
		}
		pcurnode->_pNext = pos->_pNext;
		free(pos);
	}
}
// 销毁单链表 
void SListDestroy(PNode* ppHead){
	PNode pdelnode = NULL;
	assert(ppHead);
	while (*ppHead){
		pdelnode = *ppHead;
		*ppHead = (*ppHead)->_pNext;
		free(pdelnode);
		
	}
}
// 求链表中结点的个数 
int SListSize(PNode pHead){
	PNode pcurnode = pHead;
	int count = 0;
	while(pcurnode){
		count++;
		pcurnode = pcurnode->_pNext;
	}
	return count;
}
// 将链表中的结点清空 
void SListClear(PNode* ppHead){
	SListDestroy(ppHead);
}
//从尾到头打印单链表
void THprint(PNode pHead){
	if (NULL == pHead){
		return;
	}
	THprint(pHead->_pNext);
	printf("%d->",pHead->_data);
}
//从尾到头打印单链表
void THprint2(PNode pHead){
	if (NULL == pHead){
		return;
	}
	PNode pcur = NULL;
	PNode pprint = NULL;
	while (pprint != pHead){
		pcur = pHead;
		while (pcur->_pNext != pprint){
			pcur = pcur->_pNext;
		}
		printf("%d", pcur->_data);
		pprint = pcur;
	}
}
//删除一个无头单链表的非尾节点（不能遍历链表）
void delnotTail(PNode pose){
	if (NULL == pose || pose->_pNext == NULL){
		return 0;
	}
	PNode pdelnode = pose->_pNext;
	pose->_data = pdelnode->_data;
	pose->_pNext = pdelnode->_pNext;
	free(pdelnode);
}
//在无头单链表的一个节点前插入一个节点（不能遍历链表）
void InsertposFront(PNode pose, DataType data){
	if (NULL == pose){
		return;
	}
	PNode pnewnode = NULL;
	pnewnode = NewNode(pose->_data);
	if (NULL == pnewnode){
		return NULL;
	}
	pnewnode->_pNext = pose->_pNext;
	pose->_pNext = pnewnode;
	pose->_data = data;

}
//找到链表中最后一个节点，并返回位置
PNode Slistback(PNode pHead){
	if (NULL == pHead){
		return NULL;
	}
	PNode pcurnode = pHead;
	while (pcurnode->_pNext != NULL){
		pcurnode = pcurnode->_pNext;
	}
	return pcurnode;
}

//1.构环
void circle(PNode pHead){
	PNode backnode = Slistback(pHead);
	backnode->_pNext = pHead;
}

//单链表实现约瑟夫环
void Josephcricle(PNode* ppHead, int M){
	assert(ppHead);
	if (NULL== *ppHead){
		return;
	}
	circle(*ppHead);
	PNode pcurnode = *ppHead;
	while (pcurnode->_pNext != pcurnode){
		int count = M;
		while (--count){
			pcurnode = pcurnode->_pNext;
		}
		PNode pdelnode = pcurnode->_pNext;
		pcurnode->_data = pdelnode->_data;
		pcurnode->_pNext = pdelnode->_pNext;
		free(pdelnode);
	}
	pcurnode->_pNext = NULL;//解环
	*ppHead = pcurnode;
}

// 使用冒泡排序方法对单链表进行排序 
void BubbleSort(PNode pHead){
	if (NULL == pHead || NULL == pHead->_pNext){
		return;
	}
	PNode pprecur = NULL;
	PNode PTail = NULL;
	PNode pcur = NULL;
	while (pHead!=PTail){
		pprecur = pHead;
		pcur = pprecur->_pNext;
		while (pcur!=PTail){
			if (pprecur->_data > pcur->_data){
				int tempPdata = pprecur->_data;
				pprecur->_data = pcur->_data;
				pcur->_data = tempPdata;
			}
			pprecur = pprecur->_pNext;
			pcur = pcur->_pNext;
		}
		PTail = pprecur;
	}
}
void printSList(PNode pHead){
	if (NULL == pHead){
		return;
	}
	PNode pcurnode = pHead;
	while (pcurnode){
		printf("%d->", pcurnode->_data);
		pcurnode = pcurnode->_pNext;
	}
	printf("NULL");
}
// 单链表的逆置--三个指针 
void ReverseSList(PNode* pHead){
	assert(pHead);
	if (NULL == *pHead || NULL == ((*pHead)->_pNext)){
		return;
	}
	PNode pprenode = NULL;
	PNode pnextnode = NULL;
	PNode pcurnode = *pHead;
	while (pcurnode){
		pnextnode = pcurnode->_pNext;
		pcurnode->_pNext = pprenode;
		pprenode = pcurnode;
		pcurnode = pnextnode;
	}
	*pHead = pprenode;//将链表的头改变
}
// 单链表的逆置--头插法 (返回pNewhead)
PNode ReverseSListOP(PNode pHead){
	if (NULL == pHead || NULL == ((pHead)->_pNext)){
		return;
	}
	PNode pNewHead = NULL;
	PNode pnextnode = NULL;
	PNode pcurnode = pHead;
	while(pcurnode){
		pnextnode = pcurnode->_pNext;
		pcurnode->_pNext =pNewHead ;
		pNewHead = pcurnode;
		pcurnode = pnextnode;
	}
	return pNewHead;
}
//合并两个有序单链表，合并之后依然有序
PNode MergeSList(PNode pHead1, PNode pHead2){
	if (NULL == pHead1){
		return pHead2;
	}
	if (NULL == pHead2){
		return pHead1;
	}
	PNode pcur1 = pHead1;
	PNode pcur2 = pHead2;
	PNode pnewhead = NULL;
	if (pcur1->_data < pcur2->_data){
		pnewhead = pcur1;
		pcur1 = pcur1->_pNext;
	}
	else {
		pnewhead = pcur2;
		pcur2 = pcur2->_pNext;
	}
	PNode pTailnode = pnewhead;
	while (pcur1&&pcur2){
		if (pcur1->_data < pcur2->_data){
			pTailnode->_pNext = pcur1;
			pcur1 = pcur1->_pNext;
		}
		else {
			pTailnode->_pNext= pcur2;
			pcur2 = pcur2->_pNext;
		}
		pTailnode = pTailnode->_pNext;
	}
	if (pcur1){
		pTailnode->_pNext = pcur1;
	}
	else
	{
		pTailnode->_pNext = pcur2;
	}
	return pnewhead;
}
// 查找链表的中间结点，要求只能遍历一次链表 
PNode FindMiddleNode(PNode pHead){
	if (NULL == pHead){
		return NULL;
	}
	PNode pFast = pHead;
	PNode pLow = pHead;
	while (pFast&&pFast->_pNext){
		pFast = pFast->_pNext->_pNext;
		pLow = pLow->_pNext;
	}
	return pLow;
}
// 查找链表的倒数第K个结点，要求只能遍历链表一次 
PNode FindLastKNode(PNode pHead, int K){
	if ((NULL == pHead) || (K < 0)){
		return NULL;
	}
	PNode pFast = pHead;
	PNode pLow = pHead;
		while (K--){//让pFast先走k步
			pFast = pFast->_pNext;
		}
		while (pFast){
			pFast = pFast->_pNext;
			pLow = pLow->_pNext;
		} 
	return pLow;
}
// 删除链表的倒数第K个结点，要求只能遍历链表一次 
void DeleteLastKNode(PNode* pHead, int K){
	PNode retnode=FindLastKNode(pHead, K);
	if (retnode ==*pHead){//如果要删的节点是头节点
		PNode pdelnode = retnode;
		*pHead = retnode->_pNext;
		free(pdelnode);
	}
	else{
		PNode prenode = NULL;
		PNode pcurnode = *pHead;
		while (pcurnode->_pNext != retnode){
			pcurnode = pcurnode->_pNext;
		}
		prenode = pcurnode;
		PNode pdelnode = retnode;
		prenode->_pNext = retnode->_pNext;
		free(pdelnode);
	}
}
// 判断单链表是否相交？链表不带环 
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2){//相交返回1，不相交返回0
	if ((NULL == pHead1) || (NULL == pHead2)){
		return 0;
	}
	PNode pcur1 = pHead1;
	PNode pcur2 = pHead2;
	while (pcur1->_pNext != NULL){
		pcur1 = pcur1->_pNext;
	}
	while (pcur2->_pNext!=NULL){
		pcur2 = pcur2->_pNext;
	}
	return pcur1 == pcur2;
}
// 求不带环单链表相交交点 
PNode GetCrossNode(PNode pHead1, PNode pHead2){
	int size1 = 0;
	int size2 = 0;
	PNode pcur1 = pHead1;
	PNode pcur2 = pHead2;
	if (IsCrossWithoutCircle(pHead1, pHead2)){
		while (pcur1){
			size1++;
			pcur1 = pcur1->_pNext;
		}
		while (pcur2){
			size2++;
			pcur2 = pcur2->_pNext;
		}
		int gap = size1 - size2;
		pcur1 = pHead1;
		pcur2 = pHead2;
		if (gap > 0){
			while (gap--){
				pcur1 = pcur1->_pNext;
			}
		}
		if (gap < 0){
			while (gap++){
				pcur2 = pcur2->_pNext;
			}
		}
		while (pcur1 != pcur2){
			pcur1 = pcur1->_pNext;
			pcur2 = pcur2->_pNext;
		}
		return pcur1;
	}
	else {
		return NULL;
	}
}
// 判断链表是否带环 //快慢指针，返回相遇点
PNode IsCircle(PNode pHead){
	if (NULL == pHead){
		return NULL;
	}
	PNode pfast = pHead;
	PNode pslow = pHead;
	while ((pfast != NULL) && (pfast->_pNext) != NULL){
		pfast = pfast->_pNext->_pNext;
		pslow = pslow->_pNext;
		if (pfast == pslow){
			return pfast;
		}
	}
		return NULL;
}
void test(){//测试链表是否带环，环的长度以及入口点
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	PNode ret = SListFind(pHead, 6);
	ret->_pNext = pHead;
	if (NULL!=IsCircle(pHead)){
		printf("链表带环\n");
	}
	else{
		printf("链表不带环\n");
	}
	int ret1 = GetCircleLen(pHead);
	printf("环的长度为：%d\n", ret1);
	 PNode retnode= GetEnterNode(pHead, IsCircle(pHead));
	 printf("环的入口点是：%d\n", retnode->_data);
}
// 求环的长度 
int GetCircleLen(PNode pHead){
	 PNode pMeetnode=IsCircle(pHead);
	 PNode pcur = pMeetnode;
	 int count = 1;
	 if (pMeetnode != NULL){
		 while (pcur->_pNext != pMeetnode){
			 pcur = pcur->_pNext;
			 count++;
		 }
		 return count;
	 }
	 else{
		 return 0;
	 }
}
// 求环的入口点--注意推断过程 
PNode GetEnterNode(PNode pHead, PNode pMeetNode){
	if ((NULL == pHead) || (NULL == pMeetNode)){
		return NULL;
	}
	PNode p1 = pHead;
	PNode p2 = pMeetNode;
	while (p1 != p2){
		p1 = p1->_pNext;
		p2 = p2->_pNext;
	}
	return p1;
}
// 判断链表是否相交，链表可能带环 
int IsListCrossWithCircle(PNode pHead1, PNode pHead2){//两个链表都不带环相交返回1
	//两个链表都带环相交返回2
	if ((NULL == pHead1) || (NULL == pHead2)){
		return;
	}
	PNode pmeetnodde1 = IsCircle(pHead1);
	PNode pmeetnodde2 = IsCircle(pHead2);
	if ((NULL == pmeetnodde1) && (NULL == pmeetnodde2)){//两个链表都不带环
		int ret = IsCrossWithoutCircle(pHead1, pHead2);
		return ret;
	}
	if (pmeetnodde1&&pmeetnodde2){//两个链表都带环
		PNode pcur1 = pmeetnodde1;
		do{
			if (pcur1 == pmeetnodde2){
				return 2;
			}
			pcur1 = pcur1->_pNext;
		} while (pcur1 != pmeetnodde1);
	}
	return 0;
}
void test2(){//测试链表是否相交，链表可能带环(不带环）
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
	PNode ret = SListFind(pHead, 2);
	ret2->_pNext = ret;
	if (1==IsListCrossWithCircle(pHead,pHead2)){
		printf("不带环相交 ");
	}
	else if (2 == IsListCrossWithCircle(pHead, pHead2)){
		printf("带环相交");
	}
	else{
		printf("不相交");
	}
}
void test3(){//测试链表是否相交，链表可能带环(带环）
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	PNode ret = SListFind(pHead, 6);
	ret->_pNext = pHead;
	PNode pHead2;
	SListInit(&pHead2);
	SListPushBack(&pHead2, 1);
	PNode ret1 = SListFind(pHead2, 1);
	ret1->_pNext = pHead->_pNext;
	if (1 == IsListCrossWithCircle(pHead, pHead2)){
		printf("不带环相交 ");
	}
	else if (2 == IsListCrossWithCircle(pHead, pHead2)){
		printf("带环相交");
	}
	else{
		printf("不相交");
	}
}
PCListNode CopyComplexList(PCListNode pHead){
	if (NULL == pHead){
		return NULL;
	}
	PCListNode pOldnode = pHead;
	PCListNode pNewnode = NULL;
	PCListNode pNewHead = NULL;
	while (pOldnode){//在原链表的每个节点后插入值相同的新节点
		pNewnode = (CListNode*)malloc(sizeof(CListNode));
		pNewnode->_data = pOldnode->_data;
		pNewnode->_pNext = NULL;
		pNewnode->_random = NULL;
		pNewnode->_pNext = pOldnode->_pNext;
		pOldnode->_pNext = pNewnode;
		pOldnode = pNewnode->_pNext;
	}
	pOldnode = pHead;
	while (pOldnode){//给新节点的随机指针域赋值
		pNewnode = pOldnode->_pNext;
		if (NULL == pOldnode->_random){
			pNewnode->_random = NULL;
		}
		else{
			pNewnode->_random = pOldnode->_random->_pNext;
		}

		pOldnode = pNewnode->_pNext;
	}
	pOldnode = pHead;
	pNewHead = pOldnode->_pNext;
	while (pOldnode->_pNext != NULL){//将插入的新节点从链表中拆下来
		pNewnode = pOldnode->_pNext;
		pOldnode->_pNext = pNewnode->_pNext;
		pOldnode = pNewnode;
	}
	return pNewHead;
}
//新节点的申请
PCListNode CNewNode(DataType data){
	PCListNode PNewnode = (PCListNode)malloc(sizeof(Node));
	if (NULL == PNewnode){
		return NULL;
	}
	PNewnode->_pNext = NULL;
	PNewnode->_data = data;
	return PNewnode;
}
// 尾插 
void CSListPushBack(PCListNode* ppHead, DataType data){
	assert(ppHead);
	PCListNode pnewnode = NULL;
	pnewnode = CNewNode(data);
	if (NULL == pnewnode){
		return NULL;
	}
	if (NULL == *ppHead){
		*ppHead = pnewnode;
	}
	else{
		PCListNode pcurnode = *ppHead;
		while (pcurnode->_pNext != NULL){
			pcurnode = pcurnode->_pNext;
		}
		pcurnode->_pNext = pnewnode;
	}
}
void test4(){
	PCListNode pHead=NULL;
	CSListPushBack(&pHead, 1);
	CSListPushBack(&pHead, 2);
	CSListPushBack(&pHead, 3);
	pHead->_random = pHead->_pNext;
	pHead->_pNext->_random = pHead->_pNext->_pNext;
	pHead->_pNext->_pNext->_random = NULL;
	PCListNode retnode = CopyComplexList(pHead);
	/*while (retnode!=NULL)
	{
		printf("%d->", retnode->_data);
		retnode = retnode->_pNext;
	}
	retnode = CopyComplexList(pHead);*/
	while (retnode != NULL) 
	{
		if (retnode->_random == NULL){
			printf("NULL");
		}
		else{
			printf("%d->", retnode->_random->_data);
		}
			retnode = retnode->_pNext;
		
	}
}
	