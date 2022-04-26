// Snake - Headers with classes definitions
// Snake.h (Class definition | Function prototypes and data members) 

class Snake
{
public:

	Snake();

	void appleCollision();
	void borderCollision();
	void extendSnakeTail();
	void fillTail();
	void getNextPosition();
	void selfCollisionTest();
	void switchDirection();

private:

	int headCoord;
	int newHeadCoord;
	int tailEndCoord;
};