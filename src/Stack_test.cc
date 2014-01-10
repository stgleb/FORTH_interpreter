// unit tests of Stack functions
// Allison Lake, for CMSC245 at Haverford College, Fall 2013

#include "Stack.h"
#include "Stack_test.h"

using namespace std;

bool Stack_test()
{
	Stack none = Stack();  // an empty stack
	Stack one  = Stack(1, none);
	Stack two  = Stack(2, one);
	Stack four = Stack(4, Stack(3, two));

	// Here is basically the same example in the "imperative" approach...
	Stack my_stack = Stack();
	my_stack.push(1);
	my_stack.push(2);
	my_stack.push(3).push(4);

	int extracted_from_four = four.pop();
	Stack four_after_extraction = four;  // here's what four would be after extraction .. since already popped

	int extracted_from_my_stack = my_stack.pop();
	Stack my_stack_after_extraction = my_stack;

	// now, check some things... these should all be true:
	return (
		extracted_from_four == 4 &&
		extracted_from_my_stack == 4 &&

		four_after_extraction.pop() == 3 && // since popped 4 off above
		four_after_extraction.pop() == 2 && // since have now popped 3 off
		four_after_extraction.top() == 1 &&
		four_after_extraction.pop() == 1 && // since popped 2 off
		four_after_extraction.empty() &&

		my_stack.top() == 3 && // since popped 4 off above
		my_stack.pop() == 3 &&
		my_stack.pop() == 2 &&
		my_stack.pop()  == 1 &&
		my_stack.empty()
		);
}

