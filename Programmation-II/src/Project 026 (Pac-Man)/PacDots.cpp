#include "PacDots.h"

#include "GameWindow.h"
#include "Maze.h"
#include "Pacman.h"

PacDots::PacDots(Maze* maze):
maze(maze)
{
    SetColor(Color::White);
}

void PacDots::OnCollision(const GameObject* other)
{
    const Pacman* pacman = dynamic_cast<const Pacman*>(other);
    if(pacman != nullptr)
    {
        maze->RemoveDot(this);
    }
}

void PacDots::Draw(const GameWindow& windowRef) const
{
    GameObject::Draw(windowRef);
    
    if(IsVisible())
    {
        Color color = Color::Black;
        double ratio = 0.1;
        windowRef.DrawInnerTileAt(GetPosition(), ratio, color);
    }
    
}
