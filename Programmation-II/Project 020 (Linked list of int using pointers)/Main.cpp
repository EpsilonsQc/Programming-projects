// Linked list of int using pointers
// Main.cpp (Main function | Program execution begins and ends there) 

#include "LinkedList.h"
#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{
	LinkedList MyLinkedListObj;

	MyLinkedListObj.displayIntro();

	MyLinkedListObj.add(1111);
	cout << "LinkedList size: " << MyLinkedListObj.size() << endl;
	cout << "LinkedList get 0: " << MyLinkedListObj.get(0) << endl << endl;

	MyLinkedListObj.add(2222);
	cout << "LinkedList size: " << MyLinkedListObj.size() << endl;
	cout << "LinkedList get 0: " << MyLinkedListObj.get(0) << endl;
	cout << "LinkedList get 1: " << MyLinkedListObj.get(1) << endl << endl;

	cout << "LinkedList get 1111: " << MyLinkedListObj.indexOf(1111) << endl;
	cout << "LinkedList get 2222: " << MyLinkedListObj.indexOf(2222) << endl;
	cout << "LinkedList get 3333: " << MyLinkedListObj.indexOf(3333) << endl << endl;

	MyLinkedListObj.clear();
	cout << "LinkedList size after clear: " << MyLinkedListObj.size() << endl << endl;

	cout << "Add value 1, 2, 3, 4, 5, 6, 7, 8, 9 :" << endl;
	MyLinkedListObj.add(1);
	MyLinkedListObj.add(2);
	MyLinkedListObj.add(3);
	MyLinkedListObj.add(4);
	MyLinkedListObj.add(5);
	MyLinkedListObj.add(6);
	MyLinkedListObj.add(7);
	MyLinkedListObj.add(8);
	MyLinkedListObj.add(9);
	MyLinkedListObj.print();

	cout << endl << "Remove value at index 4 :" << endl;
	MyLinkedListObj.remove(4);
	MyLinkedListObj.print();

	cout << endl << "Remove value at index 2 :" << endl;
	MyLinkedListObj.remove(MyLinkedListObj.indexOf(2));
	MyLinkedListObj.print();

	cout << endl << "Add value 66 at index 1 :" << endl;
	MyLinkedListObj.addAt(66, 1);
	MyLinkedListObj.print();

	MyLinkedListObj.endOfProgram();
}