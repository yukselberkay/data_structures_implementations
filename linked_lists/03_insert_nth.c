#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node* head;
void insert(int data, int n){
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	temp1 -> data = data;
	temp1 -> next = NULL;
	if (n == 1){
		temp1 -> next = head;
		head = temp1;
		return;
	}
		
	struct node* temp2 = head;
	for(int i = 0; i < n-2 ; i++){
		temp2 = temp2 -> next;
	}
	temp1 -> next = temp2 -> next;
	temp2 -> next = temp1;
}

void printlist(){
	struct node* temp = head;
	while(temp != NULL){
		printf("%d ",temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}
int main(){
	head = NULL; // initially the list is empty.
	insert(2,1); // 2
	insert(3,2); // 2,3
	insert(4,1); // 4,2,3
	insert(5,2); // 4,5,2,3
	printlist();
}	
