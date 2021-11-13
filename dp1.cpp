#include<iostream>
void find_max_sum_cont_sub(int n,int a[]){
	int i,S[n+1];
	S[0]=0;
	for(i=1;i<=n;i++){
		S[i]=(S[i-1]>0)?S[i-1]+a[i-1]:a[i-1];
	}
	printf("Maximum sum of contiguous subsequence=%d\n",S[n]);
}
int main(){
	int n,i;
	printf("Enter size of array:");
	scanf("%d",&n);
	int a[n];
	printf("Enter array:");
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	find_max_sum_cont_sub(n,a);
	return 0;
}