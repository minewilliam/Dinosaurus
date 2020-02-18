#include "../header/game2d.h"

Texture::Texture(char* name)
{
    _name = name;
    ifstream ifs(name);
    height = 0;
    width = 0;
    char c;
    while(ifs >> c)
    {
        width++;
        if(c == '\n') height++;
        map.insert(new char(c));
    }
}

Texture::Texture(char* name, Vect2d size)
{
    _name = name;
    width = size.x;
    height = size.y;
    Load();
}

void Texture::Load()
{
    ifstream ifs(_name);
    char c;
    while(ifs >> c)
    {
        map.insert(new char(c));
    }
}