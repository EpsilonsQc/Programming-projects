// Linked list of int using pointers
// LinkedList.cpp (Implementation file | Constructor and member functions definitions)

#include "LinkedList.h"
#include <iostream>

using namespace std;

// Default CTOR
LinkedList::LinkedList() :
	first(nullptr),
	numberOfElements(0)
{
	// Empty CTOR body
}

// Add
void LinkedList::add(int value)
{
	numberOfElements++;

	Node* newNode = new Node();
	newNode->data = value;

	if (numberOfElements == 1)
	{
		first = newNode;
	}
	else
	{
		Node* last = first;

		while (last->next != nullptr)
		{
			last = last->next;
		}

		last->next = newNode;
	}
}

// Add at
void LinkedList::addAt(int value, int index)
{
	Node* newNode = new Node();
	newNode->data = value;

	Node* old = nullptr;

	if (index == 0)
	{
		old = first;
		first = newNode;
	}
	else
	{
		Node* nodeAtIndex = first;

		for (int i = 1; i < index; i++)
		{
			nodeAtIndex = nodeAtIndex->next;
		}

		old = nodeAtIndex->next;
		nodeAtIndex->next = newNode;
	}

	newNode->next = old;
	numberOfElements++;
}

// Remove
void LinkedList::remove(int index)
{
	if (index >= 0 && index < size())
	{
		Node* nodeToRemove = first;

		if (index == 0)
		{
			first = first->next;
		}
		else
		{
			Node* previous = first;
			nodeToRemove = first->next;

			for (int i = 1; i < index; i++)
			{
				previous = nodeToRemove;
				nodeToRemove = nodeToRemove->next;
			}
			previous->next = nodeToRemove->next;
		}

		numberOfElements--;
		delete nodeToRemove;
	}
	else
	{
		cout << endl << "[Error] Invalid index" << endl;
	}
}

// Clear
void LinkedList::clear()
{
	while (size() > 0)
	{
		remove(0);
	}
}

// Get
int LinkedList::get(int index) const
{
	Node* nodeAtIndex = first;

	for (int i = 0; i < index; i++)
	{
		nodeAtIndex = nodeAtIndex->next;
	}

	return nodeAtIndex->data;
}

// Index of
int LinkedList::indexOf(int value) const
{
	Node* node = first;

	for (int i = 0; i < size(); i++)
	{
		if (node->data == value)
		{
			return i;
		}
		node = node->next;
	}

	cout << endl << "[Error] Cannot find value" << endl;

	return -1;
}

// Size
int LinkedList::size() const
{
	return numberOfElements;
}

// Print
void LinkedList::print() const
{
	Node* node = first;
	cout << "[ ";
	
	for (int i = 0; i < size(); i++)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << "]" << endl;
}