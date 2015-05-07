/*
	main.cc
    Allison Lake, for CMSC245 at Haverford College, Fall 2013
	This file contains the main function for the Stack class and text interface.
	To disallow running either the tests or the interface, 
	change the RUN_STACK_TESTS or RUN_STACK_INTERFACE variable from 1 to 0
*/

/*-----------Includes---------*/
#include "Stack.h"
#include "Stack_test.h"
#include "Stack_interface.h"
#include <fstream>

/*----------Constants---------*/
#define RUN_STACK_TESTS			1
#define RUN_STACK_INTERFACE		1


void run_file(char* file_name) {
    ifstream in(file_name, std::ifstream::in);
    string token;

    while (token != "end") {
		in >> token;
		cout<< token<<endl;
	}
    in.close();
}


int main ()
{
	bool passed_tests;
	#if RUN_STACK_TESTS
	passed_tests = Stack_test();
	if (!passed_tests) {
		cout << "Something went wrong in the stack unit tests." << endl;
	}
	#endif
	#if RUN_STACK_INTERFACE
	cout << "Type some FORTH input:" << endl;
	cli("file.ft");
	Start_stack_interface();
	#endif
	cout<<"That's all folks!"<<endl;
	return 0;
}
