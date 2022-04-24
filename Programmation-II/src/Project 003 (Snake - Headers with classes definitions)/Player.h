// Snake - Headers with classes definitions
// Player.h (Class definition | Contain function prototypes AND data members)

#include <string>

class Player
{
public:

	Player();

	void playerName();
	void setLevel();
	void score();

private:

	std::string playerName;
	int level;
	int score;
};