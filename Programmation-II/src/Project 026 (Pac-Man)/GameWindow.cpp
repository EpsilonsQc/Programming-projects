#include "GameWindow.h"

#include "Defines.h"
#include "Game.h"

using namespace std;

GameWindow::GameWindow():
game(),
window(nullptr),
renderer(nullptr),
font(nullptr),
previousFrameTime(0.0)
{
	hud.SetGame(&game);
}

GameWindow::~GameWindow()
{
    //cout << "GameWindow DTOR" << endl;
}

void GameWindow::Draw()
{
    //std::cout << "GameWindow::draw()" << std::endl;
    
    //Clear screen
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );
    
    game.Draw(*this);
    hud.Draw(*this);

    //Update screen
    SDL_RenderPresent( renderer );
}

void GameWindow::DrawTileAt(Vector2i pos) const
{
    DrawTileAt(pos, Color::Black);
}

void GameWindow::DrawTileAt(Vector2i pos, Color color) const
{
    DrawInnerTileAt(pos, 1, color);
}

void GameWindow::DrawInnerTileAt(Vector2i pos, double pct, Color color) const
{
    if(WINDOW_SIZE % game.GetGridSize().x != 0)
    {
        cerr << "Watch out. The grid does not fit the window size!" << endl;
    }
    
    static int tileSize = WINDOW_SIZE / game.GetGridSize().x;
    int offset = static_cast<int>((1.0 - pct) * tileSize / 2);
    int side = static_cast<int>(tileSize * pct);
    SDL_Rect fillRect = { pos.x * tileSize + offset, pos.y * tileSize + offset, side, side };
    SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, 0xFF );
    SDL_RenderFillRect( renderer, &fillRect );
}

void GameWindow::OnTime(double totalTime, double deltaTime)
{
    //std::cout << "OnTime " << totalTime << " deltaTime " << deltaTime << std::endl;
    game.OnTime(totalTime, deltaTime);
}

int GameWindow::Init()
{
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }
        
        //Create window
        window = SDL_CreateWindow( "PACMAN", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == nullptr )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
            if( renderer == nullptr )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
            }
        }
    }
    
    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    else
    {
        font = TTF_OpenFont("Arial.ttf", FONT_SIZE);
    }
    
    return success;
}

bool GameWindow::ProcessInput()
{
    //Event handler
    SDL_Event e;
    
    //Handle events on queue
    while( SDL_PollEvent( &e ) != 0 )
    {
        //User requests quit
        if( e.type == SDL_QUIT )
        {
            return true;
        }//User presses a key
        else if( e.type == SDL_KEYDOWN )
        {
            //Select surfaces based on key press
            switch( e.key.keysym.sym )
            {
                case SDLK_UP:
                    //std::cout << "Up" << std::endl;
                    game.OnGameEvent(SET_DIRECTION_NORTH);
                    break;
                    
                case SDLK_DOWN:
                    //std::cout << "Down" << std::endl;
                    game.OnGameEvent(SET_DIRECTION_SOUTH);
                    break;
                    
                case SDLK_LEFT:
                    //std::cout << "Left" << std::endl;
                    game.OnGameEvent(SET_DIRECTION_WEST);
                    break;
                    
                case SDLK_RIGHT:
                    //std::cout << "Right" << std::endl;
                    game.OnGameEvent(SET_DIRECTION_EAST);
                    break;
                    
                default:
                    std::cout << "Received unknown key:" << e.key.keysym.sym << std::endl;
                    break;
            }
        }
    }
    
    return false;
}

int GameWindow::Run()
{
    //Start up SDL and create window
    if( !Init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Main loop flag
        bool quit = false;
        
        //While application is running
        while( !quit )
        {
            quit = ProcessInput();
            
            double now = SDL_GetTicks() / 1000.0;
            double deltaTime = now - previousFrameTime;
            previousFrameTime = now;
            OnTime(now, deltaTime);
            
            Draw();
        }
    }
    
    //Free resources and close SDL
    Close();
    
    return 0;
}

void GameWindow::Close()
{
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = nullptr;
    renderer = nullptr;
    
    TTF_CloseFont( font );
    font = NULL;
    
    TTF_Quit();
    SDL_Quit();
}

void GameWindow::DrawText(std::string text, int x, int y, Color c) const
{
    SDL_Color textColor = {static_cast<Uint8>(c.r), static_cast<Uint8>(c.g), static_cast<Uint8>(c.b)};
    
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    
    TTF_SizeText(font, text.c_str(), &rect.w, &rect.h);
    
    SDL_RenderCopy(renderer, textTexture, NULL, &rect);
    
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

void GameWindow::MeasureText(std::string text, int& w, int& h) const
{
    TTF_SizeText(font, text.c_str(), &w, &h);
}
