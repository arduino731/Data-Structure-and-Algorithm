// Address.c 
#include <stdio.h>

int main(void) {    
	int i =10;
    int j =20;
    int k =50;
    int *p_ptr = &i; // first assign 10 address

    printf("p_ptr = %d\n", i);
    printf("p_ptr = %d\n", *p_ptr);
    *p_ptr = *p_ptr + 2; 
    p_ptr = &j; // reassign 20 address
     
    printf("p_ptr = %d\n", *p_ptr);
    p_ptr = &k;
    *p_ptr = *p_ptr +10;
    printf("p_ptr = %d\n", *p_ptr);
    *p_ptr = i;
    printf("p_ptr = %d\n", *p_ptr);


}

