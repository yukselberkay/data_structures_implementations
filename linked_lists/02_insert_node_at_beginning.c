#include <stdlib.h>
#include <stdio.h>

struct node{
	int item;
	struct node* next;
};

void insert(struct node ** ref, int data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> item = data;
	new_node -> next = (*ref);
}

void printlist(){
	struct node* traverse = (struct node*)malloc(sizeof(struct node));
	while(traverse != NULL){
		printf("%d\n",traverse->item);
		traverse = traverse -> next;
	}
}

int main(){
	struct node* head = NULL;
	insert(&head, 2);
	printlist();
}
