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
int main(){
	Stack S1;
	S1.push(0);
	S1.push(1);
	S1.push(2);
	S1.push(3);
	S1.pop();
	S1.seek();
	printf("Stack S1:\n");
	S1.print();
	return 0;
}