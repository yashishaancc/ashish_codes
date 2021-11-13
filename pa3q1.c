#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node *next;
}Node;
typedef struct stack{
    // int str[1000];
    Node* head;
    // int top;
    // int size;
}Stack;
typedef struct graph{
	int v;
	Node **arr;
}Graph;
void push(Stack* stk,int v){
    // if(stk->top==stk->size)return;
    // stk->str[stk->top++]=v;
    Node* node=(Node*)malloc(1*sizeof(Node));
    node->val=v;
    node->next=stk->head;
    stk->head=node;
}
int pop(Stack* stk){
    if(stk->head==NULL)return -1;
    int to_return=stk->head->val;
    stk->head=stk->head->next;
    return to_return;
}
void printS(Stack* S){
    Node* ptr=S->head;
    while(ptr!=NULL){
        printf("%d\n",ptr->val);
        ptr=ptr->next;
    }
}
void print(Graph G){
	int i;
	for(i=0;i<G.v;i++){
		Node **ptr=&G.arr[i];
		printf("AdjList of %6d is:",i);
		while(*ptr!=NULL){
			printf("%6d",(*ptr)->val);
            ptr=&((*ptr)->next);
		}
		printf("\n");
	}
}
void scc_kosaraju(Graph G,int vertices){
    int source,s_ver,e_ver,vis[vertices],max=1,count,c,i;
    for(i=0;i<vertices;i++)vis[i]=0;
    Stack S,S2;
    // S.size=1000;
    // S.top=0;
    // S2.size=1000;
    // S2.top=0;
    S.head=NULL;
    S2.head=NULL;
    for(i=0;i<vertices;i++){
        if(vis[i]==0){
            source=i;
            // printf("HI 1\n");
            // printf("S.head=%ld\n",(long)S.head);
            push(&S,source);
            printf("Stack S:\n");
            printS(&S);
            // printf("HI 2\n");
            vis[source]=1;
            count=0;
            printf("Visiting:%d\n",source);
            // printf("S.head=%ld\n",(long)S.head);
            while(S.head!=NULL){
                s_ver=S.head->val;
                // printf("s_ver=%d\n",s_ver);
                Node **ptr=&G.arr[s_ver];
                c=0;
                // printf("HI 3\n");
                while(*ptr!=NULL){
                    e_ver=(*ptr)->val;
                    if(vis[e_ver]==0){
                        // printf("HI 4\n");
                        push(&S,e_ver);
                        printf("Stack S:\n");
                        printS(&S);
                        // printf("HI 5\n");
                        vis[e_ver]=1;
                        printf("Visiting:%d\n",e_ver);
                        c++;
                        break;
                    }
                    // printf("HI 6\n");
                    ptr=&((*ptr)->next);
                }
                // printf("HI 7\n");
                vis[s_ver]=2;
                count++;
                if(c==0){
                    pop(&S);
                    printf("Stack S:\n");
                    printS(&S);
                    push(&S2,s_ver);
                    printf("Stack S2:\n");
                    printS(&S2);
                    printf("finishing:%d\n",s_ver);
                }
                // printf("HI 8\n");
                // printf("S.head=%ld\n",(long)S.head);
            }
            // if(count>max)max=count;
        }
        // printf("HI 9\n");
    }
    // printf("HI 10\n");
    Graph GR;
    GR.v=G.v;
    GR.arr=(Node**)calloc(G.v, sizeof(Node*));
    for(i=0;i<G.v;i++){
        Node **ptr=&G.arr[i];
        // printf("AdjList of %6d is:",i);
        while(*ptr!=NULL){
            // printf("%6d",(*ptr)->val);
            // Node *node=(Node*)calloc(1,sizeof(Node));
            Node **qtr=&GR.arr[(*ptr)->val];
            while(*qtr!=NULL){
                // printf("*ptr->val=%d\n",(*ptr)->val);
                qtr=&((*qtr)->next);
            }
            Node *node=(Node*)calloc(1,sizeof(Node));
            (*node).val=i;
            *qtr=node;
            (*qtr)->next=NULL;
            ptr=&((*ptr)->next);
        }
        // printf("\n");
    }
    // printf("%d\n",max);
    printf("G:\n");
    print(G);
    printf("GR:\n");
    print(GR);
    // printf("GR:\n");
    for(i=0;i<vertices;i++)vis[i]=0;
    Stack S3;
    // S3.size=1000;
    // S3.top=0;
    S3.head=NULL;
    for(i=0;i<vertices;i++){
    //     if(vis[i]==0){
            source=pop(&S2);
            printf("Stack S2:\n");
            printS(&S2);
            if(vis[source]==0){
                push(&S3,source);
                printf("Stack S3:\n");
                printS(&S3);
            }
            vis[source]=1;
            count=0;
            while(S3.head!=NULL){
                s_ver=S3.head->val;
                Node **ptr=&GR.arr[s_ver];
                c=0;
                while(*ptr!=NULL){
                    e_ver=(*ptr)->val;
                    if(vis[e_ver]==0){
                        push(&S3,e_ver);
                        printf("Stack S3:\n");
                        printS(&S3);
                        vis[e_ver]=1;
                        c++;
                        break;
                    }
                    ptr=&((*ptr)->next);
                }
                vis[s_ver]=2;
                // count++;
                if(c==0){
                    pop(&S3);
                    printf("Stack S3:\n");
                    printS(&S3);
                    count++;
                    // push(&S3,s_ver);
                }
            }
            printf("Scc_length_from:%3d=%d\n",source,count);
            if(count>max)max=count;
        // }
    }
    printf("max_len of scc=%d\n",max);
}
int main() {
    int t,i,j,vertices,edges;
    scanf("%d",&t);
    for(int k=0;k<t;k++){
    	Graph G;
    	scanf("%d%d",&vertices,&edges);
    	G.v=vertices;
    	// Node nodes[vertices];
    	// for(j=0;j<vertices;j++)nodes[j].val=j;
    	G.arr=(Node**)calloc(G.v, sizeof(Node*));
    	// for(j=0;j<vertices;j++){
            // if(G.arr[j].next==NULL)printf("%d\n",j);
            // printf("(G.arr[j])=%16ld\n",(long)*(int*)G.arr);
            // G.arr[j].head=NULL;
        // }
    	int u,v;
    	for(j=0;j<edges;j++){
    		scanf("%d%d",&u,&v);
    		Node **ptr=&G.arr[u];
    		while(*ptr!=NULL){
                // printf("*ptr->val=%d\n",(*ptr)->val);
    			ptr=&((*ptr)->next);
    		}
            Node *node=(Node*)calloc(1,sizeof(Node));
            (*node).val=v;
            *ptr=node;
    		(*ptr)->next=NULL;
            // print(G);
    	}
    	// print(G);
        scc_kosaraju(G,vertices);
    }
    return 0;
}

/*
1

8
9

0 1
1 2
2 0
2 3
3 4
4 5
5 6
6 3
4 7
*/
