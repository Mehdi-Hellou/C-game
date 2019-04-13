#ifndef ECRANCHOIX
#define ECRANCHOIX

#include "texte.hpp"
#include "magicien.hpp"
#include "ninja.hpp"
#include "controls.hpp"
#include <vector>

class EcranChoix{
private:
	Sprite* mage;
	Sprite* ninja;

	Texte* mag_txt;
	Texte* ninja_txt;
	Texte* choix;

	SDL_Rect mag_rect;
	SDL_Rect ninja_rect;

	SDL_Texture* bg_texture;
	
	SDL_Event event;

	int nJ, sel;

	std::vector<Humain*> gentils;

public:
	EcranChoix();
	~EcranChoix();

	void loadBackground(SDL_Renderer* renderer, const char* filename);
	void init(SDL_Renderer* renderer, int nJoueurs);
	void render(SDL_Renderer* renderer);
	void update();
	void handleEvents();
	void close();

	void renderRect(SDL_Renderer* renderer, int sel);

	std::vector<Humain*> getTab();
};
#endif