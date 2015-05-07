/*
	Stack_interface.cc
 Allison Lake, for CMSC245 at Haverford College, Fall 2013
	This file contains all of the function definitions for the Stack_interface.
	These will be used to generate the text interface for the stack

	Functions:
	Title			  		Description
	------------------------------------------
	Start_stack_interface	start the stack text interface
*/

/*----------Includes---------*/

#include "Stack_interface.h"
#include "hc_list.h"
#include "hc_list_helpers.h"
#include "stoi.h"

#include <fstream>
#include <thread>

Stack main_stack;


// from Dave's queue-adt.cc; helpful in allowing interpreter to create function definitions
static list<string>append_item(list<string> l, string item)
{
  if (empty(l)) {
    return list<string>(item, list<string>());
  } else {
    return list<string>(head(l), append_item(rest(l), item));
  }
}

// functions to go in list
void allie_plus(Stack &S)
{
	if (S.size() < 2) {
		cout << "stack contains < 2 elements";
	} else {
		int a;
		int b;
		a = S.pop();
		b = S.pop();
		int result;
		result = a + b;
		S.push(result);
	}
}

void allie_minus(Stack &S)
{
	if (S.size() < 2) {
		cout << "stack contains < 2 elements" << endl;
	} else {
		int a;
		int b;
		a = S.pop();
		b = S.pop();
		int result;
		result = b-a;
		S.push(result);
			}
	}

void allie_times(Stack &S)
{
	if (S.size() < 2) {
			cout << "stack contains < 2 elements" << endl;
	} else {
		int a;
		int b;
		a = S.pop();
		b = S.pop();
		int result;
		result = a * b;
		S.push(result);
		}
}

void pop_and_print(Stack &S)
{
	if (S.empty()) {
		cout << "can't pop an empty stack!" << endl;
	} else {
		cout << S.pop() << endl;
	}
}

void dot_s(Stack &S)
{
	cout << "<" << S.size() << ">\n";
	reverse_print(S);
	cout << "\n";
}

// drop, nip, dup, over, tuck, and swap, and the operations <, >, and = (

void drop_(Stack &S)
{
	S.pop();
}

void dup_(Stack &S)
{
	S.push(S.top());
}

void swap_(Stack &S)
{
	int to_be_below_top = S.pop();
	int to_be_top = S.pop();
	S.push(to_be_below_top).push(to_be_top);
}

void nip_(Stack &S)
{
	swap_(S);
	drop_(S);
}

void over_(Stack &S)
{
	int top = S.pop();
	int below_top = S.pop();
	S.push(below_top);
	S.push(top);
	S.push(below_top);
}

void tuck_(Stack &S)
{
	swap_(S);
	over_(S);
}

void lt_(Stack &S)
{
	int top = S.pop(); // second operand
	int below_top = S.pop(); // first operand
	if (below_top < top) {
		S.push(-1);
	} else {
		S.push(0);
	}
}

void gt_(Stack &S)
{
	int top = S.pop(); // second operand
	int below_top = S.pop(); // first operand
	if (below_top > top) {
		S.push(-1);
	} else {
		S.push(0);
	}

}

void eq_(Stack &S)
{
	int top = S.pop(); // second operand
	int below_top = S.pop(); // first operand
	if (below_top == top) {
		S.push(-1);
	} else {
		S.push(0);
	}
}
// .s helper function
void reverse_print(Stack S) // must FIX
{
	int size;
	size = S.size();
	Stack S2 = Stack();

	for (int n = size; n > 0; n--) {
		S2.push(S.pop());
	}

	for (int n = size; n > 0; n--) {
		cout << S2.pop() << " ";
	}
}

list<pair <string, stack_func> > func_list= list<pair <string, stack_func> >(make_pair("+", allie_plus),
											list<pair <string, stack_func> >(make_pair("-", allie_minus),
											list<pair <string, stack_func> >(make_pair("*", allie_times),
											list<pair <string, stack_func> >(make_pair(".", pop_and_print),
											list<pair <string, stack_func> >(make_pair(".s", dot_s),
											list<pair <string, stack_func> >(make_pair("dup", dup_),
											list<pair <string, stack_func> >(make_pair("swap", swap_),
											list<pair <string, stack_func> >(make_pair("drop", drop_),
											list<pair <string, stack_func> >(make_pair("nip", nip_),
											list<pair <string, stack_func> >(make_pair("over", over_),
											list<pair <string, stack_func> >(make_pair("tuck", tuck_),
											list<pair <string, stack_func> >(make_pair("<", lt_),
											list<pair <string, stack_func> >(make_pair(">", gt_),
											list<pair <string, stack_func> >(make_pair("=", eq_),
											list<pair <string, stack_func> >()))))))))))))));


list<name_def_pair> definitions = list<name_def_pair>();

bool in_func_list(string s) {
	list<pair <string, stack_func> > temp_func_list;
	pair <string, stack_func> h;

	temp_func_list = func_list;
	return in_func_list_helper(s, temp_func_list);
}

bool in_func_list_helper(string s, list<pair <string, stack_func> > L) {
	pair <string, stack_func> h;
	if (length(L) == 0) {
		return false;
	} else {
		h = head(L);
		if (s.compare(h.first)==0) {
			return true;
		} else {
			return in_func_list_helper(s, rest(L));
		}
	}
}

