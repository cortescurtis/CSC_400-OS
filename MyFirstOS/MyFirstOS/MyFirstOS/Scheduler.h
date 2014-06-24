#include <iostream>

using namespace std;

class Scheduler
{


public:
	Scheduler ();

	// Get the No of proces 
	void getdata();
	// First come first served
	void fcfs();
	// Shortest job
	void sjf();
	// Round Robin
	void roundrobin();
	// Priority
	void priority();
	
};

