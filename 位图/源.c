#define _CRT_SECURE_NO_WARNINGS 
#include "BitMap.h"
int main(){
	bit_map bit_map;
	Initbit_map(&bit_map, 24);
	int i = 0;
	int array[] = { 1, 3, 7, 4, 12, 16, 19, 13, 22, 18 };
	int sz = sizeof(array) / sizeof(array[0]);
	for (i = 0; i < sz; i++){
		setone(&bit_map,array[i]);
	}
	int ret = countonesize(&bit_map);
	printf("%d\n", ret);
	system("pause");
	return 0;
}