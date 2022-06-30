// Snake - Headers with classes definitions
// Direction.h (Class definition | Function prototypes and data members)

#pragma once

class Direction
{
public:

	Direction();

	void directionFunction();
	void up();
	void right();
	void down();
	void left();

private:

	int lastDirection();
	int newDirection();
};