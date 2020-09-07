#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head;
void printlist(struct node* n){
	while(n!=NULL){
		printf("%d \n",n->data);
		n = n -> next;
	}
}

void insert(struct node **ref, int data){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = data;
	temp -> next = *ref;
	*ref = temp;
}

void insert_position(int data,int position){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node)); // node to be inserted
	temp -> data = data; // data assignment to the node
	temp -> next = NULL;
	if(position == 1){ // if there is only head node or there isnt any node
		temp -> next = head;
		
		return;
	}
	struct node* temp2 = head;
	for(int i = 0; i < position-2; i++){
		temp2 = temp2 -> next;

	}
	temp -> next = temp2->next;
	temp2->next = temp;

}

int main(){
	struct node* second;
	int x;
	head = NULL;
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));

	head -> data = 5;
	head -> next = second;

	second -> data = 10;
	second -> next = NULL;

	printf("enter the data to be inserted : ");
	scanf("%d",&x);
	insert(&head,x);
	insert_position(125,2);
	insert_position(150,3);
	printlist(head);
}
