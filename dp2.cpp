#include<iostream>
#include<math.h>
void find_min_pen(int n,int a[]){
	int i,j,min,S[n];
	for(i=0;i<n;i++){
		min=pow(200-a[i],2);
		for(j=i-1;j>=0;j--){
			if(S[j]+pow(200-(a[i]-a[j]),2)<min)min=S[j]+pow(200-(a[i]-a[j]),2);
		}
		S[i]=min;
	}
	printf("Minimum penalty=%d\n",S[n-1]);
}
int main(){
	int n,i;
	printf("Enter size of array:");
	scanf("%d",&n);
	int a[n];
	printf("Enter array:");
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	find_min_pen(n,a);
	return 0;
}