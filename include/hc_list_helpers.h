#if ! defined LIST_HELPERS_H
#define LIST_HELPERS_H

// SIMPLE LIST ADT HELPER FUNCTIONS
// created for CMSC245 Fall 2013 by David Wonnacott, Haverford College, Haverford, PA

#include "hc_list.h"

// find the length of the list
template <class T> int length(const list<T> &il);

// easy ways to build lists of 1-5 items...
template <class T> list<T> ez_list(const T &one);
template <class T> list<T> ez_list(const T &one, const T &two);
template <class T> list<T> ez_list(const T &one, const T &two, const T &three);
template <class T> list<T> ez_list(const T &one, const T &two, const T &three, const T &four);
template <class T> list<T> ez_list(const T &one, const T &two, const T &three, const T &four, const T&five);

// find i in list il, answer true (it's there) or false (it's not)
template <class T> bool find(const T &i, const list<T> &il);
// find i in list il, return 0 if at head, 1 if next, etc., or -1 if not there
template <class T>  int index_of(const T &i, const list<T> &il);

// find an element i for which f(i) is true in il, return true iff one is there
template <class T> bool find(bool (*f)(const T &i), const list<T> &il);

// return the thing that was found, as above
template <class T> const T retrieve(bool (*f)(const T &i), const list<T> &il);
// precondtion: il should have at least one element for which f is true
// postcondition: return that element (or throw "false" as an exception if it's not there)
// 		  if there is more than one such element, return the one closest to the head

// produce a list of those elements i of il for which f(i) is true
// (in the original order)
template <class T> list<T> filter(bool (*f)(const T &i), const list<T> &il);


#include "hc_list_helpers.t"

#endif
