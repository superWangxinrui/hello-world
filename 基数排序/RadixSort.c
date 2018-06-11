//#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<malloc.h>
#include<string.h>
int getbitcount(int *array, int size){//统计数组中最大位数(避过除法）
	int i = 0;
	int count = 1;
	int radix = 10;
	for (i = 0; i < size; i++){
		while (array[i] >= radix){
			++count;
			radix *= 10;
		}
	}
	return count;
}
void RadixSort(int *array, int size){
	int bitIdex = 0;//表示位数
	int radix = 1;
	for (; bitIdex < getbitcount(array,size); bitIdex++){
		int count[10] = { 0 };
		int i = 0;
		int *temp;
		temp = (int *)malloc(sizeof(array) / sizeof(array[0]));
		for (i = 0; i < size; i++){//统计每个桶中元素的个数
			count[array[i]/radix % 10]++;
		}
		//计算每个桶的起始位置
		int startaddr[10] = { 0 };
		for (i = 1; i < 10; i++){
			startaddr[i] = startaddr[i - 1] + count[i - 1];
		}
		//放元素
		for (i = 0; i < size; i++){
			int bucketNo = array[i]/radix%10;
			temp[startaddr[bucketNo]++] = array[i];
		}
		memcpy(array, temp, sizeof(array[0])*size);
		radix *= 10;
	}
	}
int main(){
	int array[] = { 73, 22, 93, 43, 55, 14, 28, 65, 39, 81 };
	int size = sizeof(array) / sizeof(array[0]);
	RadixSort(array,size);
	int i = 0;
	for (i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	getchar();
	return 0;
}