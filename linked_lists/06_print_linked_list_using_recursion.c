#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;

};

void printlist(struct node* p){
	if(p == NULL) return; // if there isnt any more nodes exit recursion.
	printf("%d",p -> data); // first print the value.
	printlist(p -> next);	// recursive call.
}
