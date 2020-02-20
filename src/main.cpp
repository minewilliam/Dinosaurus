#include "../header/terrain.h"
#include <unistd.h>

Level Level({100,15});

int main(int argc, char** argv)
{
    while(1)
    {
        Level.draw(cout);
        usleep(50000);
        Level.transformTerrain({1,0});
    }
    return 0;
}