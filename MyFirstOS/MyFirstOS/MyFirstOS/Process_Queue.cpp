/*****************************************************************************
* ProcessQ.cpp
* Process Queue Source Code
******************************************************************************/

#include "ProcessQ.h"

/**********************************************************
 * Process Queue Default Constructor
 *	Setup an empty queue using the default constructor for
 *	the Process data type for the Process variable 'p'
 **********************************************************/
Process_Queue::Process_Queue(){
	pN = NULL;
	first = NULL;
	last = NULL;
	pQueueSize = 0;
};

/**********************************************************
 * Process Queue Overloaded Constructor for user
 **********************************************************/
Process_Queue::Process_Queue(const Process_Node &inPN){
	pN = inPN;
	pQueueSize = 1;
};

/**********************************************************
 * Process Queue Copy Constructor
 **********************************************************/
Process_Queue::Process_Queue(const Process_Queue &inPQ){
	this->p = inPQ->p;
	this->first
};

/**********************************************************
* Process Queue Assignment Operator
**********************************************************/
Process_Queue::Process_Queue & operator=(const Process_Queue &inPQ){

};

/**********************************************************
* Process Queue Destructor
**********************************************************/
Process_Queue::~Process_Queue(void){

};

/**********************************************************
* Process Queue Pop
*   Pop the data off the front of the queue and return the
*   data to the user
**********************************************************/
Process Process_Queue::pop(void){

};

/**********************************************************
* Process Queue Read
*   Get the process from the front of the queue without 
*   removing it from the queue. This doubles as a
*   'getFirst()' function
**********************************************************/
Process Process_Queue::read(void){

};

/**********************************************************
 * Process Queue Push
 *   Push a process to the end of the queue
 **********************************************************/
void Process_Queue::push(const Process_Node &inPN){

};

/**********************************************************
 * Process Queue Get Next
 *   Get the next process in the queue
 **********************************************************/
Process Process_Queue::getNext(void){

};

/**********************************************************
 * Process Queue Get Last
 *   Get the lass process in the queue
 **********************************************************/
Process Process_Queue::getLast(void){

};

/**********************************************************
 * Process Queue Get Process Queue Size
 *   Return the size of the process queue
 **********************************************************/
int Process_Queue::getPQueueSize(void){

};

/**********************************************************
 * Process Queue is Empty
 *   Return whether or not the queue is empty
 **********************************************************/
bool Process_Queue::isEmpty(void){

};

/**********************************************************
* Process Queue test Process Queue Size
*	 Test the size of the Process Queue
**********************************************************/
bool Process_Queue::testPQueueSize(void){

}

/**********************************************************
 * Process Queue fix Process Queue Size
 *	 In the case that the queue size is wrong then fix
 *		the size. This will be invoked by the function is
 *		isEmpty() ONLY.
 **********************************************************/
void Process_Queue::fixPQueueSize(void){

}