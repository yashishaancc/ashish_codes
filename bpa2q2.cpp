#include<iostream>
using namespace std;
typedef struct node{
    int val;
    struct node* next;
}Node;
class Stack{
public:
    Node* head;
    Stack(){
        head=NULL;
    }
    void push(int n){
        Node* temp = (Node*)calloc(1, sizeof(Node));
        temp->val = n;
        temp->next = head;
        head = temp;
    }
    int pop(){
        Node* temp = head;
        head = head->next;
        int to_return = temp->val;
        free(temp);
        return to_return;
    }
    void print(){
        Node* temp = head;
        while(temp!=NULL){
            printf("%d\n", temp->val);
            temp = temp->next;
        }
    }
};
class Queue{
public:
    Node* head;
    Node* tail;
    Queue(){
        head=NULL;
        tail=NULL;
    }
    void enqueue(int v){
        Node* temp=(Node*)calloc(1,sizeof(Node));
        temp->val=v;
        if(tail!=NULL)tail->next=temp;
        else head=temp;
        tail=temp;
    }
    int dequeue(){
        Node* temp = head;
        head = head->next;
        int to_return = temp->val;
        free(temp);
        if(head==NULL)tail=NULL;
        return to_return;
    }
    void print(){   
        Node* temp=head;
        while(temp!=NULL){
            printf("%d\t",temp->val);
            temp=temp->next;
        }
        printf("\n");
    }
};
class Graph{
public:
    int v;
    Node** adj;
    Graph(){
        v=0;
        adj=NULL;
    }
    void add_edge(int u,int v){
        Node *ptr=adj[u];
        Node *temp=(Node*)calloc(1,sizeof(Node));
        temp->val=v;
        temp->next=ptr;
        adj[u]=temp;
    }
    void print(){
        int i;
        for(i=0;i<v;i++){
            Node *temp=adj[i];
            printf("AdjList of %6d is:",i);
            while(temp!=NULL){
                printf("%6d",(temp)->val);
                temp=temp->next;
            }
            printf("\n");
        }
    }
};
int* bridge_dist(Graph G){
    int vertices=G.v,i,s=0,f=-1,u,v,c,count=0,vis[vertices],disc[vertices],low[vertices];
    for(i=0;i<vertices;i++)vis[i]=0;
    Stack S;
    count++;
    disc[s]=count;
    low[s]=count;
    vis[s]=1;
    // printf("Visiting:%d\n",s);
    S.push(s);
    // printf("Stack S:\n");
    // S.print();
    while(S.head!=NULL){
        u=S.head->val;
        Node *ptr=G.adj[u];
        c=0;
        while(ptr!=NULL){
            v=ptr->val;
            if(vis[v]==0){
                count++;
                disc[v]=count;
                low[v]=count;
                vis[v]=1;
                // printf("Visiting:%d\n",v);
                S.push(v);
                // printf("Stack S:\n");
                // S.print();
                c++;
                break;
            }
            ptr=ptr->next;
        }
        vis[u]=2;
        if(c==0){
            S.pop();
            // printf("Stack S:\n");
            // S.print();
            ptr=G.adj[u];
            c=0;
            while(ptr!=NULL){
                v=ptr->val;
                if(S.head==NULL||v!=S.head->val){
                    if(low[v]<low[u])low[u]=low[v];
                }
                ptr=ptr->next;
            }
            if(S.head!=NULL){
                if(low[u]>disc[S.head->val]){
                    printf("Bridge edge:");
                    printf("%d %d\n",S.head->val,u);
                    f=u;
                    break;
                }
            }
        }
    }
    static int *d;
    d=(int*)calloc(vertices,sizeof(int));
    for(i=0;i<vertices;i++)vis[i]=0;
    Queue Q;
    d[f]=0;
    vis[f]=1;
    // printf("Visiting:%d\n",f);
    Q.enqueue(f);
    // printf("Queue Q:");
    // Q.print();
    while(Q.head!=NULL){
        u=Q.dequeue();
        Node *ptr=G.adj[u];
        c=0;
        while(ptr!=NULL){
            v=ptr->val;
            if(vis[v]==0){
                d[v]=d[u]+1;;
                vis[v]=1;
                // printf("Visiting:%d\n",v);
                Q.enqueue(v);
                // printf("Queue Q:");
                // Q.print();
            }
            ptr=ptr->next;
        }
    }
    for(i=0;i<vertices;i++)printf("d[%d]=%d\n",i,d[i]);
    return d;
}
int main() {
    int i,vertices,edges,queries,u,v,b;
    scanf("%d%d%d",&vertices,&edges,&queries);
	Graph G;
	G.v=vertices;
    G.adj=(Node**)calloc(G.v,sizeof(Node*));
	for(i=0;i<edges;i++){
		scanf("%d%d",&u,&v);
        G.add_edge(u,v);
        G.add_edge(v,u);
	}
    G.print();
    int *d=bridge_dist(G);
    for(i=0;i<queries;i++){
        scanf("%d%d",&u,&v);
        printf("Shortest distance between %4d and %4d is:",u,v);
        printf("%d\n",d[u]+d[v]);
    }
    return 0;
}