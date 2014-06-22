/*****************************************************************************
* Process_Queue.cpp
* Process Queue Source Code
******************************************************************************/

#include "Process_Queue.h"

/**********************************************************
* Process Queue Default Constructor
*	Setup an empty queue using the default constructor for
*	the Process data type for the Process variable 'p'
**********************************************************/
Process_Queue::Process_Queue(){
	current = NULL;
	first = NULL;
	last = NULL;
	pQueueSize = 0;
}

/**********************************************************
* Process Queue Overloaded Constructor for user
**********************************************************/
Process_Queue::Process_Queue(Process_Node &inPN){
	current = new Process_Node(inPN);
	first = current;
	last = current;
	pQueueSize = 1;
}

/**********************************************************
* Process Queue Copy Constructor
**********************************************************/
Process_Queue::Process_Queue(const Process_Queue &inPQ){
	current = new Process_Node();
	*current = *inPQ.current;
	first = new Process_Node();
	*first = *inPQ.first;
	last = new Process_Node();
	*last = *inPQ.last;
	pQueueSize = inPQ.pQueueSize;
}

/**********************************************************
* Process Queue Assignment Operator
**********************************************************/
Process_Queue &Process_Queue::operator=(const Process_Queue &inPQ){
	current = inPQ.current;
	first = inPQ.first;
	last = inPQ.last;
	pQueueSize = inPQ.pQueueSize;
	return *this;
}

/**********************************************************
* Process Queue Destructor
**********************************************************/
Process_Queue::~Process_Queue(void){
	delete[] current;
	delete[] first;
	delete[] last;
}

/**********************************************************
* Process Queue Pop
*   Pop the data off the front of the queue and return the
*   data to the user
**********************************************************/
Process_Node Process_Queue::pop(void){
	Process_Node pNode = *first;
	return pNode;
}

/**********************************************************
* Process Queue Read
*   Get the process from the front of the queue without
*   removing it from the queue. This doubles as a
*   'getFirst()' function
**********************************************************/
Process_Node Process_Queue::read(void){
	return *first;
}

///**********************************************************
// * Process Queue Push
// *   Push a process to the end of the queue
// **********************************************************/
//void Process_Queue::push(const Process_Node &inPN){
////	if (isEmpty){
////		first = inPN;
////		first->setNext(NULL);
////		first->setPrevious(NULL);
////		*current = *first;
////		*last = *first;
////	}
////	else if (!isEmpty && pQueueSize > 1){
////		last->setNext(inPN);
////		inPN->setPrevious(last);
////		inPN->setNext(NULL);
////		*last = &inPN;
////	}
////	else if (!isEmpty && pQueueSize == 1) {
////
////	}
//}
//
///**********************************************************
// * Process Queue Get Next
// *   Get the next process in the queue
// **********************************************************/
//Process_Node Process_Queue::getNext(void){
//	return this->next;
//}
//
///**********************************************************
// * Process Queue Get Last
// *   Get the lass process in the queue
// **********************************************************/
//Process_Node Process_Queue::getLast(void){
//
//}
//
///**********************************************************
// * Process Queue Get Process Queue Size
// *   Return the size of the process queue
// **********************************************************/
//int Process_Queue::getPQueueSize(void){
//
//}
//
///**********************************************************
// * Process Queue is Empty
// *   Return whether or not the queue is empty
// **********************************************************/
//bool Process_Queue::isEmpty(void){
//
//}
//
///**********************************************************
//* Process Queue test Process Queue Size
//*	 Test the size of the Process Queue
//**********************************************************/
//bool Process_Queue::testPQueueSize(void){
//
//}
//
///**********************************************************
// * Process Queue fix Process Queue Size
// *	 In the case that the queue size is wrong then fix
// *		the size. This will be invoked by the function is
// *		isEmpty() ONLY.
// **********************************************************/
//void Process_Queue::fixPQueueSize(void){
//
//}
