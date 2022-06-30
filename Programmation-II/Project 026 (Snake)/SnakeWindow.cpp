// Snake
// SnakeWindow.cpp (Implementation file | Constructor and member functions definitions)

#include <SDL.h>

#include "SnakeWindow.h"
#include "Defines.h"
#include "Game.h"

const int WINDOW_SIZE = 500;
const int SCREEN_WIDTH = WINDOW_SIZE;
const int SCREEN_HEIGHT = WINDOW_SIZE;

SnakeWindow::SnakeWindow() :
    game(),
    gWindow(nullptr),
    gRenderer(nullptr),
    previousFrameTime(0.0)
{
}

void SnakeWindow::Draw()
{
    // std::cout << "SnakeWindow::draw()" << std::endl;

    // Clear screen
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);

    game.Draw(*this);

    // Update screen
    SDL_RenderPresent(gRenderer);
}

void SnakeWindow::DrawTileAt(Vector2i pos) const
{
    DrawTileAt(pos, 0, 0, 0);
}

void SnakeWindow::DrawTileAt(Vector2i pos, int colorR, int colorG, int colorB) const
{
    static int tileSize = WINDOW_SIZE / game.GetGridSize().x;
    SDL_Rect fillRect = { pos.x * tileSize, pos.y * tileSize, tileSize, tileSize };
    SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, 0xFF);
    SDL_RenderFillRect(gRenderer, &fillRect);
}

void SnakeWindow::OnTime(double totalTime, double deltaTime)
{
    // std::cout << "OnTime " << totalTime << " deltaTime " << deltaTime << std::endl;
    game.OnTime(totalTime, deltaTime);
}

int SnakeWindow::Init()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        // Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        // Create window
        gWindow = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                // Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            }
        }
    }

    return success;
}

bool SnakeWindow::ProcessInput()
{
    // Event handler
    SDL_Event e;

    // Handle events on queue
    while (SDL_PollEvent(&e) != 0)
    {
        // User requests quit
        if (e.type == SDL_QUIT)
        {
            return true;
        }// User presses a key
        else if (e.type == SDL_KEYDOWN)
        {
            // Select surfaces based on key press
            switch (e.key.keysym.sym)
            {
            case SDLK_UP:
                // std::cout << "Up" << std::endl;
                game.OnGameEvent(SET_DIRECTION_NORTH);
                break;

            case SDLK_DOWN:
                // std::cout << "Down" << std::endl;
                game.OnGameEvent(SET_DIRECTION_SOUTH);
                break;

            case SDLK_LEFT:
                // std::cout << "Left" << std::endl;
                game.OnGameEvent(SET_DIRECTION_WEST);
                break;

            case SDLK_RIGHT:
                // std::cout << "Right" << std::endl;
                game.OnGameEvent(SET_DIRECTION_EAST);
                break;

            case SDLK_a:
                // std::cout << "A" << std::endl;
                game.OnGameEvent(DEBUG_MOVE_BY);
                break;

                // A
                // game.OnGameEvent(DEBUG_MOVE_BY);

            default:
                // std::cout << "Received unknown key:" << e.key.keysym.sym << std::endl;
                break;
            }
        }
    }

    return false;
}

int SnakeWindow::Run()
{
    // Start up SDL and create window
    if (!Init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        // Main loop flag
        bool quit = false;

        // While application is running
        while (!quit)
        {
            quit = ProcessInput();

            double now = SDL_GetTicks() / 1000.0;
            double deltaTime = now - previousFrameTime;
            previousFrameTime = now;
            OnTime(now, deltaTime);

            Draw();
        }
    }

    // Free resources and close SDL
    Close();

    return 0;
}

void SnakeWindow::Close()
{
    // Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    SDL_Quit();
}