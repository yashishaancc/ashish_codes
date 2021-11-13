#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void change(int k,int arr[],int *ptr){
	k=5;
	arr=&k;
	ptr=&arr[0];
	*ptr=9;
}

int main(){
	int a,ar[10];
	ar[5==6]=108;
	int i,j,k=4,arr[ar[1]];
	int *ptr=NULL;
	//printing before
	printf("k=%d\n",k);
	printf("arr=%16ld\n",(long)arr);
	printf("ptr=%16ld\n",(long)ptr);
	// printf("*ptr=%d\n",*ptr);
	printf("&arr=%16ld\n",(long)&arr);
	printf("*arr=%d\n",*arr);
	printf("arr[0]=%d\n",arr[0]);
	//changing
	change(k,arr,ptr);
	//printing
	printf("k=%d\n",k);
	printf("arr=%16ld\n",(long)arr);
	printf("ptr=%16ld\n",(long)ptr);
	// printf("*ptr=%d\n",*ptr);
	printf("&arr=%16ld\n",(long)&arr);
	printf("*arr=%d\n",*arr);
	printf("arr[0]=%d\n",arr[0]);
	return 0;
}