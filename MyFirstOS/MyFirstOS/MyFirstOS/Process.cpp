#include <iostream>
#include <stdlib.h>
#include "windows.h"
#include "Process.h"


Process::Process(){
	ID = rand();
	mode = 1;
	priority = 1;
	procTime = 3;
	complete = false;
}


Process::Process(int _ID, int _mode, int _priority, int _procTime, bool _complete){
	ID = _ID;
	mode = _mode;
	priority = _priority;
	procTime = _procTime;
	complete = _complete;
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

bool Process::isComplete(){
	return complete;
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

void Process::printStatus() {
	if (complete){
		std::cout << "Process status: complete" << std::endl;
	}
	else
		std::cout << "Process status: pending" << std::endl;
}

void Process::printAll() {
	printID();
	std::cout << " "; 
	printMode(); 
	std::cout << " "; 
	printPriority();  
	std::cout << " "; 
	printProcTime();
	std::cout << " ";
	printStatus();
	std::cout << " " << std::endl;
}

void Process::run(){
	std::cout << "\nProcessing";
	for (int i = 0; i < procTime; i++){
		std::cout << ".";
		Sleep(500);
	}
	std::cout << "\nProcess completed\n\n";
	complete = true;
}

bool Process::operator<(const Process& second)
{
	if (mode < second.mode)
		return true;
	else if (mode == second.mode)
	{
		if (priority < second.priority)
			return true;
		else if (priority == second.priority)
		{
			if (procTime < second.procTime)
				return true;
			else if (procTime == second.procTime)
			{
				if (complete == false && second.complete == true)
					return true;
				else if (complete == second.complete)
				{
					if (min < second.min)
						return true;
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool Process::operator<=(const Process& second)
{
	if (mode <= second.mode)
	{
		if (priority <= second.priority)
		{
			if (procTime <= second.procTime)
			{
				if (complete <= second.complete)
				{
					if (min <= second.min)
						return true;
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool Process::operator>(const Process& second){
	if (mode > second.mode)
		return true;
	else if (mode == second.mode)
	{
		if (priority > second.priority)
			return true;
		else if (priority == second.priority)
		{
			if (procTime > second.procTime)
				return true;
			else if (procTime == second.procTime)
			{
				if (complete > second.complete)
					return true;
				else if (complete == second.complete)
				{
					if (min > second.min)
						return true;
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool Process::operator>=(const Process& second)
{
	if (mode >= second.mode)
	{
		if (priority >= second.priority)
		{
			if (procTime >= second.procTime)
			{
				if (complete >= second.complete)
				{
					if (min >= second.min)
						return true;
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool Process::operator==(const Process& second)
{
	if (mode == second.mode)
	{
		if (priority == second.priority)
		{
			if (procTime == second.procTime)
			{
				if (complete == second.complete)
				{
					if (min == second.min)
						return true;
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool Process::operator!=(const Process& second)
{
	if (mode != second.mode)
		return true;
	else if (priority != second.priority)
		return true;
	else if (procTime != second.procTime)
		return true;
	else if (complete != second.complete)
		return true;
	else if (min != second.min)
		return true;
	else
		return false;
}
