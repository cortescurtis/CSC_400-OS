// MyFirstOS.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include "Processor.h"
#include "Process_Queue.h"
#include "Process.h"
#include "process_Queue_Node.h"

using namespace std;

void Bootstrap()
{
	//initialize Processor
	//jump_start 
}

int main()
{
	bool more = true;
	int input;
	int quit = 2;

	while (more){
		cout <<"Please Select form the following menu:"<<endl<<
			"1. Start Simulation."<<endl<<
			"2. Quit."<<endl;
		cin>> input;

		if(input == quit)
			more = false;

		else {
			Bootstrap();
		}

	return 0;
}

