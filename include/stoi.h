#include <string>
using namespace std;

// STRING-TO-INTEGER HELPER FUNCTION
// created for CMSC245 Fall 2013 by David Wonnacott, Haverford College, Haverford, PA

// handy functions to convert between integers (i) and strings (s), and test if a string is made of numerals
//  e.g.  atoi("325") == 325 and itoa(325) == "325"

string itos(int i);  // itos(12) is "12"
int stoi(string s);  // stoi("12") is 12
bool is_numeric(string s);  // true for is_numeric("23"), false for is_numeric("2q3")
