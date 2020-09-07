#include <stdio.h>
#include <stdlib.h>

struct foo{
	int x;
	int y;
};

int main(){
	struct foo var;
	struct foo* pvar;
	pvar = malloc(sizeof(pvar)); // allocate memory with the size of struct foo

	var.x = 5;
	(*pvar).x = 6;

	printf("%d", pvar->x);
}
