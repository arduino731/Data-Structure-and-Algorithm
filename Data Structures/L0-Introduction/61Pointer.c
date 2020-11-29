// Pointer.c 
#include <stdio.h>

int main(void) {
	double a, *b;

	b = &a;

	*b = 12.34;
	printf("a: %f\n", a); 	// 12.450000
	printf("&b: %f\n", &b); // 12.450000
	printf("*b: %f\n", *b); // 12.450000
	printf("b: %f\n", b); 	// 12.339996
	// printf("*a: %f\n", *a); // error
	printf("b with p: %p\n", b); // to print a pointer of value hexdecimal

	return  0;
}

