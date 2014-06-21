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
	Process(int _ID, int _mode, int _priority, int _procTime);

	//--------------------------accessor member functions-----------------------
	//return object's ID#
	int getID();
	//return object's mode
	int getMode();
	//return object's priority
	int getPriority();
	//return object's processing time
	int getProcTime();

	//--------------------------print member functions-----------------------
	void printID();
	void printMode();
	void printPriority();
	void printProcTime();
	void printAll();
	void run();

private:
	int ID;
	int mode;
	int priority;
	int procTime;
};

#endif //PROCESS_H