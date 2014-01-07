/*
	Stack.cc
	This file contains all of the function definitions for the Stack class
	This implementation uses a list as a stack
	
	Functions:
	Title			Description
	----------------------------
	Stack			Basic constructor
*/

/*--Includes*/

#include "Stack.h"

using namespace std;

Stack::Stack() 
{
	this-> elements = list<int>();  // represent empty stack with empty list
}

Stack::Stack(int n, Stack s)
{
	this-> elements = list<int>(n, s.elements);
}

int Stack::top()
{
	return ::head(this-> elements);  // call the list 'head' function; not a recursive call
}

bool Stack::empty()
{
	return ::empty(this-> elements);
}

int Stack::size()
{
	return ::length(this-> elements);
}

int &Stack::pop()
{
	//precondition(not empty());
    int* my_top;
    my_top = new int;
	*my_top=this-> top();
	this-> elements = rest(this->elements);
	return *my_top;
}

Stack &Stack::push(int item) // what do "&" and "*" mean???
{
	this->elements = list<int>(item, this->elements);
	return *this;
}

