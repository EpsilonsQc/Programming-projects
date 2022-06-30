#ifndef __PACMAN__Maze__
#define __PACMAN__Maze__

#include <iostream>
#include <map>
#include <vector>

#include "GameObject.h"
#include "Vector2i.h"

class GameWindow;
class Ghost;
class Pacman;
class PacDots;
class Portal;

class Maze
{
public:
    Maze(Pacman* pacman);
    inline Vector2i GetSize() const { return Vector2i(size, size); }
    void Draw(const GameWindow& windowRef) const;
    void PhysicStep(double currentTime, double deltaTime);
    inline long GetNbRemainingDots() const { return static_cast<long>(dots.size()); }
    void Unload();
    void RemoveDot(PacDots* dot);
    bool IsWallAt(Vector2i pos) const;
    
private:
    static void DrawAll(const GameWindow& windowRef, std::vector<GameObject*> objects);
    void Load();
    int GetIndex(Vector2i pos) const;
    GameObject* GetObjectAt(Vector2i pos) const;
    void DeleteObjectAt(Vector2i pos);
    void ConfigurePortal(Portal* portal, char key);

private:
    Pacman* pacman;
    std::vector<Ghost*> ghosts;
    std::vector<PacDots*> dots;//TODO count static
    std::vector<GameObject*> mazeObjects;
    std::map<char, std::pair<Portal*, Portal*>> portals;
    unsigned int size;
};

#endif /* defined(__PACMAN__Maze__) */
