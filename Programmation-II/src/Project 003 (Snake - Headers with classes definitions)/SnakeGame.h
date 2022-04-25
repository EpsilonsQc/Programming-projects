// Snake - Headers with classes definitions
// SnakeGame.h (Class definition | Function prototypes and data members)

class SnakeGame
{
public:

	SnakeGame();

	void initialize();
	void main();
	void onKeyDown();
	void updatePlayField();
	void setDifficulty();

private:

	int apple;
	int appleEaten;
	int direction;
	int gameIsPlaying;
	int input;
	int paused;
	int player;
	int playField;
	int rendered;
	int tick;
	int difficulty;

};