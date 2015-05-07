/*
	Stack_interface header file
*/


#ifndef __STACK_INTERFACE_H_INCLUDED__   // if x.h hasn't been included yet...
#define __STACK_INTERFACE_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include "Stack.h"
#include <iostream>
#include <string>
#include <utility>
#include "hc_list.h"
#include "hc_list_helpers.h"
#include <cctype>
#include "stoi.h"

using namespace std;

typedef void (*stack_func)(Stack&);


struct name_def_pair {
        string name;
        list<string> def;
};


// functions to go in list (& pop-apply-push helper)
void reverse_print(Stack S);
bool in_func_list(list<pair <string, stack_func> > L);
bool in_func_list_helper(string s, list<pair <string, stack_func> > L);
bool in_definitions(string s);
bool in_definitions_helper(string s, list<name_def_pair> L);
void handle_builtin(string s, Stack &S);
void handle_userdefined(string s, Stack &S);
void execute_userdefined(name_def_pair p, Stack &S);
void handle_input(string s, Stack &S);
void handle_input_recursive(string s, Stack &S);
void cli(char* file_name);
void Start_stack_interface();


#endif
