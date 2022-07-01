#include <time.h>

#include "GameWindow.h"

int main(int argc, char **argv)
{
	srand(static_cast<unsigned int>(time(0)));
    GameWindow w;
	int result = w.Run();
	return result;
}
