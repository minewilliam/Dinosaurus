#ifndef TERRAIN_H
#define TERRAIN_H

#include "game2d.h"
#include "obstacle.h"
#include "player.h"
#include "vecteur.h"


class Terrain
{
    public:
    Terrain();
    Terrain(Vect2d size);
    ~Terrain() {}

    void setSize(Vect2d v);
    Vect2d getSize();
    void transform(Vect2d v);
    void draw(ostream &s);

    private:
    Vecteur<Texture> _BackgroundTextures;
    Vect2d _size;
    Obstacle _obstacleList;
    Player _player;
    Vect2d _pos;
    void drawBackground(ostream &s, Vect2d pos);
};

#endif