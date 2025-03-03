#include <stdio.h>

int main(){
	void *p;

	char x = 'A';
	p = &x;

	printf("%ld", sizeof(p));
	return 0; 
}