/*
	main.cc
	This file contains the main function for the Stack class and text interface.
	To disallow running either the tests or the interface, 
	change the RUN_STACK_TESTS or RUN_STACK_INTERFACE variable from 1 to 0
*/

/*-----------Includes---------*/
#include "Stack.h"
#include "Stack_test.h"
#include "Stack_interface.h"

/*----------Constants---------*/
#define RUN_STACK_TESTS			1
#define RUN_STACK_INTERFACE		1


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
	Start_stack_interface();
	#endif
	cout<<"That's all folks!"<<endl;
	return 0;
}
