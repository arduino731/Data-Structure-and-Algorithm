/*
Author: Brian van Vlymen
Assignment Number: Lab Assignment "Lab 1 part A"
File Name: BrianVanVlymenLab1.zip
Course/Section: CS 2123 Section OC1
Due Date: 9/21/2020
Instructor: Ku, B
*/

#include <stdio.h>

// function prototype
double power(double a,int n);  

int main(void) {
    // read input data
    printf("for 2,  3 = %lf\n", power(2,4));
    printf("for 2, -4 = %lf\n", power(2,-4));
	return 0;
}

// function definition
double power(double a, int n) { 
    if ( n == 0){
        return 1;
    }else if (n > 0){
        return a * power(a , n-1);
    }else{
        return 1 / a * power(a, n+ 1);
    }

}

