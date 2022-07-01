// Snake - Headers with class definitions
// Main.cpp (Main function | Program execution begins and ends there) 

using namespace std;

#include <iostream>

void displayIntro();
int endOfProgram();

int main()
{
	displayIntro();

	cout << "Please look at the headers file:" << endl << endl;
	
	cout << "Apple.h" << endl;
	cout << "Coord.h" << endl;
	cout << "Direction.h" << endl;
	cout << "GameRenderer.h" << endl;
	cout << "Input.h" << endl;
	cout << "Playfield.h" << endl;
	cout << "Player.h" << endl;
	cout << "Snake.h" << endl;
	cout << "SnakeGame.h" << endl;
	
	endOfProgram();
}

void displayIntro()
{
	cout << "================================================" << endl;
	cout << ".:: SNAKE - HEADERS WITH CLASS DEFINITIONS ::." << endl;
	cout << "================================================" << endl << endl;
}

int endOfProgram()
{
	cout << endl;
	cout << "====================" << endl;
	cout << ":: END OF PROGRAM ::" << endl;
	cout << "====================" << endl << endl;

	system("pause");

	return 0;
}