//Brian van vlymen

#include <stdio.h>

int linearSearchIterative(int data [], int n, int target); // function prototype 
int binarySearchIterative(int data [], int n, int target); // function prototype 

int main(void) {
    // read input data
    printf("for 5 =%lf\n", linearSearchIterative(1, 20) );
    printf("for 10 =%lf\n", binarySearchIterative(1, 10) );
	return 0;
}



int linearSearchIterative(int data [], int n, int target) { // function definition
    for(int i=0;i<n;i++){
        if(data[i]==target){
            return i;
        }
        return -1;
    }
}

int binarySearchIterative(int data [], int n, int target){ // BSI
int low =0;
int high = n-1;
while(low <=high){
    int mid = (low + high)/ 2;
    if(data[mid] == target){
        return mid;
    }else if(data[mid] < target){
        low = mid + 1;
    }else{
        high = mid - 1;
    }
    return -1;  
}

}