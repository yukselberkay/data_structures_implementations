#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node* head;
struct node* void reverse(struct node* head){
	struct node *current,*temp,*prev;
	current = head;
	prev = NULL;
	while(current != NULL){
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
		
	}
	head = prev;
	return head;
}

int main(){
	struct node* head = NULL;
	head = insert(head,2);
	head = inser(head,4);
	printlist(head);
	head = reverse(head);
	printlist(head);
}
