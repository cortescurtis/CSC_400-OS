#pragma once
#include <iostream>
#include "Process.h"
#include "Process_Queue.h"
#include "Scheduler.h"

class Processor
{
public:
	Processor();
	~Processor();
	//for accepting processes and running them
	void run(Process& p, Scheduler& s); 
	//Opperation functions
	//void timer();

	//Getter functions
	int get_Cur_Proc_Priority();
	int get_Cur_Proc_ID();
	bool get_Status();

	//Setter functions
	void set_Cur_Proc_Priority(int p);
	void set_Cur_Proc_ID(int id);
	void set_Status_Running();
	void set_Status_Idle();


private:
	int curProcPriority;
	int curProcID;
	//status is set to true processor is running
	//status is set to false processor is idle 
	bool status;

};

