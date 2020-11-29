#include <stdio.h> 
#include <time.h>  

int factorialRecursive(int n)
{
    // printf("hi\n");
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1);
}

int factorialIterative(int n)
{
    int sum = 1;
    if (n <= 1) return sum;
    while (n > 1)
    {
        sum *= n;
        n--;
    }
    return sum;
}
// The main program calls fun() and measures time taken by fun() 
int main() 
{ 
    double time_taken;
    // Calculate the time taken by fun() 
    clock_t t; 
    t = clock(); 
    // for one million trials:
        // call your recursive function
        factorialRecursive(100000);
    t = clock() - t; 
     time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("recursive function took %f seconds to execute \n", time_taken); 

    t = clock(); 
    // for one million trials:
        // call your iterative function
        factorialIterative(100000);
    t = clock() - t; 
     time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("iterative function took %f seconds to execute \n", time_taken); 


    return 0; 
}