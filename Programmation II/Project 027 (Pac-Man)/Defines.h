#ifndef EXAMEN_Defines_h
#define EXAMEN_Defines_h

#define INITIAL_DIRECTION WEST
#define DEFAULT_GHOST_SPEED 7
#define DEFAULT_PACMAN_SPEED 8

#define PACMAN_NB_LIFES 3

const int WINDOW_SIZE = 810;//Make sure it fits game's size.
const int SCREEN_WIDTH = WINDOW_SIZE;
const int SCREEN_HEIGHT = WINDOW_SIZE;

const int FONT_SIZE = 32;

#define POINTS_PER_DOT 10

#define POWER_UP_DURATION 30

enum GAME_EVENT
{
    SET_DIRECTION_WEST,
    SET_DIRECTION_EAST,
    SET_DIRECTION_NORTH,
    SET_DIRECTION_SOUTH,
    DEBUG_MOVE_BY,
};

enum DIRECTION
{
    NORTH = 1,
    SOUTH,
    EAST,
    WEST,
    FIRST = NORTH,
    LAST = WEST
};

#endif
