// Snake
// Defines.h (Class definition | Function prototypes and data members)

#pragma once

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
    NORTH,
    SOUTH,
    EAST,
    WEST,
};

#define SIZE 20