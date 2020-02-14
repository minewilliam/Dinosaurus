#include "game2d.h"
#include "vecteur.h"
#include "obstacle.h"
#include <ostream>


class Terrain
{
    Terrain() {}
    Terrain(vect2d size) : _size(size) {}
    ~Terrain() {}

    void setSize(vect2d v);
    vect2d getSize();
    void transform()
    void draw(&ostream s);

    private:
    vect2d _size;
    Obstacle _obstacleList;
    Player _player;
    
}