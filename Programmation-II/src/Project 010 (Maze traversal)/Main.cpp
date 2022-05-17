// Maze traversal 
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>

using namespace std;

int main()
{
    // arrayMaze();

    system("pause");

    return 0;
}

void arrayMaze()
{
    char maze[12][12] = 
    {
    '#','#','#','#','#','#','#','#','#','#','#','#',
    '#','.','.','.','#','.','.','.','.','.','.','#',
    '.','.','#','.','#','#','#','#','#','#','.','#',
    '#','#','#','.','#','.','.','.','.','#','.','#',
    '#','.','.','.','.','#','#','#','.','#','.','.',
    '#','#','#','#','.','#','.','#','.','#','.','#',
    '#','.','.','#','.','#','.','#','.','#','.','#',
    '#','#','.','#','.','#','.','#','.','#','.','#',
    '#','.','.','.','.','.','.','#','.','#','.','#',
    '#','#','#','#','#','#','.','#','#','#','.','#',
    '#','.','.','.','.','.','.','#','.','.','.','#',
    '#','#','#','#','#','#','#','#','#','#','#','#',
    };
}

void mazeTraverse()
{
    // There is a simple algorithm for walking through a maze that guarantees finding the exit (assuming that there is an exit). 
    // If there is not an exit, you’ll arrive at the starting location again. 
    // 
    // Write recursive function mazeTraverse to walk through the maze. 
    // The function should receive arguments that include a 12-by-12 built-in array of chars representing the maze and the starting location of the maze. 
    // 
    // As mazeTraverse attempts to locate the exit from the maze, it should place the character X in each square in the path. 
    //
    // The function should display the maze after each move, so the user can watch as the maze is solved.
}
