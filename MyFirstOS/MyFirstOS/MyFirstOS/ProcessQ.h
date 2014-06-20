/*****************************************************************************
* ProcessQ.h
* Process Queue
******************************************************************************/
#pragma once

#include <iostream>
#include "stdio.h"
#include "Process.h" // I need to have access to the Process.h file so I can
                     // see the API

class Process_Queue {
public:

	// Constructors & Destructors
	Process_Queue(void); // Default Constructor
	Process_Queue(const Process &inP); // Overloaded Constructor for user
	Process_Queue(const Process_Queue &inPQ); // Copy Constructor
	Process_Queue & operator=(const Process_Queue &inPQ); // Assignment Operator
	~Process_Queue(void); // Destructor

	// Getters
	Process pop(void); // Pop the data off the front of the queue and return
	                   // data to user
	Process read(void); // Get the Process from the front of the queue without
						// removing it from the queue

	// Other Queue Functions
	void push(const Process &inP); // push a process to the end of the queue

protected:

	// Getters
	Process getNext(void); // get next process in queue
	Process getLast(void); // get last process in queue
	int     getPQueueSize(void); // get the size of the queue

	// Others
	bool isEmpty(void); // get whether or not the queue is empty

private:
	Process  p;
	Process *first;
	Process *next;
	Process *last;
	bool     empty;
	int      pQueueSize;
};

