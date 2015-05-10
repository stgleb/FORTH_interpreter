#include "stoi.h"
#include <cstdlib>
#include <cstdio>

string itos(int i)  // turn an int i into a string; possibly useful for printing
{
  char t[33]; sprintf(t,"%d",i); return t;
}

int _stoi(string s)
{
  return atoi(s.c_str());
}

bool is_numeric(string s)
{
  if (s.length()<1)
      return false;

  int i; // next digit to process
  if (s[0] == '-' || s[0] == '+') {
      i = 1;
      if (s.length()<=i)
	  return false;
  } else {
      i = 0;
  }

  for (; i<s.length(); i++)
    if (!isdigit(s[i])) return false;

  return true;
}
