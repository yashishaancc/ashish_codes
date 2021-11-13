#include<stdio.h>
#include<math.h>
void print(int*ar,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d",ar[i]);
	}
	printf("\n");
}
int check(int*ar,int n){
	int i,j,c[n],f=0;
	for(i=0;i<n;i++)c[i]=0;
	for(i=0;i<n;i++)c[ar[i]]++;
	for(i=0;i<n;i++){
		if(c[i]==ar[i])f++;
		else return 0;
	}
	if(f==n)return 1;
	else return 0;
}
int find_auto(int*ar,int n,int id){
	int i,j;
	if(id==n){
		if(check(ar,n)==1)return 1;
		else return 0;
	}
	for(i=0;i<n&&id*i<=n;i++){
		ar[id]=i;
		if(id==0&&i==0)continue;
		int sum=0;
		for(j=0;j<=id;j++)sum+=ar[j];
		if(sum>n)return 0;
		// print(ar,n);
		if(find_auto(ar,n,id+1)==1){
			print(ar,n);
			// return 1;
		}
	}
}
int main(){
	int n,i;
	printf("Enter no. of digits in autobiographic number:");
	scanf("%d",&n);
	int ar[n];
	for(i=0;i<n;i++)ar[i]=0;
	printf("Autobiographic number of length <=%d are:\n",n);
	// for(i=0;i<=n;i++)find_auto(ar,i,0);
	return 0;
}