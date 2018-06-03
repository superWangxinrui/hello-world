#include<stdio.h>
#include<assert.h>
#include<malloc.h>
typedef  int DataType;
typedef int(*compare)(DataType, DataType);//函数指针（为了实现既可以创建大堆又可以创建小堆
typedef struct Heap{
	DataType * array;//动态数组
	int capacity;//容量
	int size;//实际大小
	compare com;
}Heap;
typedef struct prorityQueue{//优先级队列
	Heap hp;
}prorityQueue;
int less(DataType left, DataType right){
	return left > right;
}
int greater(DataType left, DataType right){
	return left < right;
}
void swap(DataType* pdata1, DataType* pdata2){//交换堆上两个节点的值
	assert(pdata1);
	assert(pdata2);
	DataType temp = *pdata1;
	*pdata1 = *pdata2;
	*pdata2 = temp;
}
void _AdjustDown(Heap*Hp, DataType root){//向下调整
	assert(Hp);
	DataType size = Hp->size;
	DataType parent = root;
	DataType child = (root * 2) + 1;//首先标记child为左孩子（child实际标记左右孩子中较小的）
	while (child<size){//孩子越界
		if (child + 1<size && Hp->com(Hp->array[child],Hp->array[child+1])){//右孩子存在，并且右孩子大于左孩子
			child = child + 1;
		}
		if (Hp->com((Hp->array[parent]) , (Hp->array[child]))){//双亲小于最大的孩子
			swap(&(Hp->array[parent]),&(Hp->array[child]));
			parent = child;//双亲走到孩子的位置
			child = (parent * 2) + 1;
		}
		else{//排好了（双亲比最大的孩子大）
			return;
		}
	}
}
void CreateHeap(Heap*Hp, DataType *array1, int size,compare com){//创建堆(注意：传过来com表示要创建大堆还是小堆
	assert(Hp);
	DataType root = (size - 2) >> 1;//从最后一个非叶子节点开始排
	int i = 0;
	Hp->array = (DataType*)malloc(sizeof(DataType)*size);
	if (Hp->array == NULL){
		return;
	}
	Hp->capacity = size;
	Hp->size = size;
	Hp->com = com;
	for (i = 0; i < size; i++){
		Hp->array[i] = array1[i];
	}
	//调整成堆（从最后一个非叶子开始排，排到根节点为止）
	for (i = root; i>=0; i--){
		_AdjustDown(Hp,i);
	}
}
//1 重新开两倍的空间 2 搬移元素 3 释放旧的空间 4 让指针指向新空间
void Check_capity(Heap *Hp){//检查容量
	if (Hp->capacity == Hp->size){
		int newcpacity = 2 * (Hp->capacity);
		DataType * temp = (DataType*)malloc(sizeof(DataType)*(Hp->capacity));
		if (NULL == temp){
			return;
		}
		for (int i = 0; i < Hp->size; i++){
			temp[i] = Hp->array[i];
		}
		free(Hp->array);
		Hp->array = temp;
		Hp->capacity = newcpacity;
	}
}
void _Adjustup(Heap* Hp, int child){//向上调整
	assert(Hp);
	DataType parent = (child - 1) >> 1;
	while (child){
		if (Hp->com((Hp->array[parent]), (Hp->array[child]))){
			swap(&Hp->array[parent], &Hp->array[child]);
			child = parent;
			parent = (parent - 1) >> 1;
		}
		else{
			return;
		}
	}
}
void InsertHeap(Heap* Hp, DataType data){//插入（思想，插到堆尾，向上调整）
	assert(Hp);
	Check_capity(Hp);//容量不够自动增容
	Hp->array[Hp->size++] = data;//插到堆尾
	//向上调整
	_Adjustup(Hp, Hp->size-1);
}
void delect(Heap *Hp){//注意：堆的删除每次必须删除堆顶元素
	assert(Hp);
	Hp->array[0] = Hp->array[Hp->size - 1];
	Hp->size = Hp->size - 1;
	_AdjustDown(Hp, 0);
}
int Heapsize(Heap*Hp){//求堆元素的个数
	return Hp->size;
}
void InitHeap(Heap *Hp,compare com){//堆初始化
	Hp->array = (DataType*)malloc(sizeof(DataType)*3);
	if (Hp->array == NULL){
		return;
	}
	Hp->capacity =3;
	Hp->size = 0;
	Hp->com = com;
}
int temptyHeap(Heap*Hp){
	if (Hp->size == 0){
		return 1;
	}
	else{
		return 0;
	}
}
//堆的应用
// 优先级队列
void InitprorityQueue(prorityQueue*pq){//初始化优先级队列
	InitHeap(&(pq->hp), greater);
}
void pushprorityQueue(prorityQueue *pq,DataType data){
	InsertHeap(&(pq->hp), data);
}
void popprorityQueue(prorityQueue *pq){
	delect(&(pq->hp));
}
int sizepQ(prorityQueue*pq){
	return  Heapsize(&(pq->hp));
}
int temppQ(prorityQueue*pq){
	temptyHeap(&(pq->hp));
}
int greatst(prorityQueue*pq){//取优先级最大的节点的值
	return (&(pq->hp))->array[0];
}
void test(){//优先级队列测试用例
	prorityQueue pq;
	InitprorityQueue(&pq);
	pushprorityQueue(&pq, 3);
	pushprorityQueue(&pq, 2);
	pushprorityQueue(&pq, 1);
	pushprorityQueue(&pq, 8);
	pushprorityQueue(&pq, 6);
	int ret = greatst(&pq);
	int ret2=sizepQ(&pq);
	printf("优先级队列的元素个数为%d\n",ret2);
	printf("优先级队列中优先级最高的是%d\n", ret);

}
void _AdjustDown2(Heap*Hp, DataType root,int size){//用于堆排序的向下调整
	assert(Hp);
	DataType parent = root;
	DataType child = (root * 2) + 1;//首先标记child为左孩子（child实际标记左右孩子中较小的）
	while (child<size){
		if (child + 1<size && Hp->com(Hp->array[child], Hp->array[child + 1])){//右孩子存在，并且右孩子大于左孩子
			child = child + 1;
		}
		if (Hp->com((Hp->array[parent]), (Hp->array[child]))){
			swap(&(Hp->array[parent]), &(Hp->array[child]));
			parent = child;
			child = (parent * 2) + 1;
		}
		else{//排好了
			return;
		}
	}
}
void sortHeap(Heap *Hp,int* arr,int sz){//堆排序(升序）
	assert(Hp);
	int i = 0;
	CreateHeap(Hp, arr, sz, greater);//创建一个大堆
	int end = sz - 1;
	while (end){
		swap(&(Hp->array[0]), &(Hp->array[end]));//堆顶与最后一个元素进行交换
		_AdjustDown2(Hp, 0,end);//剩下的元素重新调整成堆
		end--;
	}
}
void test1(){//堆排序测试用例
	Heap Hp;
	int arr[10] = { 3, 9, 4, 1, 2, 8, 6, 7, 5, 0 };
	sortHeap(&Hp, arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i <sizeof(arr) / sizeof(arr[0]); i++){
		printf("%d ", (&Hp)->array[i]);
	}
}