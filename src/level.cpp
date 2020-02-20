#include "../header/level.h"


Level::Level(Coord size)
{
    _size = size;
    _screenBuffer = new char*[_size.x];
    for(int i = 0; i < _size.x; i++)
    {
        _screenBuffer[i] = new char[_size.y];
    }
    _terrain = Terrain({100,30});
    _obstacle.transform({10,10});

}

Level::~Level()
{

}

void Level::start()
{
    _loop = true;
    run();
}

void Level::stop()
{

}

void Level::run()
{
    while(_loop)
    {

    }
}

void Level::draw()
{
    _terrain.draw(_screenBuffer);

    for(int i = 0; i < )
}
