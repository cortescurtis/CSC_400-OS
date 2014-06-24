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
Process_Queue::Process_Queue(Process &inP){
	Process_Node inPN = new Process_Node(inP);
	*current = inPN;
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
	*current = *first;
	while(current->getNext() != NULL){
		Process_Node *temp = current;
		current = current->getNext();
		delete[] temp;
	}

	delete[] current;
	delete[] first;
	delete[] last;
}

/**********************************************************
* Process Queue Pop
*   Pop the data off the front of the queue and return the
*   data to the user
**********************************************************/
Process *Process_Queue::pop(void){
	
	Process_Node *pNode = first;
	first = first->getNext();
	return pNode.getProcess();
}

/**********************************************************
* Process Queue Read
*   Get the process from the front of the queue without
*   removing it from the queue. This doubles as a
*   'getFirst()' function
**********************************************************/
Process *Process_Queue::read(void){
	return first->getProcess();
}

/**********************************************************
 * Process Queue Push
 *   Push a process to the end of the queue
 **********************************************************/
void Process_Queue::push(Process &inP){
	Process_Node inPN = Process_Node(inP);
	
	if (isEmpty()){
		*first = inPN;
		*current = inPN;
		*last = inPN;
	}
	else {
		inPN.setNext(*first);
		first->setPrevious(inPN);
		*first = inPN;
		current = first;
	}
	pQueueSize++;
}

/**********************************************************
 * Process Queue Get Current
 *   Get the first process in the queue
 **********************************************************/
Process_Node *Process_Queue::getCurrent(void){
	return current;
}

/**********************************************************
 * Process Queue Get First
 *   Get the first process in the queue
 **********************************************************/
Process_Node *Process_Queue::getFirst(void){
	return first;
}

/**********************************************************
 * Process Queue Get Last
 *   Get the lass process in the queue
 **********************************************************/
Process_Node *Process_Queue::getLast(void){
	return last;
}

/**********************************************************
 * Process Queue Get Process Queue Size
 *   Return the size of the process queue
 **********************************************************/
int Process_Queue::getPQueueSize(void){
	return pQueueSize;
}

/**********************************************************
 * Process Queue is Empty
 *   Return whether or not the queue is empty
 **********************************************************/
bool Process_Queue::isEmpty(void){
	bool empty = true;

	if (first == NULL && last == NULL){ // The queue is empty
		testPQueueSize();
		empty = true;
	}
	else if (first == NULL && last != NULL){
		printQueueError(1); // Alert the user there is an error
		rebuildQueue(1); // rebuild the queue from the back
						 // to find the front
		testPQueueSize();
		empty = false;
	}
	else if (first != NULL && last == NULL){
		printQueueError(0); // Alert the user there is an error
		rebuildQueue(0); // rebuild the queue from the front
						 // to find the back
		testPQueueSize();
		empty = false;
	}
	else if (first != NULL && last == NULL){
		testPQueueSize();
		empty = false;
	}

	return empty;
}

/**********************************************************
* Process Queue test Process Queue Size
*	 Test the size of the Process Queue
**********************************************************/
bool Process_Queue::testPQueueSize(void){
	bool sizeCorrectness = false;

	if(first == NULL && last == NULL){
		(pQueueSize == 0) ?
				sizeCorrectness = true : sizeCorrectness = false;
		if(!sizeCorrectness){
			pQueueSize = 0;
		}
	}
	else {
		int tempSize = countQueue();
		(pQueueSize == tempSize) ?
				sizeCorrectness = true : sizeCorrectness = false;
		if(!sizeCorrectness){
			pQueueSize = tempSize;
		}
	}

	return sizeCorrectness; // this should always return true
}

/**********************************************************
 * Process Queue Rebuild Queue
 *
 **********************************************************/
void Process_Queue::rebuildQueue(int direction){
	if(direction == 0){ // rebuild from the front
		current = last;
		while(current->getPrevious()!= NULL){
			current = current->getPrevious();
		}
		first = current;
	}
	else if(direction == 1){//rebuild from the back
		current = first;
		while(current->getNext() != NULL){
			current = current->getNext();
		}
		last = current;
	}
}

/**********************************************************
 * Process Queue Count Queue
 *
 **********************************************************/
int Process_Queue::countQueue(){
	int count = 0;
	*current = *first;

	(this->first != NULL) ? count++ : count = 0;

	while(current->getNext() != NULL && current != NULL){
		count++;
		current = current->getNext();
	}

	return count;
}

/**********************************************************
 * Process Queue Print Queue Error
 **********************************************************/
void Process_Queue::printQueueError(int errorCode){
	const int MAX_LENGTH = 60; // Max length of text before wrap
	char error[50] = "Queue structure failure, attempting rebuild";

	printLine(MAX_LENGTH);
	printf("ERROR %d: %s", errorCode, error);
	printLine(MAX_LENGTH);

}

/**********************************************************
 * Process Queue Print a Line of '-'s
 **********************************************************/
void Process_Queue::printLine(int MAX_LENGTH){
	printf("\n");
	for(int i = 0; i < MAX_LENGTH; i++){
		printf("-");
	}
	printf("\n");
}