bool in_definitions(string s) {
	list<name_def_pair> temp_def_list = definitions;
	return in_definitions_helper(s, temp_def_list);
}

bool in_definitions_helper(string s, list<name_def_pair> L) {
	name_def_pair h;
	if (length(L)==0) {
		return false;
	} else {
		h = head(L);
		if (s.compare(h.name) == 0) {
			return true;
		} else {
			return in_definitions_helper(s, rest(L));
		}
	}
}


void add_definitions() {
// TODO: must catch syntax errors / unexpected input (not REQUIRED, but would be useful)

        name_def_pair pair;
        string token;
        bool do_not_add = false;

        // current token should be ":", so advance one
        cin >> token;
        // current token should now be the function name
        pair.name = token;
        pair.def  = list<string>();
        cin >> token;
        // current token should now be first word in the function definition
        while(token != ";") {
        	if ((in_func_list(token)) | (in_definitions(token)) | (is_numeric(token)) | (token.compare("if") == 0) |
        		(token.compare("else") == 0) | (token.compare("endif") == 0) | (token == pair.name)) {
        		pair.def = append_item(pair.def, token); 
        		cin >> token;
        	} else {
        		cout << token << " is undefined; " << pair.name << " not compiled" << endl;
        		do_not_add = true;
        		break;
        	}
        }
        if (not do_not_add) {
        	 definitions = list<name_def_pair>(pair, definitions);
        	 cout << "function " << pair.name << " compiled." << endl;
        }
}

void handle_builtin(string s, Stack &S) {
	list<pair <string, stack_func> > temp_func_list;
	pair <string, stack_func> h;

	temp_func_list = func_list;
	for (int n = length(func_list); n>0; n--) {
			h = head(temp_func_list);
			if (s.compare(h.first) == 0) {
				stack_func f;
				f = h.second;
				f(S);
				break;
			} else {
				temp_func_list = rest(temp_func_list);
			}
		}
}

void handle_userdefined(string s, Stack &S) {
	list<name_def_pair> temp_def_list;
	name_def_pair h;

	// first, find def in def list
	temp_def_list = definitions;
	for (int n = length(definitions); n>0; n--) {
		h = head(temp_def_list);
		if (s == h.name) {
			execute_userdefined(h, S);
			break;
		} else {
			temp_def_list = rest(temp_def_list);
		}
	}

}

void execute_userdefined(name_def_pair p, Stack &S) {
	string word;
	list<string> temp_word_list;
	bool boolean;
	temp_word_list = p.def;
	for (int n = length(p.def); n>0; n--) {
		word = head(temp_word_list);
		if (word == "if") {
			boolean = ((S.pop() == 0)? false : true ); // pop the stack -- top element should indicate "true" or "false"
			temp_word_list = rest(temp_word_list); // cut out the "if" from the word list
			word = head(temp_word_list); // advance to the next word
			if (boolean) {
				while ((word!="else") && (word!="endif")) {
					handle_input(word, S);
					temp_word_list = rest(temp_word_list);
					word = head(temp_word_list);
				}  // word should now be "else" or "endif", so we're done

			} else { // execute what's after the "else", or just end. current word should be first word after the "if"
				while((word!="else") && (word!= "endif")) {
					temp_word_list = rest(temp_word_list);
					word = head(temp_word_list);
				} // now, word should be "else" or "endif"
				if (word == "else") {
					temp_word_list = rest(temp_word_list);
					word = head(temp_word_list); // word should now be first word after the "else"
					while(word!="endif") {
						handle_input(word, S);
						temp_word_list = rest(temp_word_list);
						word = head(temp_word_list); // now word should be "endif", so we're done
					}
				} // otherwise, word is "endif", so we're done
			}
			break;
		} else {
			handle_input(word, S);
			temp_word_list = rest(temp_word_list);
		}
	}

}


void handle_input(string s, Stack &S)
{
	string token;
	string thread = "thread";
    cout<<s<<endl;

	if (is_numeric(s)) {
		S.push(_stoi(s));
	} else if (s == thread) {
	    cout <<"run in thread"<< endl;
	    cin >> token;
	    cout<< token<< endl;
	    std::thread t(handle_userdefined, token, std::ref(S));
	    t.detach();
	} else if (in_func_list(s)) {
		handle_builtin(s, S);
	} else if(in_definitions(s)) {
	    cout<<"execute function "<<s<<endl;
		handle_userdefined(s, S);
	} else {
		cout << s << " is undefined" << endl;
	}
}

void cli(char* file_name) {
	main_stack = Stack();
	ifstream in(file_name, std::ifstream::in);
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());

    string token;
    cout<<file_name<<endl;
    cin >> token;
    cout<< token<<endl;

    while (token != "end") {
        cout<< token<<endl;
        if (token == ":") {
			add_definitions();
		} else {
			handle_input(token, main_stack);
		}
		cin >> token;
	}
    in.close();
    std::cin.rdbuf(cinbuf);
}

void Start_stack_interface()
{
	main_stack = Stack();

    string token;
	cin >> token;

	while (token != "end") {
		if (token == ":") {
			add_definitions();
		} else {
			handle_input(token, main_stack);
		}
		cin >> token;
	}
}
