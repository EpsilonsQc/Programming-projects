// Linked list of int using pointers
// LinkedList.h (Class definition | Function prototypes and data members)

#pragma once

#include "Node.h"

class LinkedList
{
public:

	LinkedList();

	void add(int value);
	void addAt(int value, int index);
	void remove(int index);
	void clear();
	int get(int index) const;
	int indexOf(int value) const;
	int size() const;
	void print() const;
	void displayIntro();
	int endOfProgram();

private:

	Node *first;
	int numberOfElements;

};