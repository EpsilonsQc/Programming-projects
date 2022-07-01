#include "Maze.h"

#include <fstream>
#include <string>
#include <vector>

#include "GameWindow.h"
#include "Ghost.h"
#include "PacDots.h"
#include "Pacman.h"
#include "Portal.h"
#include "Wall.h"

using namespace std;

Maze::Maze(Pacman* pacman):
pacman(pacman),
size(0)
{
    Load();
}

void Maze::Load()
{
    ifstream stream("MAZE-27X27.txt", ios::in);
    
    if(!stream)
    {
        cerr << "Cannot load maze." << endl;
		cout << "Press ENTER to continue" << endl;
		getchar();
		exit(1);
    }
    
    string line;
    int x = 0;
    int y = 0;
    while(getline(stream, line))
    {
        //cout << line << endl;
        string::iterator it = line.begin();

        while(it != line.end())
        {
            Vector2i pos(x, y);
            GameObject* ptr = nullptr;
            char c = *it++;
            switch(c)
            {
                case 'X':
                {
                    ptr = new Wall();
                    ptr->SetPosition(pos);
                    break;
                }
                case '.':
                {
                    PacDots* dot = new PacDots(this);
                    ptr = dot;
                    ptr->SetPosition(pos);
                    dots.push_back(dot);
                    break;
                }
                case 'P':
                {
                    pacman->SetPosition(pos);
                    break;
                }
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                {
                    ptr = new Portal();
                    ptr->SetPosition(pos);
                    ConfigurePortal(static_cast<Portal*>(ptr), c);
                    break;
                }
                case 'G':
                {
                    Ghost* ghost = new Ghost(this);
                    ghost->SetPosition(pos);
                    ghost->SetInitialPosition(pos);
                    ghosts.push_back(ghost);
                    break;
                }
                default:
                    break;
                    
            }
            mazeObjects.push_back(ptr);
            cout << c;
            size = ++x;
            //cout << "size = " << size << endl;
        }
        x = 0;
        ++y;
        cout << endl;
    }
    
    stream.close();
}

void Maze::ConfigurePortal(Portal* portal, char key)
{
    //cout << "Configure portal with key=" << key << endl;
    map<char, pair<Portal*, Portal*>>::iterator it = portals.find(key);
    if(it != portals.end())
    {
        //cout << "Found portal with key=" << key << endl;
        pair<Portal*, Portal*>& portalDuo = it->second;
        if(portalDuo.second == nullptr)
        {
            //cout << "Second portal is null with key=" << key << endl;
            portalDuo.first->SetOther(portal);
            portalDuo.second = portal;
            portal->SetOther(portalDuo.first);
        }
        else
        {
            cerr << "Too many portals for key=" << key << endl;
        }
    }
    else
    {
        pair<Portal*, Portal*> portalDuo = make_pair(portal, nullptr);
        portals.insert(make_pair(key, portalDuo));
    }
}

void Maze::Draw(const GameWindow& windowRef) const
{
    vector<GameObject*> allObjects;
    allObjects.insert(allObjects.end(), mazeObjects.begin(), mazeObjects.end());
    allObjects.insert(allObjects.end(), ghosts.begin(), ghosts.end());
    
    vector<GameObject*>::const_iterator it = allObjects.cbegin();
    while(it != allObjects.cend())
    {
        const GameObject* o = *it++;
        if(o != nullptr)
        {
            o->Draw(windowRef);
        }
    }
	//for (unsigned int x = 0; x < size; ++x)
	//{
	//	for (unsigned int y = 0; y < size; ++y)
	//	{
	//		 GameObject* o = mazeObjects[GetIndex(Vector2i(x, y))];
	//		    if(o != nullptr)
	//		    {
	//		        o->Draw(windowRef);
	//		    }
	//			else
	//			{
	//				windowRef.DrawTileAt(Vector2i(x, y), FL_BLACK);
	//			}
	//	}
	//}
}

void Maze::PhysicStep(double currentTime, double deltaTime)
{
    pacman->Move(currentTime);
    
    GameObject* o = GetObjectAt(pacman->GetPosition());
    if(pacman->Collides(o))
    {
        pacman->OnCollision(o);
        o->OnCollision(pacman);
    }
    
    vector<Ghost*>::iterator it = ghosts.begin();
    while(it != ghosts.end())
    {
        Ghost* ghost = *it++;
        ghost->Move(currentTime);
        
        GameObject* o = GetObjectAt(ghost->GetPosition());
        if(ghost->Collides(o))
        {
            ghost->OnCollision(o);
            o->OnCollision(ghost);
        }
        
        if(pacman->Collides(ghost))
        {
            pacman->OnCollision(static_cast<GameObject*>(ghost));
            ghost->OnCollision(pacman);
        }
    }
}

void Maze::Unload()
{
    cout << "Unload" << endl;
    
    vector<GameObject*> allObjects;
    allObjects.insert(allObjects.end(), mazeObjects.begin(), mazeObjects.end());
    allObjects.insert(allObjects.end(), ghosts.begin(), ghosts.end());
    
    vector<GameObject*>::const_iterator it = allObjects.cbegin();
    while(it != allObjects.cend())
    {
        const GameObject* o = *it++;
        delete o;
    }
}

void Maze::RemoveDot(PacDots* dot)
{
    for( vector<PacDots*>::const_iterator iter = dots.cbegin(); iter != dots.cend(); ++iter )
    {
        if(*iter == dot)
        {
            dots.erase(iter);
            break;
        }
    }
    DeleteObjectAt(dot->GetPosition());
}

int Maze::GetIndex(Vector2i pos) const
{
    return pos.x + pos.y * size;
}

GameObject* Maze::GetObjectAt(Vector2i pos) const
{
    return mazeObjects[GetIndex(pos)];
}

void Maze::DeleteObjectAt(Vector2i pos)
{
    int index = GetIndex(pos);
    delete mazeObjects[index];
    mazeObjects[index] = nullptr;
}

bool Maze::IsWallAt(Vector2i pos) const
{
    Wall* wall = nullptr;
    if(GetObjectAt(pos) != nullptr)
    {
        wall = dynamic_cast<Wall*>(GetObjectAt(pos));
    }
    return wall != nullptr;
}