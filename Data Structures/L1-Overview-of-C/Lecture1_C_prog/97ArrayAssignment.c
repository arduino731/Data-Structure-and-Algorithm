// ArrayAssignment.c
#include <stdio.h>
#define N 10

int main(void) {
	int source[N] = { 10, 20 , 30 ,40, 50 };
	int dest[N];

	int i;
	for (i = 0; i < N; i++) {
		printf("%d ", source[i]);
	}
	printf("\n");

	for (i = 0; i < N; i++)
	{
		dest[i] = source[i];
		printf("%d ", dest[i]);
	}
	
	// dest = source; ILLEGAL!!!

	return 0;
}

