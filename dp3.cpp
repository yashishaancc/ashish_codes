#include<iostream>
#include<math.h>
void find_min_cost(int n1,int n2,char a[],char b[]){
	int i,j,min,C[n1][n2];
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			if(a[i]==b[j]){
				if(i==0)C[i][j]=j;
				else if(j==0)C[i][j]=i;
				else C[i][j]=C[i-1][j-1];
			}
			else{
				if(i==0&&j==0)C[i][j]=1;
				else if(i==0)C[i][j]=C[i][j-1];
				else if(j==0)C[i][j]=C[i-1][j];
				else {
					C[i][j]=(C[i-1][j]<C[i][j-1])?C[i-1][j]:C[i][j-1];
					if(C[i-1][j-1]+1<C[i][j])C[i][j]=C[i-1][j-1]+1;
				}
			}
		}
	}
	printf("Minimum cost=%d\n",C[n1-1][n2-1]);
}
int main(){
	int n1,n2,i;
	printf("Enter size of 1st word:");
	scanf("%d",&n1);
	printf("Enter size of 2nd word:");
	scanf("%d",&n2);
	char a[n1],b[n2];
	scanf("\n");
	printf("Enter 1st word:");
	for(i=0;i<n1;i++)scanf("%c",&a[i]);
	scanf("\n");
	printf("Enter 2nd word:");
	for(i=0;i<n2;i++)scanf("%c",&b[i]);
	for(i=0;i<n1;i++)printf("%c",a[i]);
	for(i=0;i<n2;i++)printf("%c",b[i]);
	find_min_cost(n1,n2,a,b);
	return 0;
}