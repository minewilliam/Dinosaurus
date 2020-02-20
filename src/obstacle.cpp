#include "../header/obstacle.h"

Obstacle::Obstacle()
{
    next = NULL;
    previous = NULL;
}

void Obstacle::draw(char** buffer, Coord v)
{
    buffer[v.x][v.y] = '0';
}

bool Obstacle::iswithin(Coord v)
{
    Coord localpos = localiseVect(v);
    if(localpos.x >= 0 && localpos.x <= _sprite2D.width && localpos.y >= 0 && localpos.y <= _sprite2D.height)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Coord Obstacle::localiseVect(Coord v)
{
    return {v.x - _sprite2D.position.x, v.y - _sprite2D.position.y};
}

void Obstacle::transform(Coord newposition)
{
    _sprite2D.position += newposition;
}