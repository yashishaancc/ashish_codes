#include<stdio.h>
void solve(int*a,int*l,int*r,int n,int b){
	int i,j,k,m;
	while(1){
		for(i=b;i>=1;i--){
			for(m=1;m<=n/i;m++){
				int c=0,f=0,q,p[n];
				for(j=0;j<n;j++){
					q=c;p[j]=0;
					if(c==i-1&&l[j]==1&&a[j]==1){c++;p[j]=1;}
					if(c<i-1&&l[j]==1){c++;p[j]=1;}
					if(c>q&&a[j]==1)f=1;
					if(c==i)break;
				}
				if(c==i&&f==1){
					printf("\x1b[33mTake ");
					for(k=0;k<=j;k++){
						if(p[k]&&l[k]==1){
							l[k]=0;
							r[k]=1;
							if(k<j)printf("%c,",'A'+k);
							else printf("%c",'A'+k);
						}
					}
					printf(" to the right.\x1b[0m\n");
					printf("\x1b[32mOn  left:");
					for(j=0;j<n;j++)if(l[j]==1)printf("%c ",'A'+j);else printf("  ");
					printf("\n\x1b[0m");
					printf("\x1b[32mOn right:");
					for(j=0;j<n;j++)if(r[j]==1)printf("%c ",'A'+j);else printf("  ");
					printf("\n\x1b[0m");
				}
				c=0;
				for(j=0;j<n;j++){
					if(l[j]==0)c++;
				}
				if(c==n){printf("Returning\n");return;}
			}
		}
	}
}
int main(){
	int n,b,i;
	printf("Enter total number of things on left bank:");
	scanf("%d",&n);
	int a[n],l[n],r[n];
	printf("Enter maximum capacity of boat:");
	scanf("%d",&b);
	printf("Who can row the boat:\nEnter 1 for that and else 0\neg. n=3 and 2,3 can row, then enter 0 1 1\nEnter here:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		l[i]=1;r[i]=0;
	}
	solve(a,l,r,n,b);
	return 0;
}