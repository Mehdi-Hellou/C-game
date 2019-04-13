#ifndef ROBOT
#define ROBOT


#include "mechant.hpp"
#include <vector>

class Robot : public Mechant
{
public:
	Robot();
	Robot(int hp, int dmg); 
	~Robot();


	void init(SDL_Renderer* renderer, int width, int height, int x, int y);
	void update(std::vector<Humain*> gentils);
	void draw(SDL_Renderer* renderer, std::vector<Humain*> gentils); 

	void attaque();
	void move(int x, int y);

	void detecter(std::vector<Humain*> gentils); 

	void mort();
	
};
#endif