#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enq(int x){
	struct node* temp = (struct node*)malloc(sizeof(struct node*));
	temp -> data = x;
	temp -> next = NULL;

	// if the queue is empty
	if(front == NULL && rear == NULL){
		front = temp;
		rear = temp;
		return;
	}
	rear -> next = temp;
	rear = temp;
}

void deq(){
	struct node* temp = front;
	if(front == NULL) return;
	if(front == rear){
		front = NULL;
		rear = NULL;

	}
	else{
		front = front -> next;
	}

	free(temp);
}

int main(){
	enq(4);
	enq(5);
}

