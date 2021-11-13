#include<iostream>
using namespace std;
typedef struct node{
	int val,w;
	struct node* next;
}Node;
typedef struct edge{
    int u,v,w;
}Edge;
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
		if(head==NULL)return -1;
		Node* temp = head;
		head = head->next;
		int to_return = temp->val;
		free(temp);
		return to_return;
	}
	int seek(){
		if(head==NULL)return -1;
		return head->val;
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
	Node *head,*tail;
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
		if(head==NULL)return -1;
		Node* temp = head;
		head = head->next;
		int to_return = temp->val;
		free(temp);
		if(head==NULL)tail=NULL;
		return to_return;
	}
	int seek(){
		if(head==NULL)return -1;
		return head->val;
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
	int v,e,d,w;
	Node **adj;
	Edge **edg;
	Graph(){
		v=0;
		e=0;
		d=0;
		w=0;
		adj=NULL;
		edg=NULL;
	}
	void set_vertices(int vertices){
		v=vertices;
		adj=(Node**)calloc(v,sizeof(Node*));
	}
	void add_edge(int u1,int u2,int wt){
		if(u1>=v)return;
		Node *ptr=adj[u1];
        Node *temp1=(Node*)calloc(1,sizeof(Node));
        temp1->val=u2;
        temp1->w=wt;
        temp1->next=ptr;
        adj[u1]=temp1;
        Edge* temp2=(Edge*)malloc(1*sizeof(Edge));
	    temp2->u=u1;
	    temp2->v=u2;
	    temp2->w=wt;
	    edg[e]=temp2;
        e++;
	}
	void remove_edge(int u1,int u2){
		if(u1>=v)return;
		Node **temp=&adj[u1];
		while(*temp!=NULL){
			if((*temp)->val==u2){
				Node* ptr=*temp;
				*temp=(*temp)->next;
				free(ptr);
				e--;
				break;
			}
			temp=&((*temp)->next);
		}
	}
	void print(){
		int i;
		for(i=0;i<v;i++){
			Node *temp=adj[i];
			printf("\x1b[34mAdjList of %6d is:\x1b[0m",i);
			while(temp!=NULL){
				printf("\x1b[34m%4d(%d)\x1b[0m\t",(temp)->val,temp->w);
	            temp=temp->next;
			}
			printf("\n");
		}
	}
};
void Quick_Sort(Edge** edg,int p,int q){
    int piv=edg[q]->w,i=p,j=p-1;
    for(i=p;i<=q;i++){
        if(edg[i]->w<=piv){
            Edge *temp=edg[i];
            edg[i]=edg[j+1];
            edg[j+1]=temp;
            j++;
        }
    }
    if(j-p>0)Quick_Sort(edg,p,j-1);
    if(q-j>0)Quick_Sort(edg,j+1,q);
}
void BFS(Graph G){
	Queue Q;
    int V=G.v,s,i,j,u,v,c=0,f=1,vis[V],d[V],par[V],bfs[V];
    for(i=0;i<V;i++)vis[i]=0;
    for(i=0;i<V;i++){
        if(vis[i]==0){
            s=i;
            d[s]=0;
            par[s]=-1;
            vis[s]=1;
            bfs[c++]=s;
            Q.enqueue(s);
            // printf("enqueued:\t%d\n",s);
            // printf("Q:\x1b[0m");
            // Q.print();
            while(Q.head!=NULL){
                u=Q.dequeue();
                Node *ptr=G.adj[u];
                while(ptr!=NULL){
                    v=ptr->val;
                    if(vis[v]==0){
                        d[v]=d[u]+1;
                        par[v]=u;
                        vis[v]=1;
                        bfs[c++]=v;
                        Q.enqueue(v);
                    }
                    else if(f==1&&d[v]==d[u])f=0;
                    ptr=ptr->next;
                }
            }
        }
    }
    printf("\x1b[33mBFS travesal of Graph is:\x1b[0m");
    for(i=0;i<V;i++)printf("\x1b[34m%6d\x1b[0m",bfs[i]);
    printf("\n");
    printf("\x1b[33mBFS shortest distances are:\x1b[0m\n");
    for(i=0;i<V;i++){
    	printf("\x1b[34mdist[%2d]=%2d\x1b[0m\t",j=bfs[i],d[bfs[i]]);
    	if(i==V-1||d[bfs[i+1]]!=d[j])printf("\n");
    }
    if(f==1)printf("\x1b[32mGraph is Bipartite\x1b[0m\n");
    else printf("\x1b[32mGraph is not Bipartite\x1b[0m\n");
}
void DFS(Graph G){
	int V=G.v,i,j=0,k=0,u,v,count,c=0,f=0,vis[V],disc[V],low[V],dfs[V];
    for(i=0;i<V;i++)vis[i]=0;
    Stack S,S1,S2;
    for(i=0;i<V;i++){
        if(vis[i]==0){
        	j++;
            disc[i]=j;
            low[i]=j;
            vis[i]=1;
            dfs[c++]=i;
            S.push(i);
            while(S.head!=NULL){
                u=S.head->val;
                Node *ptr=G.adj[u];
                count=0;
                while(ptr!=NULL){
                    v=ptr->val;
                    if(vis[v]==0){
                    	j++;
                        disc[v]=j;
                        low[v]=j;
                    	vis[v]=1;
                    	dfs[c++]=v;
                        S.push(v);
                        count++;
                        break;
                    }
                    ptr=ptr->next;
                }
                if(count==0){
                	S.pop();
                	ptr=G.adj[u];
                    while(ptr!=NULL){
                        v=ptr->val;
                        if(S.head==NULL||v!=S.head->val){
                            if(low[v]<low[u])low[u]=low[v];
                        }
                        ptr=ptr->next;
                    }
                    if(S.head!=NULL){
                        if(low[u]>disc[S.head->val]){
                            S1.push(S.head->val);
                            S2.push(u);
                            f++;
                        }
                    }
                }
            }
        }
    }
    printf("\x1b[33mDFS travesal of Graph is:\x1b[0m");
    for(i=0;i<V;i++)printf("\x1b[34m%6d\x1b[0m",dfs[i]);
    printf("\n");
    Node *ptr1,*ptr2;
    ptr1=S1.head;
    ptr2=S2.head;
    if(f!=0)printf("\x1b[33mBridge edges are:\x1b[0m\n");
    while(ptr1!=NULL&&ptr2!=NULL){
        printf("\x1b[34mBridge edge number %3d is:%2d %2d\x1b[0m\n",++k,ptr1->val,ptr2->val);
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    if(f==0)printf("\x1b[32mNo Bridges\x1b[0m\n");
    else printf("\x1b[32mTotal number of bridges=%d\x1b[0m\n",f);
}
void scc_kosaraju(Graph G){
    int i,j=0,V=G.v,source,u,v,vis[V],scc[V],Scc[V],max=1,count,c;
    for(i=0;i<V;i++)vis[i]=0;
    Stack S,S2;
    for(i=0;i<V;i++){
        if(vis[i]==0){
            vis[i]=1;
            S.push(i);
            while(S.head!=NULL){
                u=S.head->val;
                Node *ptr=G.adj[u];
                c=0;
                while(ptr!=NULL){
                    v=ptr->val;
                    if(vis[v]==0){
                    	vis[v]=1;
                        S.push(v);
                        c++;
                        break;
                    }
                    ptr=ptr->next;
                }
                if(c==0){
                    S.pop();
                    S2.push(u);
                }
            }
        }
    }
    Graph GR=G;
    if(G.d){
	    GR.e=0;
	    GR.adj=(Node**)calloc(GR.v, sizeof(Node*));
	    for(i=0;i<G.v;i++){
	        Node *ptr=G.adj[i];
	        while(ptr!=NULL){
	        	GR.add_edge(ptr->val,i,ptr->w);
	            ptr=ptr->next;
	        }
	    }
	    // printf("\x1b[33mGR:\x1b[0m\n");
	    // GR.print();
	}
    for(i=0;i<V;i++)vis[i]=0;
    Stack S3;
	printf("\x1b[33mSCCs are:\x1b[0m\n");
    for(i=0;i<V;i++){
        source=S2.pop();
        if(vis[source]==0){
            S3.push(source);
	        vis[source]=1;
	        count=0;
	        while(S3.head!=NULL){
	            u=S3.head->val;
	            Node *ptr=GR.adj[u];
	            c=0;
	            while(ptr!=NULL){
	                v=ptr->val;
	                if(vis[v]==0){
	                    S3.push(v);
	                    vis[v]=1;
	                    c++;
	                    break;
	                }
	                ptr=ptr->next;
	            }
	            vis[u]=2;
	            if(c==0){
	                S3.pop();
	                Scc[u]=j;
	                scc[count++]=u;
	            }
	        }
		    j++;
		    printf("\x1b[34mSCC number %3d of length %2d is:\x1b[0m",j,count);
		    for(c=0;c<count;c++)printf("\x1b[34m%6d\x1b[0m",scc[c]);
		    printf("\n");
	        if(count>max)max=count;
	    }
    }
    printf("\x1b[32mLength of largest scc=%d\x1b[0m\n",max);
}
void path_dijkstra(Graph G){
    int V=G.v,i,j,f=-1,s,t,u,v,w,c,min,min_idx,count=0,vis[V],d[V],p[V],wt[V];
    for(i=0;i<V;i++){vis[i]=0;d[i]=INT32_MAX;p[i]=-1;wt[i]=INT32_MAX;}
    Queue Q;
    for(i=0;i<V;i++){
    	s=i;
    	t=V-1;
	    d[s]=0;
	    p[s]=-1;
	    wt[s]=0;
	    vis[s]=1;
	    Q.enqueue(s);
	    while(Q.head!=NULL){
	        u=Q.dequeue();
	        if(u==t)break;
	        vis[u]=2;
	        Node *ptr=G.adj[u];
	        min=-1;
	        while(ptr!=NULL){
	            v=ptr->val;
	            w=ptr->w;
	            if(vis[v]==0){
	                d[v]=d[u]+w;
	                p[v]=u;
	                wt[v]=w;
	                vis[v]=1;
	            }
	            else if(d[u]+w<d[v]){
	            	d[v]=d[u]+w;
	            	p[v]=u;
	            	wt[v]=w;
	            }
	            ptr=ptr->next;
	        }
	        for(j=0;j<V;j++){
	            if(vis[j]==1&&(min==-1||d[j]<min)){
                    min=d[j];
                    min_idx=j;
	            }
	        }
	        if(min!=-1)Q.enqueue(min_idx);
	    }
	    printf("\x1b[33mShortest path from %d to %d is :\x1b[0m",s,v=t);
	    while(v!=s&&v!=-1){
	    	printf("\x1b[31m%d\x1b[0;34m<--(%d)-\x1b[0m",v,wt[v]);
	    	v=p[v];
	    }
	    printf("\x1b[31m%d\x1b[0m\n",s);
	    printf("\x1b[32mShortest path length from %2d to %2d=%d\x1b[0m\n",s,t,d[t]);
	    break;
	}
}
void min_span_tree_kruskal(Graph G){
    int V=G.v,E=G.e,i,j,u,v,w,lw,c=0,sum=0,root[V];
    Edge **edg=G.edg;
    for(i=0;i<V;i++)root[i]=i;
    lw=edg[E-1]->w;
    for(i=0;i<E;i++){
        if(edg[i]->w>lw){
            for(j=E-1;j>i;j--){
                Edge *t=edg[j];
                edg[j]=edg[j-1];
                edg[j-1]=t;
            }
            break;
        }
    }
    printf("\x1b[33mMinimum spanning tree edges are:\x1b[0m\n");
    for(i=0;i<E;i++){
        u=edg[i]->u;
        v=edg[i]->v;
        w=edg[i]->w;
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
            printf("\x1b[34mEdge number %3d is:%d\t%d\t%d\x1b[0m\n",++c,edg[i]->u,edg[i]->v,w);
            root[u]=root[v];
        }
    }
    printf("\x1b[32mWeight of minimum spanning tree=%d\x1b[0m\n",sum);
}
void Examine(Graph G){
	BFS(G);
	DFS(G);
	scc_kosaraju(G);
	path_dijkstra(G);
	min_span_tree_kruskal(G);
}
int main(){
	int i,vertices,edges,directed,weighted,u,v,w=1;
	printf("On the first line print 4 integers separated by a space whose description is given below\n");
	printf("\x1b[33mEnter no. of vertices in graph:\x1b[0m\n");
	printf("\x1b[33mEnter no. of edges in graph:\x1b[0m\n");
	printf("\x1b[33mEnter 1 if Graph is directed and 0 if Graph is undirected:\x1b[0m\n");
	printf("\x1b[33mEnter 1 if Graph is weighted and 0 if Graph is unweighted:\x1b[0m\n");
    printf("\x1b[36mAfter that enter (no. of edges)lines each having two vertices denoting an edge.\x1b[0m\n");
    printf("\x1b[36mIf Graph is weighted then also enter weight of each edge alongside.\x1b[0m\n");
	scanf("%d",&vertices);
    scanf("%d",&edges);
    scanf("%d",&directed);
    scanf("%d",&weighted);
	Graph G;
	G.v=vertices;
    G.d=directed;
    G.w=weighted;
    G.adj=(Node**)calloc(G.v,sizeof(Node*));
    G.edg=(Edge**)malloc(edges*sizeof(Edge*));
	for(i=0;i<edges;i++){
		if(weighted)scanf("%d%d%d",&u,&v,&w);
		else scanf("%d%d",&u,&v);
        G.add_edge(u,v,w);
        if(!directed)G.add_edge(v,u,w);
	}
	Quick_Sort(G.edg,0,edges-1);
	printf("\x1b[33mGraph G:\x1b[0m\n");
	G.print();
	Examine(G);
	return 0;
}/*example graph:
9 9 1 1
0 1 2
1 2 3
2 0 4
1 3 5
3 5 6
3 4 9
7 3 8
8 2 6
4 7 3
*/