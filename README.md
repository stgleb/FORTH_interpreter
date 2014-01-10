# FORTH_interpreter

This project is a working C++-based interpreter for the stack-based language FORTH. It is based on an assigment for the course CMSC245: Principles of Programming Languages at Haverford College, taught by David Wonnacott in Fall 2013.

## Set-up Instructions

This program was tested on Mac OSX 10.8.5 using the g++ compiler. It should be easy to modify it to run on any operating system.

1. Download the FORTH_interpreter repository as a ZIP file. 
2. Set your current directory to the project folder. 
3. Build the project by typing `./build.sh` into the command line. 
4. Run the compiled program by typing `./bin/FORTH_interpreter` into the command line.


## How to Use

FORTH is a stack-based, procedural, untyped programming language. This interpreter includes a subset of the FORTH language features. See http://en.wikipedia.org/wiki/Forth_(programming_language) for more details on the language.

FORTH_intepreter allows the user to create and manipulate a stack of integers. Input symbols are separated by either spaces or newlines.

Input types: 
* _End_. The input `end` quits out of the progam.
* _Integers._ The user adds elements to the main stack by typing integers into the interpreter interface. For example, the input `1 2 3 4` creates a stack with the integers 1, 2, 3, 4.
* _Stack functions._ A variety of built-in functions exist that allow the user to view the stack and manipulate it in various ways. Users can also define their own stack functions (see _Function definitions_)

  Built-in functions:
  * `.s` displays the size of the stack, followed by the elements of the stack. For example, if we start with an empty stack, the input `1 2 3 4` results in the output `<4> 1 2 3 4`.
  * `.` removes the top element of the stack and displays this element
  * `+`, `-`, and  `*` apply the given operator to the top two elements of the stack, with the second-to-top element as the first operand, and the top element as the second operand. The top element of the stack is replaced with the result of the operation. For example, the input `1 2 - .` results in the output `-1`.
  * `<`, `>`, and `=` apply the given relational operator to the top two elements of the stack, with the second-to-top element as the first operand, and the top element as the second operand. The top element of the stack is replaced with the result of the comparison, where `-1` indicates TRUE and `0` indicates FALSE. For example, the input `1 1 = .` results in the output `-1`, and `3 2 < .` outputs `0`.
  * `drop`, `nip`, `dup`, `over`, `tuck`, and `swap`: see http://wiki.laptop.org/go/Forth_stack_operators for an explanation of these stack operators. `dup`, for instance, duplicates the top element of the stack, so `1 dup . .` outputs `1 1`.
* _Function definitions._ This interpeter allows for user-defined functions, which are added to a dictionary and can be used again throughout the current instance of the program (i.e. these function definitions will have disappeared when you exit and re-enter the program). The structure of a function definition is as follows :
             `` : <FUNCTION NAME> <FUNCTION DEFINITION> ; ``
  For example, suppose we want to define a function `double` to take the top element of the stack and replace it with its   doubled value. The definition would look like: 
             ``: double dup + ; ``

  User-defined functions can be recursive and can make use of control flow operators `if`, `else`, and `endif`. See         http://www.complang.tuwien.ac.at/forth/gforth/Docs-html/Selection.html for explanation of use of control-flow operators.

You can navigate to `tests/some_tests.txt` for more examples of FORTH commands to try.
