#include "../header/terrain.h"
#include <unistd.h>

Terrain terrain;

int main(int argc, char** argv)
{
    terrain.setSize({100,15});
    ostream &s = cout;
    while(1)
    {
        terrain.draw(s);
        usleep(50000);
        terrain.transform({1,0});
    }
    return 0;
}