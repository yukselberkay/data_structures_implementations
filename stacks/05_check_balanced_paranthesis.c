// last unclosed should be first closed.


// scan from left to right if opening symbol add it to a list if closing symbol remove last opening symbol in list.

#include <stdio.h>
#define MAX_SIZE 101

char str[] = "[[()]]";
char stack[MAX_SIZE];
int top = -1;

void push(char x){
	top++;
	stack[top] = x;
}

void pop(){
	top--;
}
	

int check_paranthesis(char strr[]){
	for(int i = 0; i < sizeof(str) - 1 ; i++){
		if(strr[i] == '[' || strr[i] == '('){
			push(strr[i]);
			
		}
		if(strr[i] == ']' || strr[i] == ')'){
			pop();
		}

	}

	// if stack is empty paranthesis are balanced if not not balanced.
	if (top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){

	if (check_paranthesis(str) == 1){
		printf("balanced");
	}
	else{
		printf("not balanced");
	}
}
