// to delete go to n-1 node and point its address to n+1th node.
#include <stdio.h>
#include <stdlib.h>

void insert(int data);
void printlist();
void Delete(int n){
	struct node* temp1 = head;
	if (n == 1){
		head = temp1 -> next;
		free(temp1);
		return;
	}
	int i;
	for(i = 0; i<n-2 ;i++ ){ // goto n-1th node
		temp1 = temp1 -> next;
	}
	struct node* temp2 = temp1 -> next;
	temp1 -> next = temp2 -> next; // point to n+1th node
	free(temp2);
}
struct node{
	int data;
	struct node* next;
};
struct node* = head;

int main(){
	head = NULL;
	insert(2);
	insert(4);
	insert(6);
	insert(5);
	int n;
	printf("enter a position\n");
	scanf("%d",&n);
	Delete(n);
	printlist();
}

