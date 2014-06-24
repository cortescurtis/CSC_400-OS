#ifndef PROCESS_H
#define PROCESS_H

class Process
{
public:
	//Default constructor: initializes Process object with a default mode, priority, and processing time
	Process();

	/**constructor with parameters;
	@param _mode user defined mode (system = 0, user = 1)
	@param _priority user defined attribute's priority (currently 1-10)
	@param _procTime user defined processing time
	**/
	Process(int _ID, int _mode, int _priority, int _procTime, bool _complete);

	//-----------------------accessor member functions-----------------------
	//return object's ID#
	int getID();
	//return object's mode
	int getMode();
	//return object's priority
	int getPriority();
	//return object's processing time
	int getProcTime();
	//return object's STATUS (true = finsihed / false = pending)
	bool isComplete();

	//--------------------------print member functions-----------------------
	void printID();
	void printMode();
	void printPriority();
	void printProcTime();
	void printStatus();
	void printAll();
	void run();

	//----------------------overloaded member functions----------------------

	/**
	These functions override the comparison operators.
	It compares the implied object's processing time variables w/ explicit object's processing time objects
	**/
	bool operator<(const Process& in);
	bool operator<=(const Process& in);
	bool operator>(const Process& in);
	bool operator>=(const Process& in);
	bool operator==(const Process& in);
	bool operator!=(const Process& in);


private:
	int ID;
	int mode;
	int priority;
	int procTime;
	bool complete;
};

#endif //PROCESS_H