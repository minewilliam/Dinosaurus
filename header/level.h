#include "game2d.h"
#include "terrain.h"
#include "player.h"
#include "obstacle.h"
#include "controller.h"

class Level
{
    public:
    Level(Coord size);
    ~Level();

    void start();
    void stop();

    void transformTerrain(Coord v);

    private:
    Obstacle _obstacle;
    Player _player;
    Terrain _terrain;
    Controller _controller;
    Coord _size;
    char** _screenBuffer;
    bool _loop;
    void run();
    void draw();
};