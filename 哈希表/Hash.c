#define _CRT_SECURE_NO_WARNINGS 
#include "Hash.h"
int main(){
	HashTable Hash;
	InitHashTable(&Hash);
	InsertHashTable(&Hash, 23);
	InsertHashTable(&Hash, 14);
	InsertHashTable(&Hash, 74);
	InsertHashTable(&Hash, 33);
	InsertHashTable(&Hash, 19);
	InsertHashTable(&Hash, 29);
	FindHashTable(&Hash, 33);
	delectHashTable(&Hash, 33);
	FindHashTable(&Hash, 33);
	system("pause");
	return 0;                                            
}