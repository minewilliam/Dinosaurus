#include "../header/obstacle.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
Obstacle::Obstacle()
{
    Coord V;
    V.x =0;
    V.y =0;
    settexture(tab[0]);
    nombre =1;

}
Obstacle::~Obstacle(){
    delete []_textureName;
    delete next;
    delete previous;
 
}
void Obstacle::RandomObstacle()
{
    Obstacle *newObstacle = new Obstacle();
    next = newObstacle;
    newObstacle->previous = this;
}
Obstacle::Obstacle(Coord v, char* textureName)
{
   
    settexture(textureName);
    transform(v);
}

void Obstacle::settexture(char* textureName){
    _textureName = textureName;

}
void Obstacle::draw(char* buffer, Coord v)
{
    ifstream inFile;
    char c;
    int v1 = rand()%CAPACITE;
    inFile.open(tab[v1],ios_base::in);
    for (int i = 0; i < v.x; i++)
    {
        for (int j = 0; j < v.y; j++)
        { 
            c= NULL;
           inFile>> noskipws >>c;
           *buffer =c;
           
           cout<< c;
          
           buffer++;
        }
        
    }
    inFile.close();
}

bool Obstacle::iswithin(Coord v)
{
    Coord localpos = localiseVect(v);
    if(localpos.x >= 0 && localpos.x <= _sprite2D.width && localpos.y >= 0 && localpos.y <= _sprite2D.height)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Coord Obstacle::localiseVect(Coord v)
{
    return {v.x - _sprite2D.position.x, v.y - _sprite2D.position.y};
}

void Obstacle::transform(Coord newposition)
{
    _sprite2D.position += newposition;
}
/*
int main(int argc, char** argv)
{
    Coord V;
    V.x =11;
    V.y =8;
    char *buffer = new char[V.x*V.y];
    List<Obstacle> *Obs_List = new List<Obstacle>;
    Obstacle *obs1 = new Obstacle();
    Obs_List->firstItem = obs1;
    Obs_List->firstItem->RandomObstacle();
    cout<< Obs_List->firstItem->nombre<<endl;
    cout<< Obs_List->firstItem->next->nombre<<endl;
    cout<< Obs_List->firstItem->next->previous->nombre<<endl;
    Obs_List->firstItem->RandomObstacle();
    Obs_List->firstItem->RandomObstacle();
    Obs_List->firstItem->RandomObstacle();
    for (int i = 0; i < 4; i++)
    {

        Obs_List->firstItem->next++->draw(buffer,V);
        cout<<endl;
    }
    
}
*/


