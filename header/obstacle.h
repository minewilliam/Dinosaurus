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
	Vect2d localiseVect(Vect2d v);
	char* _textureName;
public:
	Obstacle();
	Obstacle(Vect2d v, char* textureName) {}
	~Obstacle() {}

	void settexture(char* textureName);
	void transform(Vect2d newposition);
	void draw(ostream &os, Vect2d v);
	bool iswithin(Vect2d v);

};

#endif