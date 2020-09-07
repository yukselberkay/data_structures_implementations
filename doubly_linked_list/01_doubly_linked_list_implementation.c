#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
	struct node* prev;
};

struct node* head;


void printlist(struct node* n){
	while(n != NULL){
		printf("%d\n",n->data);
		n = n->next;
	}
}

void reverse_print(struct node* temp){
	if(temp == NULL) return; // if the list is empty exit.
	//goto last node
	while(temp->next != NULL){
		temp = temp -> next;
	}

	// traverse backward using prev pointer
	printf("reverse : \n");
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp = temp -> prev;
	}
}

struct node* create_node(int data){
	struct node* new_node; 
	new_node = (struct node*)malloc(sizeof(struct node));

	new_node -> data = data;
	new_node -> prev = NULL;
	new_node -> next = NULL;

	return new_node;
}

void insert_at_head(int x){
	struct node* temp;
	temp = create_node(x);
	if(head == NULL){ // if the list is empty 
		head = temp;
		return;
	}
	
	head -> prev = temp;
	temp -> next = head;
	head = temp;
}

void insert_at_tail(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));


	temp = head;


	while(temp->next != NULL){
		temp = temp -> next;
	}
	temp -> data = data;


}
	
	
int main(){
	int data1,data2,data3;
	struct node* second;
	struct node* third;
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));



	insert_at_head(5);
	insert_at_head(7);
	insert_at_head(9);

	printf("data to be inserted at head : ");
	scanf("%d",&data1);
	insert_at_head(data1);

	printf("second data to be inserted at head :");
	scanf("%d",&data2);
	insert_at_head(data2);

	printf("third data to be inserted at tail : ");
	scanf("%d",&data3);
	insert_at_tail(data3);

	printlist(head);
	reverse_print(head);

}
