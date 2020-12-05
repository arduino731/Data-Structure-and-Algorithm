#include <stdio.h>


// using namespace std;

int main(){

    // int a=10;
    // int *p;
    // p=&a;
    // printf("using pointer %d %d", *p, &a);

    int a[5]={1,2,3,4,5};
    int *p;
    // p=&a[0]; // if you want to use ampersand then you should said zero of array and address assign to the pointer of p
    // p=&a; // this is invaild syntax and compiler will not give you any warning so you will not get proper results

    p=a;
    for (int i = 0; i < 5; i++)
    {
        printf("%d \n", a[i]);
    }

    int *t;
    t=(int *)malloc(5*sizeof(int)); //we can assign a tree created in the hemp
    // t[0]=10;
    // t[1]=15;
    // t[2]=18;
    // t[3]=19;
    // t[4]=55;

    // t =new int[5];    // c++ 
    // delete [ ] t; // using C++ language, whenever you are dynamically allocalling memory, you must release the memory when you finished
    free(t); // using C language , this is for dislocating the memory that is allocated in a heap
    return 0;
}