#ifndef __PACMAN__Portal__
#define __PACMAN__Portal__

#include <iostream>

#include "GameObject.h"

class Portal : public GameObject
{
public:
    Portal();
    void OnCollision(const GameObject* other);
    
    inline const Portal* GetOther() const { return other; }
    inline void SetOther(const Portal* other) { this->other = other; }
    
private:
    const Portal* other;
};

#endif /* defined(__PACMAN__Portal__) */
