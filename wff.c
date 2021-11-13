#include<stdio.h>
#include<stdlib.h>
void wff(char* c,char* l,char* str,int len,int* count,int n,int p,int lc,int hl){
	int ran,i,j;
	if(lc==hl){
		(*count)++;
		printf("%5d.\t",*count);
		puts(str);
		return;
	}
	if(1||(hl==5&&lc==0)){
		for(i=0;i<3;i++){
			str[len]=l[i+1];
			for(j=0;j<n;j++){
				str[len+1]=c[j];
				str[len+2]='\0';
				wff(c,l,str,len+2,count,n,0,lc+1,hl);
			}
		}
	}
}
int main(){
	int n,i,len=0,count=0,hl;
	printf("\x1b[33mEnter no. of propositions:\x1b[0m");
	scanf("%d",&n);
	char c[n],l[4]={"!&|>"};
	printf("\x1b[33mEnter %d propositional variables(single character) without any space:\x1b[0m",n);
	getchar();
	for(i=0;i<n;i++){
		c[i]=getchar();
	}
	printf("\x1b[33mEnter no. of logical connectives:\x1b[0m");
	scanf("%d",&hl);
	char str[1000];
	*(str)='\0';
	// puts(str);
	for(i=0;i<n;i++){
		str[len]=c[i];
		wff(c,l,str,len+1,&count,n,0,0,hl);
	}
	// puts(str);
	return 0;
}