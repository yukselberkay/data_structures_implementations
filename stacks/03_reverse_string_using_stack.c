#include <stdio.h>

#define MAX_SIZE 101
char stack[MAX_SIZE];
int top = -1;

void reverse_string(char str[], int len){
	for(int i = 0; i < len; i++){
		top++;
		stack[top] = str[i];
	}

	for(int j = 0; j < len ; j++){
		top--;
		printf("%c",stack[top]);
	}
	
	
	
}


int main(){
	printf("Enter a string : ");
	char str[] = "berkay"; 

	printf("original string is: %s\n",str);
	reverse_string(str, sizeof(str));
}
