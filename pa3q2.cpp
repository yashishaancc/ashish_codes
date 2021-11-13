#include <stdio.h>
#include <iostream>
#include <chrono>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
using namespace std::chrono;
typedef struct node{
    int val;
    struct node *next;
}Node;
typedef struct queue{
    // int arr[1000];
    // int rear=999;
    // int front=0;
    // int size;
    Node *head;
    Node *tail;
}Queue;
typedef struct graph{
	int v;
	Node **arr;
}Graph;
void Enqueue(Queue* Q,int v){
    // if(Q->size==1000)return;
    // Q->size++;
    // Q->rear=(Q->rear+1)%1000;
    // Q->arr[Q->rear]=v;
    Node* node=(Node*)calloc(1,sizeof(Node));
    node->val=v;
    // printf("Q->tail=%ld\n",(long)Q->tail);
    if(Q->tail!=NULL)Q->tail->next=node;
    else Q->head=node;
    // printf("Q->head->val=%d\n",Q->head->val);
    Q->tail=node;
}
int Dequeue(Queue* Q){
    // if(Q->size==0)return -1;
    // Q->size--;
    // Q->front=(Q->front+1)%1000;
    // return Q->arr[(Q->front+999)%1000];
    if(Q->head==NULL)return -1;
    int to_return =Q->head->val;
    Q->head=Q->head->next;
    if(Q->head==NULL)Q->tail=NULL;
    return to_return;
}
void printQ(Queue* Q){
    Node* ptr=Q->head;
    while(ptr!=NULL){
        printf("%2d ",ptr->val);
        ptr=ptr->next;
    }
    printf("\n");
}
bool check_bipartite(Graph G){
    Queue Q;
    // Q.size=0;
    Q.head=NULL;
    Q.tail=NULL;
    int V=G.v,s,i,u,v;
    int col[V],d[V],p[V];
    for(i=0;i<V;i++)col[i]=0;
    for(i=0;i<V;i++){
        if(col[i]==0){
            s=i;
            d[s]=0;
            Enqueue(&Q,s);
            printf("enqueued:\t%d\n",s);
            printf("Q:");
            printQ(&Q);
            // printf("Q.head->val=%d\n",Q.head->val);
            while(Q.head!=NULL){
                u=Dequeue(&Q);
                printf("dequeued:\t%d\n",u);
                printf("Q:");
                printQ(&Q);
                Node **ptr=&G.arr[u];
                while(*ptr!=NULL){
                    v=((*ptr)->val);
                    if(col[v]==0){
                        d[v]=d[u]+1;
                        p[v]=u;
                        col[v]=1;
                        Enqueue(&Q,v);
                        printf("enqueued:\t%d\n",v);
                        printf("Q:");
                        printQ(&Q);
                    }
                    else if(d[v]==d[u])return false;
                    // printf("%6d",(*ptr)->val);
                    ptr=&((*ptr)->next);
                }
                col[u]=2;
                // printf("\n");
            }
        }
    }
    return true;
}
void print(Graph G){
	int i,j;
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
int main() {
    int S,i,j,vertices,edges;
    scanf("%d",&S);
    for(i=0;i<S;i++){
        // auto start = high_resolution_clock::now();
    	Graph G;
    	scanf("%d%d",&vertices,&edges);
    	G.v=vertices;
    	// Node nodes[vertices];
    	// for(j=0;j<vertices;j++)nodes[j].val=j;
    	G.arr=(Node**)calloc(G.v,sizeof(Node*));
    	// for(j=0;j<vertices;j++){
            // if(G.arr[j].next==NULL)printf("%d\n",j);
            // printf("(G.arr[j])=%16ld\n",(long)*(int*)G.arr);
            // G.arr[j].head=NULL;
        // }
    	int u,v;
    	for(j=0;j<edges;j++){
    		scanf("%d%d",&u,&v);
            u--;
            v--;
    		Node *ptr=G.arr[u];
    		// while(*ptr!=NULL){
            // printf("*ptr->val=%d\n",(*ptr)->val);
    		// 	ptr=&((*ptr)->next);
    		// }
            Node *node=(Node*)calloc(1,sizeof(Node));
            (*node).val=v;
            node->next=ptr;
            G.arr[u]=node;
    		// (*ptr)->next=NULL;
            Node *qtr=G.arr[v];
            // while(*qtr!=NULL){
            //     // printf("*qtr->val=%d\n",(*qtr)->val);
            //     qtr=&((*qtr)->next);
            // }
            Node *nnode=(Node*)calloc(1,sizeof(Node));
            (*nnode).val=u;
            nnode->next = qtr;
            G.arr[v]=nnode;
            // (*qtr)->next=NULL;
    	}
        print(G);
        auto start = high_resolution_clock::now();
        if(check_bipartite(G)==true)printf("Yes\n");
        else printf("No\n");
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        printf("v=%-6d,e=%-6d,v+e=%-6d\n",vertices,edges,vertices+edges);
        cout << "\x1b[33mTime taken by function: \x1b[0;34m"<< duration.count() << " microseconds\x1b[0m" << endl;
    }
    return 0;
}