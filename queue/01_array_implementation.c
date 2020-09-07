#include <stdio.h>
#define MAX_SIZE 101

int queue[MAX_SIZE];

// allocate 30 blocks of integer to be used in queue
int rear = 29;
int front = 0;

void enq(int x){
	rear++;
	queue[rear] = x;
	
}

void deq(){
	front++;
}

void get_front(){
	printf("%d\n", queue[front]);
}

int is_empty(){
	if(rear == front){return 1;}
	else{return 0;}
}

void print_queue(){
	for(int i = front; i <= rear; i++){
		printf("%d",queue[i]);
	}
	printf("\n");
}

int main(){
	enq(5);
	enq(6);
	enq(7);
	print_queue();
}
