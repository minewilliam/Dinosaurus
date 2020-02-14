#include "game2d.h"

template<typename T>
struct List
{
	T* next;
    T* previous;
};

class Obstacle{
private:
	sprite2D _sprite2D;
	void LocaliseVect(vect2d v):
	char* _textureName;
public:
	Obstacle(vect2d v, char* textureName);
	~Obstacle();
	
	List<Obstacle> list;

	void settexture(char* textureName);
	void transform(vect2d newposition);
	void draw(ostream& os, vect2d v);
	bool iswithin(vect2d v);

};