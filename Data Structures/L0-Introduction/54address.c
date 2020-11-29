// Address.c 
#include <stdio.h>

int main(void) {    
	int a = 255;
	int *b = &a; 		// declaring an int pointer and assign the address to the b pointer or initialising b

	printf("a = %d\n", a);		// 255
	printf("&a = %p\n\n", &a); // 0061FF1C

	printf("b = %p\n", b); 		// 0061FF1C 
	printf("*b with d = %d\n", *b); 	// 255
	printf("*b with p = %p\n", *b); 	// 000000FF
	printf("&b = %p\n", &b); 	// 0061FF18

	return 0;
}

