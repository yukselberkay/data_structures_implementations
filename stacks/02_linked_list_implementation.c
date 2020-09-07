#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};


struct node* top = NULL;

void push(int x){
	struct node* temp = (struct node*)malloc(sizeof(struct node*));
       	temp -> data = x;
	temp -> next = top;
	top = temp;
}

void pop() {
	struct node* temp;
	// if stack is empty quit from function
	if(top == NULL) return;
	// temp node is pointing to top node
	temp = top;
	printf("%d is popped out from stack \n",temp->data);
	top = top -> next;
	free(temp);
}

void get_top() {
	if(top == NULL) return;
	printf("top node's data : %d\n", top->data);
}

void print_stack(){
	struct node* temp = (struct node*)malloc(sizeof(struct node*));
	temp = top;
	while(temp != NULL){
		printf("stack : %d \n",temp->data);
		temp = temp -> next;
	}
}


int main(){
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	pop();
	print_stack();
	get_top();
}
