#include<stdio.h>
void combine(int *array, int left, int mid, int right, int *temp){
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
	while (r1<mid){
		temp[r3] = array[r1];
		r3++;
		r1++;
	}
	while (r2<right){
		temp[r3] = array[r2];
		r3++;
		r2++;
	}
	memcpy(array + left, temp + left, sizeof(int)*(right - left));
}
void mergersort(int *array,int sz){
	int gap = 1;
	int *temp;
	temp = (int *)malloc(sizeof(int)*sz);
	if (temp == NULL){
		perror(0);
		return;
	}
	while (gap <= sz){
		int i = 0;
		for (i = 0; i < sz; i =i+ 2 * gap){
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			//注意越界问题
			if (mid>sz){
				mid = sz;
			}
			if (right > sz){
				right = sz;
			}
			combine(array, left, mid, right, temp);
		}
		gap = gap * 2;
	}
	free(temp);
}
int main(){
	int array[] = { 3, 4, 5, 7, 1, 2, 0, 6, 8, 9 };
	int sz = sizeof(array) / sizeof(array[0]);
	mergersort(array, sz);
	int i = 0;
	for (i = 0; i < sz; i++){
		printf("%d ", array[i]);
	}
	system("pause");
	return 0;
}