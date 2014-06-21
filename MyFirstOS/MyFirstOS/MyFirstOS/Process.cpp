#include <iostream>
#include <stdlib.h>
#include "windows.h"
#include "Process.h"


Process::Process(){
	ID = rand();
	mode = 1;
	priority = 1;
	procTime = 3;
}


Process::Process(int _ID, int _mode, int _priority, int _procTime){
	ID = _ID;
	mode = _mode;
	priority = _priority;
	procTime = _procTime;
}

int Process::getID(){
	return ID;
}

int Process::getMode(){
	return mode;
}

int Process::getPriority(){
	return priority;
}

int Process::getProcTime(){
	return procTime;
}

//print functions
void Process::printID(){
	std::cout << "Process ID #: " << ID << std::endl;
}

void Process::printMode(){
	std::cout << "Mode: " << mode << std::endl;
}

void Process::printPriority() {
	std::cout << "Priority: " << priority << std::endl;
}


void Process::printProcTime() {
	std::cout << "Processing Time: " << procTime << std::endl;
}

void Process::printAll() {
	printID();
	std::cout << " "; 
	printMode(); 
	std::cout << " "; 
	printPriority();  
	std::cout << " "; 
	printProcTime();
	std::cout << " "  << std::endl; 
}

void Process::run(){
	std::cout << "\nProcessing";
	for (int i = 0; i < procTime; i++){
		std::cout << ".";
		Sleep(500);
	}
	std::cout << "\nProcess completed\n\n";
}

