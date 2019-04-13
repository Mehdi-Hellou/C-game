#ifndef STATBAR
#define STATBAR

#include "sprite.hpp"
#include <cmath>

class StatBar: public Sprite
{
private:
	int pourcent;

	void toPer(int stat_max, int stat);
public:
	StatBar(SDL_Renderer* renderer, const std::string& filename);
	~StatBar();
	void update(int stat_max, int stat);
};
#endif