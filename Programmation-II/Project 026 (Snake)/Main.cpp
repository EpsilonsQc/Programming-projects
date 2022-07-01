// Snake
// Main.cpp (Main function | Program execution begins and ends there)

#include <time.h>

#include "SnakeWindow.h"

int main(int argc, char** argv) 
{
    srand((unsigned int)time(0));
    SnakeWindow w;
    return w.Run();
}