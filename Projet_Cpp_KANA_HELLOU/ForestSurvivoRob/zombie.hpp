#ifndef ZOMBIE
#define ZOMBIE

#include "mechant.hpp"
#include <vector>

class Zombie : public Mechant
{
public:
	Zombie();
	Zombie(int hp, int dmg);
	~Zombie();

	void init(SDL_Renderer* renderer, int width, int height, int x, int y);
	void update(std::vector<Humain*> gentils);
	void draw(SDL_Renderer* renderer, std::vector<Humain*> gentils); 

	void attaque();
	void move(int x, int y);

	void detecter(std::vector<Humain*> gentils); 

	void mort();
	
};

#endif