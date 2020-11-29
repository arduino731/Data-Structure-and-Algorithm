/*
Author: Brian van vlymen
Assignment Number: Lab Assignment 4
File Name: driver.c
Course/Section: CS 2123 Section 00x
Due Date:
Instructor: Dr. Ku
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BST.h"


int getHeight(struct nodeT *H){
   int leftDepth,rightDepth;
  
   /* if NULL return height -1 */
   if(H==NULL){
       return -1;
   }
   else{
       leftDepth=getHeight(H->pLeft);
       rightDepth=getHeight(H->pRight);
      
       /* return maximum height */
       if(leftDepth > rightDepth){
           return(leftDepth+1);
       }else{
           return(rightDepth+1);
       }
   }
}

int getNumberOfNodes(struct nodeT *N){
    if(N == NULL){
        return 0;
    }else{
        return (getNumberOfNodes(N->pLeft) + 1 + getNumberOfNodes(N->pRight)); 
    }
}

int getNumberOfLeaves(struct nodeT *L){
    if(L == NULL){
        return 0;
    }
    if(L->pLeft == NULL && L->pRight == NULL){
        return 1;
    }else{
        return (getNumberOfLeaves(L->pLeft) + getNumberOfLeaves(L->pRight));
    }
}
/*
 *
 */
int main(int argc, char** argv) {
    nodeT *pRoot = NULL;        //root
    int data;                   //holds the int data
   
    //Insertion of new items, reports when done
    printf("BST is empty \n");
    printf("Height of BST is %d \n",getHeight(pRoot));
    printf("the number of nodes is %d \n",getNumberOfNodes(pRoot));
    printf("the number of leaves is %d \n",getNumberOfLeaves(pRoot));
    // the height is -1 
    printf("Items to insert (-999 to stop): ");
    scanf("%d", &data);
  
        
    while(data != -999){
        pRoot = insert(pRoot, data);
        printf("Height of BST is %d \n",getHeight(pRoot));
        printf("the number of nodes is %d \n",getNumberOfNodes(pRoot));
        printf("the number of leaves is %d \n",getNumberOfLeaves(pRoot));
        printf("Items to insert (-999 to stop): ");
        scanf("%d", &data);
        //expected outputs standard
        
    }
    report(pRoot);

    //deletion of items, reports after each deletion
    printf("Items to delete (-999 to stop): ");
    scanf("%d", &data);
    while(data != -999){
        pRoot = deleteNode(pRoot, data);
        report(pRoot);
        printf("Height of BST is %d \n",getHeight(pRoot));
        printf("the number of nodes is %d \n",getNumberOfNodes(pRoot));
        printf("the number of leaves is %d \n",getNumberOfLeaves(pRoot));
        printf("Items to delete (-999 to stop): ");
        scanf("%d", &data);
    }

    return 0;
}



