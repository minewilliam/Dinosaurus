#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "game2d.h"

template<typename T>
struct List
{
	T* next;
    T* previous;
};

class Obstacle : public List<Obstacle>
{
private:
	Sprite2D _sprite2D;
	Coord localiseVect(Coord v);
	char* _textureName;
public:
	Obstacle();
	Obstacle(Coord v, char* textureName) ;
	~Obstacle() {}
	void RandomObstacle(char);
	void settexture(char* textureName);
	void transform(Coord newposition);
	void draw(char** buffer, Coord v);
	bool iswithin(Coord v);

};

#endif