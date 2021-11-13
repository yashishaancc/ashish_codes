#include<iostream>
using namespace std;
typedef struct node{
    int val;
    int w;
    struct node* next;
}Node;
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
    void add_edge(int u,int v,int w){
        Node *ptr=adj[u];
        Node *temp=(Node*)calloc(1,sizeof(Node));
        temp->val=v;
        temp->w=w;
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
void best_path(Graph G,int s,int t){
    int vertices=G.v,i,f=-1,u,v,w,c,min,min_idx,count=0,vis[vertices],d[vertices],svis[vertices];
    for(i=0;i<vertices;i++){
        vis[i]=0;
        svis[i]=0;
    }
    Queue Q;
    d[s]=0;
    vis[s]=1;
    Q.enqueue(s);
    while(Q.head!=NULL){
        u=Q.dequeue();
        // printf("Visiting:%d\n",u);
        if(u==t)break;
        svis[u]=1;
        Node *ptr=G.adj[u];
        min=-1;
        while(ptr!=NULL){
            v=ptr->val;
            w=ptr->w;
            if(vis[v]==0){
                d[v]=d[u]+w;
                vis[v]=1;
            }
            else if(d[u]+w<d[v])d[v]=d[u]+w;
            ptr=ptr->next;
        }
        for(i=0;i<vertices;i++){
            if(vis[i]==1&&svis[i]==0){
                if(min==-1||d[i]<min){
                    min=d[i];
                    min_idx=i;
                }
            }
        }
        if(min!=-1)Q.enqueue(min_idx);
    }
    printf("Shortest path length from %d to %d is :",s,t);
    printf("%d\n",d[t]);
}
int main() {
    int i,vertices,edges,u,v,w;
    scanf("%d%d",&vertices,&edges);
	Graph G;
	G.v=vertices;
    G.adj=(Node**)calloc(G.v,sizeof(Node*));
	for(i=0;i<edges;i++){
		scanf("%d%d%d",&u,&v,&w);
        G.add_edge(u,v,w);
	}
    G.print();
    scanf("%d",&u);
    // scanf("%d%d",&u,&v);
    // best_path(G,u,v);
    for(v=0;v<vertices;v++)best_path(G,u,v);
    return 0;
}