// Snake
// Game.cpp (Implementation file | Constructor and member functions definitions)

#include <string>

#include "Game.h"
#include "SnakeWindow.h"

Game::Game() :
    gridSize(SIZE, SIZE),
    snake(Vector2d(SIZE / 2, SIZE / 2)),
    gameOver(false)
{
    FindPositionForApple();
}

void Game::OnTime(double time, double deltaTime)
{
    if (!gameOver)
    {
        snake.Move(deltaTime);
        if (DetectCollision(snake, apple))
        {
            // std::cout << "On collision!" << std::endl;
            snake.IncreaseLengthBy1();
            FindPositionForApple();
        }
        CheckGameOverConditions();
    }
}

void Game::OnGameEvent(GAME_EVENT event)
{
    switch (event)
    {
    case SET_DIRECTION_EAST:
        snake.SetDirection(EAST);
        break;
    case SET_DIRECTION_WEST:
        snake.SetDirection(WEST);
        break;
    case SET_DIRECTION_NORTH:
        snake.SetDirection(NORTH);
        break;
    case SET_DIRECTION_SOUTH:
        snake.SetDirection(SOUTH);
        break;
    case DEBUG_MOVE_BY:
        snake.MoveBy(1.0);
        break;
    default:
        std::cerr << "Invalid event=" << event << std::endl;
    }
}

void Game::Draw(const SnakeWindow& windowRef) const
{
    // DrawChessGrid(windowRef); // Debug usage only
    snake.Draw(windowRef);
    apple.Draw(windowRef);
}

void Game::DrawChessGrid(const SnakeWindow& windowRef) const
{
    for (int i = 0; i < gridSize.x; i++)
    {
        for (int j = 0; j < gridSize.y; j++)
        {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
            {
                windowRef.DrawTileAt(Vector2i(i, j));
            }
        }
    }
}

void Game::CheckGameOverConditions()
{
    if (IsSnakeOutOfBounds() || IsSnakeRollOver())
    {
        gameOver = true;
        std::string reason = IsSnakeOutOfBounds() ? "OutOfBounds" : "Rollover";
        std::cout << "GAME OVER! " << reason << std::endl;
    }
}

bool Game::IsSnakeOutOfBounds() const
{
    Vector2i pos = snake.GetPosition().ToVector2i();
    // std::cout << "Position=" << pos.x << " " << pos.y << std::endl;
    return pos.x < 0 || pos.x >= SIZE || pos.y < 0 || pos.y >= SIZE;
}

bool Game::IsSnakeRollOver() const
{
    return snake.IsRollOver();
}

bool Game::DetectCollision(const Snake& snakeRef, const Apple& appleRef) const
{
    return snakeRef.GetPosition().ToVector2i().Equals(appleRef.GetPosition());
}

void Game::FindPositionForApple()
{
    bool foundPosition = false;
    int x = rand() % SIZE;
    int y = rand() % SIZE;
    for (int i = x; i < gridSize.x; i++)
    {
        for (int j = y; j < gridSize.y; j++)
        {
            if (!snake.IsOnSnake(Vector2i(i, j)))
            {
                std::cout << "Found position for apple at " << i << " " << j << std::endl;
                foundPosition = true;
                apple.SetPosition(Vector2i(i, j));
                return;
            }
            else
            {
                std::cout << "Snake at " << i << " " << j << std::endl;
            }
        }
    }
    if (!foundPosition)
    {
        for (int i = 0; i < gridSize.x; i++)
        {
            for (int j = 0; j < gridSize.y; j++)
            {
                if (!snake.IsOnSnake(Vector2i(i, j)))
                {
                    foundPosition = true;
                    apple.SetPosition(Vector2i(i, j));
                    return;
                }
            }
        }
    }
    if (!foundPosition)
    {
        gameOver = true;
        std::cout << "YOU BEAT THE GAME" << std::endl;
    }
}