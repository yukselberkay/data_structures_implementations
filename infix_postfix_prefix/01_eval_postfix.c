#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 101
char stack[MAX_SIZE];
int top = -1;

void push(int x){
	top++;
	stack[top] = x;
}

char pop(){
	return stack[top];
	top--;
}

int perform(char op2, char op1, char exp){
	op2 = (int)op2;
	op1 = (int)op1;

	if(exp == '*'){
		return op2 * op1;
	}
	else if(exp == '/'){
		return op2 / op1;
	}
	else if(exp == '+'){
		return op2 + op1;
	}
	else {
		return op2 - op1;
	}


}

void eva_post(char exp){
	int x = exp - '0';

	if(isdigit(x)){
		push(x);
		
	}
	else{
		char op2 = pop();
		char op1 = pop();
		int res = perform(op2, op1, exp);
		push(res);
		
	}
	
}

int main(){
	char y[] = "23*54*+9-";
	for(int i = 0; sizeof(y) - 1 ; i++){
		eva_post(y[i]);
	}
	printf("result : %c",stack[top]);
}
