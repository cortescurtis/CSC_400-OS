/*****************************************************************************
* Process_Queue.h
* Process Queue
******************************************************************************/
#pragma once

#include "Process_Queue_Node.h"

class Process_Queue {
public:

	// Constructors & Destructors
	Process_Queue(void);                            // Default Constructor
	Process_Queue(Process_Node &inPN);              // Overloaded Constructor
	// for user
	Process_Queue(const Process_Queue &inPQ);             // Copy Constructor
	Process_Queue & operator=(const Process_Queue &inPQ); // Assignment Operator
	~Process_Queue(void);                                 // Destructor

	// Getters
	Process_Node pop(void);  // Pop the data off the front of the queue and return
	// data to user
	Process_Node read(void); // Get the Process from the front of the queue without
	// removing it from the queue

	// Other Queue Functions
	void push(const Process_Node &inPN); // push a process to the end of the queue

protected:

	// Getters
	Process_Node getCurrent(void);    // get current process in queue
	Process_Node getNext(void);       // get next process in queue
	Process_Node getLast(void);       // get last process in queue
	int          getPQueueSize(void); // get the size of the queue

	// Others
	bool isEmpty(void);        // get whether or not the queue is empty
	bool testPQueueSize(void); // Test to make sure the size of the queue is correct
	void fixPQueueSize(void);  // Fix the queue size if not correct

private:
	Process_Node *current; // Used for iterations and holding the current position of
	Process_Node *first;   // Used for holding ythe place of the first node in the list
	Process_Node *last;    // Used for holding the lplace of the last node in the list
	int pQueueSize;        // holds the total size of the queue, this is tho help keep
	// from errors
};