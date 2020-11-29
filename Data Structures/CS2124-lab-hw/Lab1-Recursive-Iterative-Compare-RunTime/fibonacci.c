//Brian van vlymen

#include <stdio.h>

double fib(int n); // function prototype 

int main(void) {
    // read input data
    printf("for 6 fib = %lf\n", fib(5));    // t5
    // printf("for 5 fib = %lf\n", fib(6));    // t6
    // printf("for 10 fib =%lf\n", fib(10));   // t55
	return 0;
}

double fib(int n) { // function definition
    if ( n < 2){
        return n;
    }else{
        return fib(n-1) + fib(n-2); // 4 + 3 = 7 no 
    }

}