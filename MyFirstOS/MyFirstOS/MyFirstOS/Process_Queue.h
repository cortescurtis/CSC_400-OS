#ifndef PROCESSQUEUE_H_
#define PROCESSQUEUE_H_

/*****************************************************************************
* Process_Queue.h
* Process Queue
******************************************************************************/

#include "Process_Queue_Node.h"

class Process_Queue {
public:

	// Constructors & Destructors
	Process_Queue(void);                                  // Default Constructor
	Process_Queue(Process &inP);                          // Overloaded Constructor
		                                                  // for user
	Process_Queue(const Process_Queue &inPQ);             // Copy Constructor
	Process_Queue & operator=(const Process_Queue &inPQ); // Assignment Operator
	~Process_Queue(void);                                 // Destructor

	// Getters
	Process *pop(void);  // Pop the data off the front of the queue and return
		                 // data to user
	Process *read(void); // Get the Process from the front of the queue without
		                 // removing it from the queue

	// Other Queue Functions
	void push(Process &inP); // push a process to the end of the queue
	bool isEmpty(void);      // get whether or not the queue is empty

protected:

	// Getters
	Process_Node *getCurrent(void);   // get current process in queue
	Process_Node *getFirst(void);     // get first process in queue
	Process_Node *getLast(void);      // get last process in queue
	int          getPQueueSize(void); // get the size of the queue

	// Others


private:
	Process_Node *current; // Used for iterations and holding the current position of
	Process_Node *first;   // Used for holding the place of the first node in the list
	Process_Node *last;    // Used for holding the place of the last node in the list
	int pQueueSize;        // holds the total size of the queue, this is tho help keep
		                   // from errors

	// Private Functions
	bool testPQueueSize(void); // Test to make sure the size of the queue is correct
	void rebuildQueue(int direction); // Enter 0 for from beginning Enter 1 for from back
	int  countQueue(void); // iterate through the queue and count the nodes

	// Print Data
	void printQueueError(int errorCode); // Prints an error based on the code sent
	void printLine(const int MAX_LENGTH); // print a line of '-'s

};

#endif /* PROCESSQUEUE_H_ */