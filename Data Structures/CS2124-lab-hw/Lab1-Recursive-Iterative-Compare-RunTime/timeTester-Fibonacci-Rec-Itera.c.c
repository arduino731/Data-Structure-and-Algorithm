/*
Author: Brian van Vlymen
Assignment Number: Lab Assignment "Lab 1 part B"
File Name: BrianVanVlymenLab1.zip
Course/Section: CS 2123 Section OC1
Due Date: 9/21/2020
Instructor: Ku, B
*/
#include <stdio.h> 
#include <time.h>  

double fib(int n) { // function definition
    //First two fibonacci digits
    if ( n < 2){
        return n;
    }else{
        printf("call %d\n", n);
        return fib(n-1) + fib(n-2);
    }
}

void fibonacciIterative(int n)
{
        int prev = 0;
        int curr = 1;
        int temp;
        int i = 0;
        
        //First two fibonacci digits
        printf("0 1 ");
        //stop at n - 2
        for (i = 0; i < n - 2; i++)
        {
                temp = prev;
                prev = curr;
                curr = temp + curr;

                printf("%d ", curr);
        }

        printf("\n");
}

int main() 
{ 
    double time_taken;
    // Calculate the time taken by fun() 
    clock_t t; 
    t = clock(); 
    // for one million trials:
        // call your recursive function
        fib(25);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("recursive function took %f seconds to execute \n", time_taken); 

    t = clock(); 
    // for one million trials:
        // call your iterative function
        fibonacciIterative(25);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("iterative function took %f seconds to execute \n", time_taken); 


    return 0; 
}