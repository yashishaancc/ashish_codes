#include<iostream>
#include<math.h>
using namespace std;
typedef struct node{
	int val,col; //col = colour of the node
	struct node *parent,*left,*right;
}Node;

Node* createNode(int n){
	Node* temp = (Node*)calloc(1, sizeof(Node));
	temp->val = n;
	return temp;
}

Node* insert(Node* root, int n){
	if(root=NULL){
		root = createNode(n);
		return root;
	}
	if(n < root->val){
		if(root->left==NULL){
			root->left = createNode(n);
			return root;
		}
		else{
			root->left = insert(root->left, n);
		}
	}
}

int main(){
	int n,i;
	scanf("%d",&n);
	Node* root = NULL;
	for(i=0; i<n; i++){
		int temp;
		scanf("%d", &temp);
		root = insert(root, temp);
	}
}