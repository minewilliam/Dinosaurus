#include "../header/terrain.h"

Terrain::Terrain(Coord size) : _size(size)
{

    _screenBuffer[1][2];
    Texture* ground = new Texture((char*)("assets/groundTexture.txt"));
    _pos = {0,0};
    _BackgroundTextures.insert(ground);

}

Coord Terrain::getSize()
{
    return _size;
}

//draws the screen from top left to bottom right.
void Terrain::draw(char** buffer)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);

    //Top left corner
    
    //Finds first element in the list.
    while(_obstacleList.previous != NULL)
    {
        _obstacleList = *_obstacleList.previous;
    }
    Obstacle* firstObstacle = &_obstacleList;
    Coord pos;
    for(pos.y=0;pos.y <= _size.y; pos.y++)
    {
        for(pos.x=0;pos.x <= _size.x; pos.x++)
        {
            _obstacleList = *firstObstacle;
            

            //Finds every element to the last.
            do
            {
                if(_obstacleList.iswithin(pos))
                {
                    _obstacleList.draw(buffer, pos);
                }
                else
                {
                    if(pos.y == _size.y) drawBackground(buffer, pos);
                }
            }
            while(_obstacleList.next != NULL);
            
        }
    }
}

void Terrain::drawBackground(char** buffer, Coord pos)
{
    int posx = (pos.x+_pos.x)%_BackgroundTextures[0].width;
    buffer[pos.x][pos.y] = _BackgroundTextures[0].map[posx];
}

void Terrain::transform(Coord pos)
{
    _pos += pos;
    while (_obstacleList.previous != NULL);
    do
    {
        _obstacleList.transform({-pos.x,pos.y});
    } while (_obstacleList.next != NULL);
    
}