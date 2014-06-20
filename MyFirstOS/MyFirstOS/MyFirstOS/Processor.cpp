#include "stdafx.h"
#include "Processor.h"
#include <Windows.h>
#include <iostream>

using namespace std;

Processor::Processor(){

}


Processor::~Processor(){

}

void Processor::run(Process& p, Scheduler& s){

	cout << "Received Process " << p->get_ID() << "with priority "<< p->get_Priority <<endl;
	
	//tell the processor about it's current process
	set_Cur_Proc_Priority(p->getPriority);
	set_Cur_Proc_ID(p->getID);

	//running the process
	p->execute();
	set_Status_Idle();

	//Notify the scheduler that the cpu is done with the current Process???
	cout << "Waiting for new Processes." << endl;
	s->cpu_Idle(p); 
}
/* Not sure if we going to need this now.
void Processor::timer(){
	if (get_Cur_Proc_Priority() == 0){
		cout << "highest Priority of 0 so 20seconds of processing time" << endl;
		Sleep(20000);
		cout << "Time up for Process: " << get_Cur_Proc_ID() << endl;
	}
	else if (get_Cur_Proc_Priority() == 1){
		cout << "Priority of 1, so 15 seconds of processing time" << endl;
		Sleep(15000);
		cout << "Time up for Process: " << get_Cur_Proc_ID() << endl;
	}
	else if (get_Cur_Proc_Priority() == 2){
		cout << "Priority of 2, so 10 seconds of processing time" << endl;
		Sleep(10000);
		cout << "Time up for Process: " << get_Cur_Proc_ID() << endl;
	}
	else if (get_Cur_Proc_Priority() == 3){
		cout << "Lowest Priority of 3, so 5 second of processing time" << endl;
		Sleep(5000);
		cout << "Time up for Process: " << get_Cur_Proc_ID() << endl;
	}
	else{
		cout << "No Process, Processor at idle." << endl;
	}
}
*/
int Processor::get_Cur_Proc_Priority(){
	return curProcPriority;
}

int Processor::get_Cur_Proc_ID(){
	return curProcID;
}

bool Processor::get_Status(){
	return status;
}

void Processor::set_Cur_Proc_Priority(int p){
	curProcPriority = p;
}

void Processor::set_Cur_Proc_ID(int id){
	curProcID = id;
}

void Processor::set_Status_Running(){
	status = true;
}
void Processor::set_Status_Idle(){
	status = false;
}
