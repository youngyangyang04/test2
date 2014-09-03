/*************************************************************************
	> File Name: my_sort.c
	> Author: yang
	> Mail:826123027@qq.com 
	> Created Time: 2014年09月02日 星期二 09:38:38
 ************************************************************************/

#include<my_sort.h>
void arr_init(int* arr,int len){//
	int index;
	for(index=0;index<len;index++)
		arr[index]=rand()%1000;
}
void arr_show(int* arr,int len){
	int index;
	for(index=0;index<len;index++)
		printf("%d ",arr[index]);
	printf("\n");
}
void insert_sort(int*arr,int len){
	int pos,index;
	int key;
	for(pos=1;pos<len;pos++){
		key=arr[pos];
		for(index=pos-1;index>=0;index--){
			if(arr[index]<key)
				break;
			else
				arr[index+1]=arr[index];
		}
		arr[index+1]=key;
	}
}
void quick_sort(int *a,int left,int right){
	int l=left,r=right;
	int key=a[left];
	while(l<r){
		while(l<r && a[r]>=key) r--;
		if(l<r)
			a[l++]=a[r];
		while(l<r && a[l]<=key) l++;
		if(l<r)
			a[r--]=a[l];
	}
	a[l]=key;
	if(left>=right) return ;
	int mid=l;
	quick_sort(a,left,mid);
	quick_sort(a,mid+1,right);
}



