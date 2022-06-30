#ifndef __PACMAN__GameObject__
#define __PACMAN__GameObject__

#include <iostream>

#include "Vector2i.h"
#include "Color.h"

class GameWindow;

class GameObject
{
public:
    GameObject();
    virtual ~GameObject() {}
    
    inline Vector2i GetPosition() const { return position; }
    inline void SetPosition(Vector2i position) { this->position = position; }
    
    inline Color GetColor() const { return color; }
    inline void SetColor(Color color) { this->color = color; }
    
    inline bool IsVisible() const { return visible; }
    inline void SetVisible(bool visible) { this->visible = visible; }
    
    bool Collides(const GameObject* other) const;
    
    virtual void OnCollision(const GameObject* other) = 0;
    virtual void Draw(const GameWindow& windowRef) const;
    
private:
    Vector2i position;
    Color color;
    bool visible;
};

#endif /* defined(__PACMAN__GameObject__) */
