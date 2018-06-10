#include<stdio.h>
#include<malloc.h>
//#include<cstring>
void combine(int *array, int left, int mid,int right, int *temp){
	int r1 = left;
	int r2 = mid;
	int r3 = left;
	while (r1 < mid && r2<right){
		if (array[r1] <= array[r2]){
			temp[r3] = array[r1];
			r3++;
			r1++;
		}
		 else if (array[r1]>array[r2]){
			temp[r3] = array[r2];
			r3++;
			r2++;
		}
	}
	while(r1<mid){
		temp[r3] = array[r1];
		r3++;
		r1++;
	}
	while (r2<right){
		temp[r3] = array[r2];
		r3++;
		r2++;
	}
	memcpy(array+left, temp+left, sizeof(int)*(right - left));
}
void _mergersort(int *array,int left,int right,int *temp){
	if (right - left > 1){
		int mid = left + ((right - left) >> 1);
		_mergersort(array, left, mid, temp);
		_mergersort(array, mid, right, temp);
		combine(array, left, mid, right, temp);
	}
}
void mergersort(int *array, int left,int right,int sz){
	int *temp;
	temp = (int *)malloc(sizeof(int)*sz);
	if (temp == NULL){
		perror(0);
		return;
	}
	_mergersort(array,left,right,temp);
	free(temp);
}
int main(){
	int array[] = { 3, 4, 5, 7, 1, 2, 0, 6, 9 };
	int sz = sizeof(array) / sizeof(array[0]);
	mergersort(array,0,sz,sz);
	int i = 0;
	for (i = 0; i < sz; i++){
		printf("%d ", array[i]);
	}
	system("pause");
	return 0;
}