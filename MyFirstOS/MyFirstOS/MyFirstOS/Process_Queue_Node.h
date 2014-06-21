#include <iostream>
#include "stdio.h"
#include "Process.h"

class Process_Node {
public:
	Process_Node(void){ 
		p = new Process();
		previous = NULL;
		next = NULL;
	};
	Process_Node(const Process &inP) {
		p = inP;
		previous = NULL;
		next = NULL;
	};
	~Process_Node(void) {
		delete p;
		delete []previous;
		delete []next;
	};

	Process_Node getNext(void) { return next; };
	Process_Node getPrevious(void) { return previous; };
	Process_Node setNext(const Process_Node &inPN) { next = inPN; };
	Process_Node setPrevious(const Process_Node &inPN) { previous = inPN; };

private:
	Process p;
	Process_Node *previous;
	Process_Node *next;
};