/*****************************************************************************
* Process_Queue_Node.cpp
* Process Queue Source Code
******************************************************************************/
#include <iostream>
#include "stdio.h"

struct Process {
	int number;
	char aChar;
	bool tryIt;
};

/*******************************************************************
* Class Process Node
*	This class will handle each individual node so the Process Queue
*		does not have to worry about the implementation.
*******************************************************************/
class Process_Node {
public:
	// Default Constructor
	Process_Node(void){
		p = new Process();
		previous = NULL;
		next = NULL;
		printf("\The default constructor completed!\n");
	};
	// Overloaded Constructor
	Process_Node(const Process &inP) {
		p = inP;
		previous = NULL;
		next = NULL;
	};
	// Destructor
	~Process_Node(void) {
		delete[] previous;
		delete[] next;
	};

	// Return the value of the pointer 'next'
	Process_Node getNext(void) { return next; };
	// Return the value of the pointer 'previous'
	Process_Node getPrevious(void) { return previous; };
	// Set the value of the pointer 'next'
	Process_Node setNext(const Process_Node &inPN) { next = inPN; };
	// Set the value of the pointer 'pointer'
	Process_Node setPrevious(const Process_Node &inPN) { previous = inPN; };

private:
	Process p;              // Hold the value of 'Process'
	Process_Node *previous; // Point to the previous Process Node
	Process_Node *next;     // Point to the Next Process Node
};

int main(int argc, char[] argv){
	Process_Node defaultNode = new Process_Node();
	return 0;
}