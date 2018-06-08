#include<assert.h>
#include<stdio.h>
#include<malloc.h>
typedef int DataType;

typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node, *PNode;
typedef  struct CListNode{
	struct CListNode*_pNext;
	struct CListNode*_random;
	DataType _data;
}CListNode,*PCListNode;

//////////////////不带头结点的单链表////////////////////////////////////// 
// .h 
//打印单链表
void printSList(PNode pHead);

// 链表初始化 
void SListInit(PNode* ppHead);

//新节点的申请
PNode NewNode(DataType data);


// 尾插 
void SListPushBack(PNode* ppHead, DataType data);

// 尾删 
void SListPopBack(PNode* ppHead);

// 头插 
void SListPushFront(PNode* ppHead, DataType data);

// 头删 
void SListPopFront(PNode* ppHead);

// 查找值为data的结点，返回该结点在链表中的位置 
PNode SListFind(PNode pHead, DataType data);

// 在链表pos位置后插入结点data 
void SListInsert(PNode* ppHead, PNode pos, DataType data);

// 删除链表pos位置上的结点 
void SListErase(PNode* ppHead, PNode pos);

// 销毁单链表 
void SListDestroy(PNode* ppHead);

// 求链表中结点的个数 
int SListSize(PNode pHead);

// 将链表中的结点清空 
void SListClear(PNode* ppHead);

// 获取结点 
PNode BuySListNode(DataType data);

// 获取链表中的最后一个结点，返回该结点的地址 
PNode SListBack(PNode pHead);


////////链表部分的面试题认真去完成，非常重要，非常重要，非常重要！！！//////////

// 从尾到头打印单链表 
void PrintListFromTail2Head(PNode pHead);
void THprint2(PNode pHead);

// 删除无头单链表的非尾结点，要求：不能遍历链表 
void DeleteNotTailNode(PNode pos);

// 在无头单链表pos位置前插入值为结点data的结点 （不能遍历单链表）
void InsertPosFront(PNode pos, DataType data);

//1.构环
void circle(PNode pHead);

// 用单链表模拟实现约瑟夫环 
void JosephCircle(PNode* pHead, const int M);

// 使用冒泡排序方法对单链表进行排序 
void BubbleSort(PNode pHead);

// 单链表的逆置--三个指针 
void ReverseSList(PNode* pHead);

// 单链表的逆置--头插法 
PNode ReverseSListOP(PNode pHead);

// 合并两个有序链表，合并之后依然有序 
PNode MergeSList(PNode pHead1, PNode pHead2);

// 查找链表的中间结点，要求只能遍历一次链表 
PNode FindMiddleNode(PNode pHead);

// 查找链表的倒数第K个结点，要求只能遍历链表一次 
PNode FindLastKNode(PNode pHead, int K);

// 删除链表的倒数第K个结点，要求只能遍历链表一次 
void DeleteLastKNode(PNode* pHead, int K);

// 判断单链表是否相交？链表不带环 
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2);

// 求不带环单链表相交交点 
PNode GetCrossNode(PNode pHead1, PNode pHead2);

// 判断链表是否带环 
PNode IsCircle(PNode pHead);

void test();//测试
void test2();
void test3();
// 求环的长度 
int GetCircleLen(PNode pHead);

// 求环的入口点--注意推断过程 
PNode GetEnterNode(PNode pHead, PNode pMeetNode);

// 判断链表是否相交，链表可能带环 
int IsListCrossWithCircle(PNode pHead1, PNode pHead2);

// 复杂链表的复制 
PCListNode CopyComplexList(PCListNode pHead);
//总结链表和顺序表的优缺点