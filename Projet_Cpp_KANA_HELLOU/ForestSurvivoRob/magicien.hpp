#ifndef MAGICIEN_HPP
#define MAGICIEN_HPP

#include "humain.hpp"


class Magicien : public Humain
{
private:
	Sprite* bdf_r, *bdf_l;

public:
	Magicien(const std::string& n, const Controls& controls);
	~Magicien();

	void init(SDL_Renderer* renderer, int width, int height, int x, int y);
	void update(const Uint8* state);
	void handleEvents(const Uint8* state);
	void draw(SDL_Renderer* renderer, std::vector<Mechant*> mechants);

	void move(const Uint8* state);
	void attaque();
	void mort();
	
	void tempete();
	int bouleDeFeu();
};
#endif