#ifndef TERRAIN_H
#define TERRAIN_H

#include "game2d.h"
#include "obstacle.h"
#include "player.h"
#include "vecteur.h"

class Terrain
{
    public:
    Terrain(Coord size);
    ~Terrain() {}

    Coord getSize();
    void transform(Coord v);
    void draw(char** stream);

    private:
    Vecteur<Texture> _BackgroundTextures;
    Coord _size;
    Coord _pos;
    char** _screenBuffer;
    void drawBackground(char** buffer, Coord pos);
};

#endif