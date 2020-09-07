#include <stdio.h>
#include <stdlib.h>

struct node{
	char data;
	struct node* next;
};

struct node* top = NULL;


void push(char x){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
//	printf("push");
	temp -> data = x;
	temp -> next = top;
	// top is just a address holder/pointer for the first node.
	top = temp;
}

void pop(){
	struct node* temp;
	if(top == NULL) return;

	temp = top;
	// break the link between the next node and point top to next next node.
	
	while(temp != NULL){
		printf("%c",temp->data);
		temp = temp -> next;
	}
	free(temp);
}


int main(){
	char str[] = "berkay";
	printf("original string : %s\n",str);

	for(int i = 0 ; i < sizeof(str) - 1; i++){
		push(str[i]);
	}

	pop();
	printf("\n");


	
}
