#include<iostream>
using namespace std;
int min_mat_oper(int arr[],int k){
	int i,j,min_oper[k][k],l,m,cost;
	for(i=0;i<k;i++)min_oper[i][i]=0;
	for(l=2;l<=k;l++){
		for(i=0;i<=k-l;i++){
			j=i+l;
			min_oper[i][j-1]=2147483647;
			for(m=i;m<j-1;m++){
				cost=min_oper[i][m]+min_oper[m+1][j-1]+arr[i]*arr[m+1]*arr[j];
				if(min_oper[i][j-1]>cost)min_oper[i][j-1]=cost;
			}
		}
	}
	return min_oper[0][k-1];
}
int main(){
	int i,j,t,k;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&k);
		int arr[k+1];
		for(j=0;j<=k;j++){
			scanf("%d",&arr[j]);
		}
		printf("%d\n",min_mat_oper(arr,k));
	}
	return 0;
}