#ifndef OBSTACLE_H
#define OBSTACLE_H
#define CAPACITE 4
#include "game2d.h"
static char* tab[CAPACITE] = {"assets/cactusTexture.txt","assets/cactusTexture1.txt","assets/cactusTexture2.txt","assets/cactusTexture3.txt"};
template<typename T>
struct List
{
	T *firstItem
	int size  =0;
};

class Obstacle : public List<Obstacle>
{
private:
	Sprite2D _sprite2D;
	Coord localiseVect(Coord v);
	char* _textureName;
public:
	int nombre;
	Obstacle *next;
	Obstacle *previous;
	Obstacle();
	Obstacle(Coord v, char* textureName) ;
	~Obstacle();
	void RandomObstacle();
	void RandomObstacle(char);
	void settexture(char* textureName);
	void transform(Coord newposition);
	void draw(char** buffer, Coord v);
	bool iswithin(Coord v);

};

#endif