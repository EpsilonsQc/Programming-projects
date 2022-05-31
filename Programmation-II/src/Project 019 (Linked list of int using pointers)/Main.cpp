// Linked list of int using pointers
// Main.cpp (Main function | Program execution begins and ends there) 

#include "LinkedList.h"
#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{
	array<int, 5> myArray = { 0, 0, 0, 0, 0 };
	vector<int> myVector;

	LinkedList MyLinkedListObj;

	cout << "myArray size: " << myArray.size() << endl;
	cout << "myVector size: " << myVector.size() << endl;
	cout << "MyLinkedListObj size: " << MyLinkedListObj.size() << endl << endl;

	myVector.push_back(333);
	MyLinkedListObj.add(333);

	cout << "myVector size: " << myVector.size() << endl;
	cout << "MyLinkedListObj size: " << MyLinkedListObj.size() << endl << endl;

	cout << "myVector at subscript 0: " << myVector.at(0) << endl;
	cout << "MyLinkedListObj get 0: " << MyLinkedListObj.get(0) << endl << endl;

	myVector.push_back(666);
	MyLinkedListObj.add(666);

	cout << "myVector size: " << myVector.size() << endl;
	cout << "MyLinkedListObj size: " << MyLinkedListObj.size() << endl << endl;

	cout << "myVector at subscript 1: " << myVector.at(1) << endl;
	cout << "MyLinkedListObj get 1: " << MyLinkedListObj.get(1) << endl << endl;

	cout << "myVector at subscript 0: " << myVector.at(0) << endl;
	cout << "MyLinkedListObj get 0: " << MyLinkedListObj.get(0) << endl << endl;

	cout << "MyLinkedListObj get 333: " << MyLinkedListObj.indexOf(333) << endl;
	cout << "MyLinkedListObj get 666: " << MyLinkedListObj.indexOf(666) << endl << endl;

	cout << "MyLinkedListObj get 999: " << MyLinkedListObj.indexOf(999) << endl << endl;

	MyLinkedListObj.clear();
	cout << "MyLinkedListObj.size after clear: " << MyLinkedListObj.size() << endl << endl;

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
	cout << endl;

	system("pause");

	return 0;
}