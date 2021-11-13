#include<iostream>
using namespace std;
typedef struct node{
	int val;
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
int main(){
	Queue Q;
	Q.enqueue(0);
	Q.enqueue(1);
	Q.enqueue(2);
	Q.enqueue(3);
	Q.dequeue();
	Q.seek();
	printf("Queue Q:\n");
	Q.print();
	return 0;
}