#include <stdio.h>

struct Rectangle {
    int length;
    int breadth;
};


void  initialize(struct Rectangle *r, int l, int b){
    r->length = l;
    r->breadth = b;
}

int area(struct Rectangle r){ // its own copy by value 
    int totalArea = r.length * r.breadth;
    printf("%d\n", totalArea);
    return totalArea;
}

void changeLength(struct Rectangle *r, int l){ // this is actually change the length 20 from 10
    r->length =l;
}




int main (){
    struct Rectangle r;

    initialize(&r, 10, 5);
    area(r);
    changeLength(&r, 5);
    area(r);
}