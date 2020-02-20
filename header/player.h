#ifndef PLAYER_H
#define PLAYER_H

#include "game2d.h"

class Player
{
    public:
    Player() {}
    ~Player() {}

    void jump();
    void duck();
    void shoot();

    private:
    Coord Location;
};

#endif