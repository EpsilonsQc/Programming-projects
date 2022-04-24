// Snake - Headers with classes definitions
// Direction.h (Class definition | Contain function prototypes AND data members)

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