#ifndef GAME2D_H
#define GAME2D_H

#include <fstream>
#include <iostream>
#include <ctime>
#include "vecteur.h"

using namespace std;

struct Vect2d
{
	void operator+=(Vect2d v) {x += v.x; y += v.y;}
    int x, y;
};

struct Sprite2D
{
	int height = 0;
	int width = 0;
	Vect2d position = {0,0};
};

struct Texture : public Sprite2D
{
	Texture(char* name);
	Texture(char* name, Vect2d size);
	~Texture() {}

	void Load();
	void setName(char* name) {_name = name;}
	char* getName() {return _name;}
	Vecteur<char> map;

	private:
	char* _name;
};

#endif