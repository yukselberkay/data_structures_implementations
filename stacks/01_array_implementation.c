#include <stdio.h>

#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1; // this means an empty stack

void push(int x){
	if(top == MAX_SIZE -1){
		printf("stack overflow.\n");
		return;
	}

	top++;
	A[top] = x;
}

void pop(){
	if(top == -1){
		printf("no element to pop.\n");
		return;
	}
	top--;
}

int get_top(){
	return A[top];
}

void printstack(){
	for(int i = 0 ; i<=top; i++){
		printf("%d \n",A[i]);
	}
	
}

int main(){
	int x;
	printf("enter a integer to push : ");
	scanf("%d",&x);

	push(x);
	push(12);
	push(15);
	printf("top :%d\n",get_top());
	push(20);
	pop();
	push(18);
	printf("top %d\n",get_top());

	printstack();

}

