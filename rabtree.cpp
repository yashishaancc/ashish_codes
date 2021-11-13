#include<iostream>
#include<math.h>
using namespace std;
typedef struct tree{
	int v,c;
	tree *p,*l,*r;
}tree;
void print(tree *root){
	if(root->l!=NULL)print(root->l);

	printf("%-4d:\t",root->v);
	if(root->l!=NULL)printf("\x1b[%dm%-4d\x1b[0m",(root->l->c==0)?35:31,root->l->v);
	else printf("\x1b[%dmNULL\x1b[0m",35);
	if(root->r!=NULL)printf("\x1b[%dm%-4d\x1b[0m",(root->r->c==0)?35:31,root->r->v);
	else printf("\x1b[%dmNULL\x1b[0m",35);
	printf("\n");

	if(root->r!=NULL)print(root->r);
}
void printtree(tree *rooot,int n){
	tree* root[4*n];
	int i=3;
	root[0]=rooot;
	root[1]=rooot->l;
	root[2]=rooot->r;
	while(i<3*n){
		int p=(i-1)/2;
		if(root[p]==NULL)root[i]=NULL;
		else if(i==2*p+1)root[i]=root[p]->l;
		else root[i]=root[p]->r;
		i++;
	}
	i=0;
	int H=floor(log2(3*n));
	int h=0;
	while(i<4*n){
		int i1=i;
		int i2=2*i;
		for(int j=0;j<pow(2,H-h)-1;j++)printf("    ");
		for(i=i1;i<i2&&i<4*n-1;i++){
			if(root[i]!=NULL)printf("\x1b[%dm%-4d\x1b[0m",(root[i]->c==0)?35:31,root[i]->v);
			else printf("\x1b[%dmNULL\x1b[0m",35);
			for(int j=0;j<pow(2,H-h+1)-1;j++)printf("    ");
		}
		if(root[i]!=NULL)printf("\x1b[%dm%-4d\x1b[0m",(root[i]->c==0)?35:31,root[i]->v);
		else printf("\x1b[%dmNULL\x1b[0m",35);
		i++;
		h++;
		printf("\n\n");
	}
}
void lr(tree *pt){
	tree *ptt,*ptp,*ptr,*ptrl;
	ptt=pt;
	ptp=pt->p;
	ptr=pt->r;
	ptrl=pt->r->l;
	ptp->r=ptr;
	ptt->p=ptr;
	ptt->r=ptrl;
	ptr->p=ptp;
	ptr->l=ptt;
	ptrl->p=ptt;
}
void rr(tree *pt){
	tree *ptt,*ptp,*ptl,*ptlr;
	ptt=pt;
	ptp=pt->p;
	ptl=pt->l;
	ptlr=pt->l->r;
	ptp->l=ptl;
	ptt->p=ptl;
	ptt->l=ptlr;
	ptl->p=ptp;
	ptl->r=ptt;
	ptlr->p=ptt;
}
void insert(int i
	,tree *rab,tree *root){
	if(i>0){
		tree *pt=root;
		while(1){
			if(rab->v<pt->v){
				if(pt->l==NULL){
					pt->l=rab;
					rab->p=pt;
					return;
				}
				else pt=pt->l;
			}
			else{
				if(pt->r==NULL){
					pt->r=rab;
					rab->p=pt;
					return;
				}
				else pt=pt->r;
			}
		}
		rab->c=1;
		if(rab->p->c==1){
			while(rab->p!=NULL&&rab->p->c==1){
				if(rab->p->p->l==rab->p){
					if(rab->p->p->r==NULL||rab->p->p->r->c==0){
						if(rab->p->r==rab){
							lr(rab->p);
							rab=rab->l;
						}
						rab->p->c=0;
						rab->p->p->c=1;
						rr(rab->p->p);
						return;
					}
					else{
						rab->p->c=0;
						rab->p->p->r->c=0;
						if(rab->p->p!=root)rab->p->p->c=1;
						rab=rab->p->p;
					}
				}
				if(rab->p->p->r==rab->p){
					if(rab->p->p->l==NULL||rab->p->p->l->c==0){
						if(rab->p->l==rab){
							rr(rab->p);
							rab=rab->r;
						}
						rab->p->c=0;
						rab->p->p->c=1;
						lr(rab->p->p);
						return;
					}
					else{
						rab->p->c=0;
						rab->p->p->l->c=0;
						if(rab->p->p!=root)rab->p->p->c=1;
						rab=rab->p->p;
					}
				}
			}
		}
	}
}


int main(){
	int n,i;
	scanf("%d",&n);
	int a[n];
	tree rb[n],*root;
	root=&rb[0];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		rb[i].v=a[i];
		rb[i].c=0;
		rb[i].p=NULL;
		rb[i].l=NULL;
		rb[i].r=NULL;
		insert(i,&rb[i],root);
	}
	print(root);
	printtree(root,n);
}