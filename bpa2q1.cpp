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
class Graph{
public:
    int v;
    int e;
    Node** adj;
    Graph(){
        v=0;
        e=0;
        adj=NULL;
    }
    void add_edge(int u,int v){
        Node *ptr=adj[u];
        Node *temp=(Node*)calloc(1,sizeof(Node));
        temp->val=v;
        temp->next=ptr;
        adj[u]=temp;
        e++;
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
int check_bridges(Graph G){
    int vertices=G.v,i,u,v,c,f=0,count=0,vis[vertices],disc[vertices],low[vertices];
    for(i=0;i<vertices;i++)vis[i]=0;
    Stack S,S1,S2;
    for(i=0;i<vertices;i++){
        if(vis[i]==0){
            count++;
            disc[i]=count;
            low[i]=count;
            vis[i]=1;
            printf("Visiting:%d\n",i);
            S.push(i);
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
                        printf("Visiting:%d\n",v);
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
                    // S.p  rint();
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
                            // printf("Bridge edge:");
                            // printf("%d %d\n",S.head->val,u);
                            S1.push(S.head->val);
                            S2.push(u);
                            f=1;
                        }
                    }
                }
            }
        }
    }
    Node *ptr1,*ptr2;
    ptr1=S1.head;
    ptr2=S2.head;
    while(ptr1!=NULL&&ptr2!=NULL){
        printf("Bridge edge:");
        printf("%d %d\n",ptr1->val,ptr2->val);
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return f;
}
int main() {
    int i,vertices,edges,u,v;
    scanf("%d%d",&vertices,&edges);
	Graph G;
	G.v=vertices;
    G.adj=(Node**)calloc(G.v,sizeof(Node*));
	for(i=0;i<edges;i++){
		scanf("%d%d",&u,&v);
        G.add_edge(u,v);
        G.add_edge(v,u);
	}
    G.print();
    if(check_bridges(G)==0)printf("No\n");
    return 0;
}