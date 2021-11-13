#include<iostream>
using namespace std;
typedef struct node{
    int val,w;
    struct node* next;
}Node;
typedef struct edge{
    int u,v,w;
}Edge;
void Insert(Edge** arr,int u,int v,int w,int i){
    Edge* temp=(Edge*)malloc(1*sizeof(Edge));
    temp->u=u;
    temp->v=v;
    temp->w=w;
    arr[i]=temp;
}
void Quick_Sort(Edge** arr,int p,int q){
    int piv=arr[q]->w,i=p,j=p-1;
    for(i=p;i<=q;i++){
        if(arr[i]->w<=piv){
            Edge *temp=arr[i];
            arr[i]=arr[j+1];
            arr[j+1]=temp;
            j++;
        }
    }
    if(j-p>0)Quick_Sort(arr,p,j-1);
    if(q-j>0)Quick_Sort(arr,j+1,q);
}
void print(Edge **arr,int e){
    printf("Array is:\n\tu\tv\tw\n");
    for(int i=0;i<e;i++){
        int u=arr[i]->u;
        int v=arr[i]->v;
        int w=arr[i]->w;
        printf("\t%d\t%d\t%d\n",u,v,w);
    }
}
void min_span_tree(int vertices,int e,Edge **arr){
    int i,j,u,v,w,lw,sum=0,root[vertices];
    for(i=0;i<vertices;i++)root[i]=i;
    lw=arr[e-1]->w;
    for(i=0;i<e;i++){
        if(arr[i]->w>lw){
            for(j=e-1;j>i;j--){
                Edge *t=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=t;
            }
            break;
        }
    }
    print(arr,e);
    printf("Spanning tree edges are:\n");
    for(i=0;i<e;i++){
        u=arr[i]->u;
        v=arr[i]->v;
        w=arr[i]->w;
        while(root[v]!=v){
            root[v]=root[root[v]];
            v=root[v];
        }
        while(root[u]!=u){
            root[u]=root[root[u]];
            u=root[u];
        }
        if(root[u]!=root[v]){
            sum+=w;
            printf("\t%d\t%d\t%d\n",arr[i]->u,arr[i]->v,w);
            root[u]=root[v];
        }
    }
    printf("%d\n",sum);
}
int main() {
    int i,vertices,edges,queries,u,v,w;
    scanf("%d%d%d",&vertices,&edges,&queries);
    Edge **arr=(Edge**)malloc((edges+queries)*sizeof(Edge*));
    for(i=0;i<edges;i++){
        scanf("%d%d%d",&u,&v,&w);
        Insert(arr,u,v,w,i);
    }
    Quick_Sort(arr,0,edges-1);
    min_span_tree(vertices,edges,arr);
    for(i=0;i<queries;i++){
        scanf("%d%d%d",&u,&v,&w);
        Insert(arr,u,v,w,edges+i);
        min_span_tree(vertices,edges+i+1,arr);
    }
    return 0;
}