#include "../header/player.h"

Player::Player()
{

}

Player::~Player()
{

}

//Thread
void Player::run()
{

}

void Player::jump()
{

}

void Player::draw(char** buffer, Coord bufferSize)
{
    Coord pos;
    Coord tranformedPos = _texture.position+_texture.size;

    for(pos.y = _texture.position.y; pos.y < tranformedPos.y; pos.y++)
    {
        for(pos.x = _texture.position.x; pos.x < tranformedPos.x; pos.x++)
        {
            int textureX = pos.x-_texture.position.x;
            int textureY = pos.y-_texture.position.y;

            if(textureX >= 0 && textureY >= 0)
            {
                char c = _texture.map[textureX][textureY];

                if(c != ' ')
                {
                    if(pos.x <= bufferSize.x && pos.y <= bufferSize.y && pos.x > 0 && pos.y > 0)
                    {
                        buffer[pos.x-1][pos.y-1] = c;
                    }
                }
            }
        }
    }
}

Coord Player::getSize()
{
    return _texture.size;
}

void Player::setPos(Coord pos)
{
    _texture.position = pos;
}

Coord Player::getPos()
{
    return _texture.position;
}