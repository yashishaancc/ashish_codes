#include<iostream>
using namespace std;
long longest_common_subseq(char a[],char b[],long m,long n){
	long i,j,mat[2][n];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i]==b[j]){
				if(i==0||j==0)mat[1][j]=1;
				else mat[1][j]=1+mat[0][j-1];
			}
			else{
				if(i==0&&j==0)mat[1][j]=0;
				else if(i==0)mat[1][j]=mat[1][j-1];
				else if(j==0)mat[1][j]=mat[0][j];
				else mat[1][j]=(mat[1-1][j]>mat[1][j-1])?mat[1-1][j]:mat[1][j-1];
			}
		}
		for(j=0;j<n;j++)mat[0][j]=mat[1][j];
	}
	return mat[0][n-1];
}
int main(){
	long i,j,t,m,n;
	scanf("%ld",&t);
	for(i=0;i<t;i++){
		scanf("%ld%ld\n",&m,&n);
		char a[m],b[n];
		for(j=0;j<m;j++)scanf("%c",&a[j]);
		getchar();
		for(j=0;j<n;j++)scanf("%c",&b[j]);
		printf("%ld\n",longest_common_subseq(a,b,m,n));
	}
	return 0;
}