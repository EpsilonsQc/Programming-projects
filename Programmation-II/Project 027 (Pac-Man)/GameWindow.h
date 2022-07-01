#ifndef __PACMAN__GameWindow__
#define __PACMAN__GameWindow__

#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>

#include "Game.h"
#include "HUD.h"
#include "Vector2i.h"
#include "Color.h"

class GameWindow
{
public:
    GameWindow();
    ~GameWindow();
    
    int Run();
    void OnTime(double totalTime);
    void DrawTileAt(Vector2i pos) const;
    void DrawTileAt(Vector2i pos, Color c) const;
    void DrawInnerTileAt(Vector2i pos, double pct, Color c) const;
    void DrawText(std::string text, int x, int y, Color c) const;
    void MeasureText(std::string text, int& w, int& h) const;
    
private:
    int Init();
    void Close();
    bool ProcessInput();
    void Draw();
    void OnTime(double totalTime, double deltaTime);

private:
    Game game;
    HUD hud;
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    double previousFrameTime;
};

#endif /* defined(__PACMAN__GameWindow__) */
