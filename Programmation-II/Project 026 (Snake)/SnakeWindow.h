// Snake
// SnakeWindow.h (Class definition | Function prototypes and data members)

#pragma once

#include <iostream>
#include <SDL.h>

#include "Game.h"
#include "Vector2i.h"

class SnakeWindow
{
public:
    SnakeWindow();
    int Run();
    void DrawTileAt(Vector2i pos) const;
    void DrawTileAt(Vector2i pos, int colorR, int colorG, int colorB) const;

private:
    int Init();
    void Close();
    bool ProcessInput();
    void Draw();
    void OnTime(double totalTime, double deltaTime);

private:
    Game game;
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    double previousFrameTime;
};