/*
	Stack header file
*/

#ifndef __STACK_H_INCLUDED__  
#define __STACK_H_INCLUDED__   

#include "hc_list.h"
#include "hc_list_helpers.h"
#include <iostream>

class Stack{ 
public:
		Stack();
		Stack(int n, Stack s);

		// accessors
		int top();
		// Stack after_pop();
		bool empty();
		int size();

		// Some mutators
		int    &pop(); // modifies "this"
		Stack &push(int item); // modifies *and*returns* "this"

private:
		list<int> elements;
};

#endif 
