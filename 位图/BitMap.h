#include<stdio.h>
#include<malloc.h>
#include<assert.h>
typedef struct bit_map{
	int * bitmap;
	int capacity;
	int size;//有效比特位的个数
}bit_map;
void Initbit_map(bit_map *bit_map, int bit){//位图初始化，以int为单位开辟空间
	bit_map->capacity = (bit >> 5) + 1;//计算bit个比特位需要开辟多少个int
	bit_map->size = bit;
	bit_map->bitmap =(int *) malloc(sizeof(int)*bit_map->capacity);
	if (bit_map->bitmap == NULL){
		perror(0);
		return;
	}
	for (int i = 0; i < bit_map->capacity; i++){
		bit_map->bitmap[i] = 0;
	}
}
void setone(bit_map* bit_map, int whitch){//某位置1
	assert(bit_map);
	int addr1 = whitch >> 5;
	int addr2 = whitch % 32;
	if (whitch > bit_map->size){//要置1的位置超过最大有效位数
		return;
	}
	bit_map->bitmap[addr1]=(bit_map->bitmap[addr1]) | (1 << addr2);
}
void setozero(bit_map* bit_map, int whitch){//某位置0
	assert(bit_map);
	int addr1 = whitch >> 5;
	int addr2 = whitch % 32;
	if (whitch > bit_map->size){//要置0的位置超过最大有效位数
		return;
	}
	bit_map->bitmap[addr1] = (bit_map->bitmap[addr1])&(~(1 << addr2));
}
int check(bit_map* bit_map, int whitch){//看某位置放的是0还是1
	assert(bit_map);
	int addr1 = whitch >> 5;
	int addr2 = whitch % 32;
	if (whitch > bit_map->size){
		return -1;
	}
	return (bit_map->bitmap[addr1])>>addr1&1;
}
int countsize(bit_map*bit_map){//位集合中总共有多少个有效比特位
	assert(bit_map);
	return bit_map->size;
}
int countonesize(bit_map *bit_map){//位集合中总共有多少个比特位是1
	assert(bit_map);
	const char*bitcount = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4";//一个字节中比特位是1的个数
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < bit_map->capacity; i++){
		int value = bit_map->bitmap[i];
		for (j = 0; j < sizeof(bit_map->bitmap[i]);j++){//一次处理一个字节
			char c = value;
			count += bitcount[c&0x0f];
			c = c >> 4;
			count = count + bitcount[c & 0x0f];
			value = value >> 8;//取下一个字节
		}
	}
	return count;
}
void destorynit_map(bit_map*bit_map){
	assert(bit_map);
	free(bit_map->bitmap);
	bit_map->capacity = 0;
	bit_map->size = 0;
}