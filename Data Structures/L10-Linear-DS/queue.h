#ifndef QUEUE
#define QUEUE
#include <iostream>
using namespace std; 
typedef int ElementType;
class Queue {
	
	public:
		
		//Default constructor
		Queue();
		
		//Add to the back of the queue
		void enqueue();
		
		//Remove from the front of the queue
		void dequeue();
	
		//Returns the front of the queue
		ElementType front();
		
		//Return size of the queue
		int getSize();
		
		//Destructor
		~Queue();
		
	private:
		
		class Node {
		
			public:
			
				ElementType data;
				Node *next;				 
				Node(ElementType i) { // Node constructor
					data = i;
					next = NULL;
				}
		}; //--- end of Node class
		
		typedef Node *NodePointer;
		
		Node *first;
		Node *last;
		int mySize;
		
}; //--- end of Queue class
#include "Queue.cpp"
#endif