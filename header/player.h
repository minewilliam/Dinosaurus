#ifndef PLAYER_H
#define PLAYER_H

#include "game2d.h"
#include "controller.h"

class Player
{
    private:
    Texture _texture = Texture((char*)"assets/playerTexture.txt",{19,9});
    void run();
    void jump();
    void duck();
    void shoot();

    public:
    Player();
    ~Player();

	Coord getSize();
    Coord getPos();
    void setPos(Coord pos);

    void draw(char** buffer, Coord bufferSize);
};

#endif