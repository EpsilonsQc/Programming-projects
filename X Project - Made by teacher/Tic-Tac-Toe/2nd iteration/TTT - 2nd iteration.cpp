#include <iostream>
#include <time.h>

using namespace std;

void displayWelcomeMessage();
void printGrid();
void initRandom();
bool determineWhoPlaysFirst();
void playHuman(char);
bool isValidSquare(int);
void play(int, char);
bool detectWinner(bool);
void playAI(char);
bool isGridFull();
bool onPlayerTurn(char, bool);

char slot1 = '1';
char slot2 = '2';
char slot3 = '3';
char slot4 = '4';
char slot5 = '5';
char slot6 = '6';
char slot7 = '7';
char slot8 = '8';
char slot9 = '9';

const char X = 'X';
const char O = 'O';
const int NB_SLOTS = 9;

int main()
{
    initRandom();
    displayWelcomeMessage();
    printGrid();
    
    bool isHuman = determineWhoPlaysFirst();
    char mark = X;
    
    bool isGameOver = false;
    
    while(!isGameOver)
    {
        isGameOver = onPlayerTurn(mark, isHuman);
        
        mark = (mark == X) ? O : X;
        
        isHuman = !isHuman;
    }
}

void displayWelcomeMessage()
{
    cout << "Welcome to TTT" << endl;
}

void printGrid()
{
    cout << " " << slot1 << " | " << slot2 << " | " << slot3 << endl;
    cout << "---|---|---" << endl;
    cout << " " << slot4 << " | " << slot5 << " | " << slot6 << endl;
    cout << "---|---|---" << endl;
    cout << " " << slot7 << " | " << slot8 << " | " << slot9 << endl << endl;
}

void initRandom()
{
    srand(static_cast<unsigned>(time(0)));
}

bool determineWhoPlaysFirst()
{
    bool isHumanFirst = rand() % 2 == 0;
    
    if(isHumanFirst)
    {
        cout << "You play first." << endl;
    }
    else
    {
        cout << "Computer plays first." << endl;
    }
    
    return isHumanFirst;
}

bool onPlayerTurn(char mark, bool isHuman)
{
    if(isHuman)
    {
        playHuman(mark);
    }
    else
    {
        playAI(mark);
    }
    
    printGrid();
    
    return detectWinner(isHuman);
}

void playHuman(char mark)
{
    int square = 0;
    
    bool isValid = false;
    while(!isValid)
    {
        cout << "Select an empty square:" << endl;
        cin >> square;
        isValid = isValidSquare(square);
    }
    
    play(square, mark);
}

void playAI(char mark)
{
    bool isValid = false;
    int square = rand() % NB_SLOTS + 1;
    while(!isValid)
    {
        square++;
        if(square > NB_SLOTS)
        {
            square = 1;
        }
        isValid = isValidSquare(square);
    }

    play(square, mark);
}

bool isValidSquare(int square)
{
    switch (square)
    {
        case 1: return slot1 == '1';
        case 2: return slot2 == '2';
        case 3: return slot3 == '3';
        case 4: return slot4 == '4';
        case 5: return slot5 == '5';
        case 6: return slot6 == '6';
        case 7: return slot7 == '7';
        case 8: return slot8 == '8';
        case 9: return slot9 == '9';
        default:
            return false;
    }
}

void play(int square, char mark)
{
    switch (square)
    {
        case 1: slot1 = mark; break;
        case 2: slot2 = mark; break;
        case 3: slot3 = mark; break;
        case 4: slot4 = mark; break;
        case 5: slot5 = mark; break;
        case 6: slot6 = mark; break;
        case 7: slot7 = mark; break;
        case 8: slot8 = mark; break;
        case 9: slot9 = mark; break;
    }
}

bool detectTTT(char c1, char c2, char c3)
{
    return c1 == c2 && c2 == c3;
}

bool detectWinner(bool isHuman)
{
    bool isGameOver = false;
    
    isGameOver |= detectTTT(slot1, slot2, slot3);
    isGameOver |= detectTTT(slot4, slot5, slot6);
    isGameOver |= detectTTT(slot7, slot8, slot9);
    isGameOver |= detectTTT(slot1, slot4, slot7);
    isGameOver |= detectTTT(slot2, slot5, slot8);
    isGameOver |= detectTTT(slot3, slot6, slot9);
    isGameOver |= detectTTT(slot1, slot5, slot9);
    isGameOver |= detectTTT(slot3, slot5, slot7);
    
    if(isGameOver)
    {
        if(isHuman)
        {
            cout << "You win" << endl;
        }
        else
        {
            cout << "You lose" << endl;
        }
    }
    else if (isGridFull())
    {
        cout << "Tie game!" << endl;
        isGameOver = true;
    }

    return isGameOver;
}

bool isGridFull()
{
    for(int i = 1; i <= NB_SLOTS; i++)
    {
        if(isValidSquare(i))
        {
            return false;
        }
    }
    return true;
}