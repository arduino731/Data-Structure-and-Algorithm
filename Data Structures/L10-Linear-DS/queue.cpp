#include <iostream>
using namespace std;
#include "Queue.h"
Queue::Queue() {
	mySize = 0;
	first = NULL;
	last = NULL;	
}
void Queue::enqueue() {
	NodePointer nPtr = new Node(1);
	NodePointer predPtr = first;
	
	if (first == NULL) { //Insert if queue is empty
		nPtr->next = first;
		first = nPtr;
	} else { //Insert into the queue at the end
		while (predPtr->next) {
			predPtr = predPtr->next;
		}
		nPtr->next = predPtr->next;
	}
	mySize++;
	last = nPtr; //Set last to new pointer
}
void Queue::dequeue() {
	if (first) {
		NodePointer dPtr = first;
		first = first->next; //Set first to the second node in the list
		delete dPtr; //Delete the node that has been dequeued
	}
	mySize--;
}
ElementType Queue::front() {
	if (first) {
		NodePointer ptr = first;
		return ptr->data;
	}
}
int Queue::getSize() {
	return mySize;
}
Queue::~Queue() {
	if (first) {
		//Deallocate all nodes in queue
		NodePointer current = first;
		NodePointer temp = first;
		
		temp = current->next;
		delete current;
		current = temp;
	}
}