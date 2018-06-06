#include<stdio.h>
#include<assert.h>
//此处实现的是静态顺序表，解决哈希冲突的方法为闭散列中的线性探测
#define Max_size 10
typedef int DataType;
typedef enum{EX,EM,DEL}state;//定义枚举类型，表示状态
typedef struct HTelem{//哈希表中存储的元素
	DataType data;
	state state;
}HTelem;
typedef struct HashTable{//哈希表
	HTelem array[Max_size];
	int size;//有效元素的个数EX
	int total;//EX+DEL的个数
}HashTable;

void InitHashTable(HashTable* Hash){//哈希表的初始化，将哈希表每个元素的状态置为EM
	assert(Hash);
	int i = 0;
	for (i = 0; i < Max_size; i++){
		(Hash->array[i]).state = EM;
	}
	Hash->size = 0;
	Hash->total = 0;
}
void InsertHashTable(HashTable*Hash, DataType data){//插入
	assert(Hash);
	if (Hash->total == Max_size){//哈希表已经插满的情况
		return;
	}
	//计算哈希地址
	int addr = data%Max_size;
	while (Hash->array[addr].state != EM){//找位置
		if (Hash->array[addr].state == EX){
			if (Hash->array[addr].data == data){//状态为EX并且值已存在的情况
				return;
			}
		}
		addr++;//状态为EX并且值不存在，或者状态为DEL，直接向后查找
		if (addr ==Max_size){//向后走一步越界，将地址置为0
			addr = 0;
		}
	}
	//找到位置，将值插入
	Hash->array[addr].data = data;
	Hash->array[addr].state = EX;
	(Hash->size)++;
	(Hash->total)++;
}
int FindHashTable(HashTable *Hash, DataType data){//查找data
	assert(Hash);
	int addr = data%Max_size;
	int start = addr;
	while (Hash->array[addr].state != EM){
		if (Hash->array[addr].state == EX){
			if (Hash->array[addr].data == data){
				printf("元素存在\n");
				return addr;
			}
		}
		addr = addr + 1;
		if (addr ==Max_size){
			addr =0;
		}
		if (addr == start){//找了一圈还没找到
			printf("元素不存在\n");
			return -1;
		}
	}
	printf("元素不存在\n");
	return -1;
}
void delectHashTable(HashTable*Hash, DataType data){//删除data,先找到data,再将状态置为DEL
	assert(Hash);
	int ret = FindHashTable(Hash, data);
	Hash->array[ret].state = DEL;
	(Hash->size)--;
}
int SizeHashTable(HashTable*Hash){//求哈希表的有效元素的个数
	return Hash->size;
}
int EmptyHashTable(HashTable*Hash){//判断哈希表是否为空
	return (Hash->size) == 0;
}