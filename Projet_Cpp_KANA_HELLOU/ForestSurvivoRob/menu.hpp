#ifndef MENU
#define MENU

#include "ninja.hpp"
#include "magicien.hpp"
#include "texte.hpp"

class Menu{
private:
	int nJoueurs;

	Texte* titre;
	Texte* combien;
	Texte* txt_j1;
	Texte* txt_j2;

 	SDL_Texture* bg_texture;
	
	SDL_Event event;

public:
	Menu();
	~Menu();

	void loadBackground(SDL_Renderer* renderer, const char* filename);
	void init(SDL_Renderer* renderer);
	void render(SDL_Renderer* renderer);
	void update();
	void handleEvents();
	void close();

	int getJoueurs();
};

#endif