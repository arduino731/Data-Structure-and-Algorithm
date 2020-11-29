/*
Author: Brian van Vlymen
Assignment Number: HW Assignment "3"
File Name: BrianVanVlymenHW1.zip
Course/Section: CS 2123 Section OC1
Due Date: 9/25/2020
Instructor: Ku, B
*/
#include <stdio.h> 
int howManyInstruction1(int n){
    int sum = 0;
    // int number;
    
    int values[n] ;

    while (n > 3 && n < 10){
        sum += values[n];
        n++;
        printf("%d\n", n);
    }
    return sum;
}

int bar(int n) {
    if( n < 0 )
        return -4;
    else
        printf("%d\n", n);
      return (2 + bar(n-1) + bar(n-2));
}

int fMystery (int a){
    if(a==0){
        return 0;
    }else{
        return fMystery(a-1) + 2 * a-1;
    }
}
// The main program calls fun() and measures time taken by fun() 
int main() 
{ 
    int enterNumber;
    printf("Enter the number: ");
    scanf("%d\n", &enterNumber);
    fMystery(enterNumber);
    // howManyInstruction1(enterNumber);
    
    int sum = 0;
    int n = 4;
    for (int i=0; i < n; i++ ) {
        for (int j=0; j < n; j++ ) {
            sum += i * j;
            
        }
    }
    printf("%d\n", sum);

    return 0; 
}