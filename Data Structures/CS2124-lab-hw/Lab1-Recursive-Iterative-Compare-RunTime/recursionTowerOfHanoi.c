/*
Author: Brian van Vlymen
Assignment Number: Lab Assignment "Lab 1 part B"
File Name: BrianVanVlymenLab1.zip
Course/Section: CS 2123 Section OC1
Due Date: 9/21/2020
Instructor: Ku, B
*/

#include <stdio.h> 
  
// C recursive function to solve tower of hanoi puzzle 
void recTowerOfHanoi(int n, char start, char end, char aux_rod) 
{ 
    if (n == 1) 
    { 
        printf("\n Move disk 1 from rod %c to rod %c", start, end); 
        return; 
    } 
    recTowerOfHanoi(n-1, start, aux_rod, end); 
    printf("\n Move disk %d from rod %c to rod %c", n, start, end); 
    recTowerOfHanoi(n-1, aux_rod, end, start); 
} 
  
int main() 
{ 
    int n = 4   ; // Number of disks 
    recTowerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods 
    return 0; 
}
