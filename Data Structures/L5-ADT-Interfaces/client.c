#include <stdio.h>
#include "random.h"

void playHiLo( int s);     /* prototype */


void playHiLo(int s)
{
    int i, guess;
    
    for(i=1; i <=6; i++){
        printf("Enter your guess : ");
        scanf("%d", &guess);
        if (guess > s)
            printf("It is Higher than secret\n");
        else if (guess < s)
            printf("It is Lower than secret\n");
        else {
            printf("Cong! you won\n");
            return;
        }
    }
    printf("Sorry! Try again\n");
    return;
}

int main(void)
{
    int secret;            /*  Declare variables */
    
    Randomize();
    
    while(1){
        secret = RandomInteger(1,100);
        playHiLo(secret);
    }
    return 0;
}