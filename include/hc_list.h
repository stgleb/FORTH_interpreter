#if ! defined LIST_H
#define LIST_H

// SIMPLE LIST ADT
// created for CMSC245 Fall 2013 by David Wonnacott, Haverford College, Haverford, PA

#include <assert.h>

template <class T> struct list_element; // see list.t for definition

// Fighting with G++ 4.0.3
template <class T> class list;
template <class T>    bool empty(const list<T> &l);
template <class T>       T  head(const list<T> &l);
template <class T> list<T>  rest(const list<T> &l);


template <class T> class list {
public:
	// A list can be one of two things
	//   * an empty list, created with   list()
	//   * a head element and a sublist, list(h, l)
	// complexity:  both O(1)
	list();
	list(const T &head, const list<T> &rest);

	// Given a list, we can ask if it is empty,
	// or retrieve its head or the sublist part:
  // friend bool T::template empty<T>(const list<T> &l);
	friend bool empty<T>(const list<T> &l);
	// axioms:
	// 	empty(list())     === true
	// 	empty(list(h, r)) === false
	// complexity: O(1)

	friend T head<T>(const list<T> &l);
	// precondition: list is not empty
	// axioms:
	//   head(list(h, r)) === h
	// complexity: O(1)

	friend list<T> rest<T>(const list<T> &l);
	// precondition: list is not empty
	// axioms:
	// 	 rest(list(h, r)) === r
	// complexity: O(1)

	// The following are required for memory management,
	// which we will discuss later:
	list(const list<T> &init);
	// complexity: O(1)

	list<T> &operator=(const list &right);
	// complexity: O(length(*this))

	~list();
	// complexity: O(length(*this))
	
private:

//	Each list element has exactly one "list"
//	that points to it, and each pointer
//	points to a valid list_element (or is 0).
//	And all list_elements are on the heap.

	list_element<T> *first; // 0 (null pointer) for empty list
};

#include <iostream>

template <class T> std::ostream &operator<<(std::ostream &o, const list<T> &l);

#include "hc_list.t"

#endif
