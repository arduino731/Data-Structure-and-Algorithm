#include "stdio.h"

int numberOfElements(int A[], int count);

int main()
{
int A[] = { 7, 12, 32, 54, 65,-1 }; // Array declaration
int count=0; // count is 0
  
printf("The lenghth of array is %d\n", numberOfElements(A,count)); // calling function
return 0;
}

int numberOfElements(int A[], int count) // called function
{
if (A[count] == -1) // if array element is negative stop recursion
return 0;
  
return ( (numberOfElements(A,count+1))+1); // recursive calling to find number of elements
}
