#ifndef MECHANT
#define MECHANT

#include "perso.hpp"
#include "statBar.hpp"
#include "humain.hpp"
#include <vector>

class Humain; 

class Mechant: public Personnage
{
protected:
	StatBar* hpBar;
	Sprite* atkCollR; 
	Sprite* atkCollL;  
	
	int fin; 

public:
	Mechant();
	//Mechant(int hp, int dmg);
	~Mechant();

	virtual void init(SDL_Renderer* renderer, int width, int height, int x, int y)=0;
	virtual void update(std::vector<Humain*> gentils)=0;
	virtual void draw(SDL_Renderer* renderer, std::vector<Humain*> gentils)=0; 

	virtual void attaque()=0;
	virtual void move(int x, int y)=0;

	virtual void detecter(std::vector<Humain*> gentils)=0; 

	virtual void mort()=0; 

	int getFin(){
		return fin;
	}

};

#endif