#include "../header/terrain.h"

Terrain::Terrain()
{
    Texture* ground = new Texture((char*)("assets/groundTexture.txt"));
    _pos = {0,0};
    _BackgroundTextures.insert(ground);
}

Terrain::Terrain(Vect2d size) : _size(size)
{

}

void Terrain::setSize(Vect2d v)
{
    _size = v;
}

Vect2d Terrain::getSize()
{
    return _size;
}

//draws the screen from top left to bottom right.
void Terrain::draw(ostream &s)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);

    //Top left corner
    Vect2d pos = {0,_size.y};
    for(;pos.y >= 0; pos.y--)
    {
        pos.x = 0;

        //Finds first element in the list.
        while(_obstacleList.previous != NULL)
        {
            _obstacleList = *_obstacleList.previous;
        }

        for(;pos.x < _size.x; pos.x++)
        {
            if(pos.y == 0) drawBackground(s, pos);
            else
            {
                s << " ";
            }
            

            //Finds every element to the last.
            // do
            // {
            //     if(_obstacleList.iswithin(pos))
            //     {
            //         _obstacleList.draw(s, pos);
            //     }
            //     else
            //     {
            //         s << " ";
            //     }
            // }
            // while(_obstacleList.next != NULL);
            
        }
        s << endl;
    }
}

void Terrain::drawBackground(ostream &s, Vect2d pos)
{
    int posx = (pos.x+_pos.x)%_BackgroundTextures[0].width;
    s << _BackgroundTextures[0].map[posx];
}

void Terrain::transform(Vect2d pos)
{
    _pos += pos;
}