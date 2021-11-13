#include<iostream>
using namespace std;
typedef struct node{
	int val;
	struct node* next;
}Node;
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
	void set_vertices(int vertices){
		v=vertices;
		adj=(Node**)calloc(v,sizeof(Node*));
	}
	void add_edge(int u1,int u2){
		if(u1>=v)return;
		Node *ptr=adj[u1];
        Node *temp=(Node*)calloc(1,sizeof(Node));
        temp->val=u2;
        temp->next=ptr;
        adj[u1]=temp;
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
			printf("AdjList of %6d is:",i);
			while(temp!=NULL){
				printf("%6d",(temp)->val);
	            temp=temp->next;
			}
			printf("\n");
		}
	}
};
int main(){
	Graph G;
	G.set_vertices(4);
	G.add_edge(0,0);
	G.add_edge(0,1);
	G.add_edge(0,2);
	G.add_edge(0,3);
	G.remove_edge(0,3);
	printf("Graph G:\n");
	G.print();
	return 0;
}