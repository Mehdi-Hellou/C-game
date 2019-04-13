#ifndef HUD
#define HUD
#include "sprite.hpp"
#include "statBar.hpp"
#include "texte.hpp"

class Hud
{
private:
	SDL_Rect box, hpRect, manaRect;
	StatBar* hpBar, *manaBar;
	SDL_Texture* hpTxt, *manaTxt;
	SDL_Surface* loadSurf;
	Texte* name_txt;

public:
	Hud(SDL_Renderer* renderer, const std::string& hpBar_fname, const std::string& manaBar_fname, const std::string& name);
	~Hud();

	void init(SDL_Renderer* renderer, int pv_max, int pv, int mana_max, int mana, int width, int height, int x, int y);

	void draw(SDL_Renderer* renderer);
	void update(int pv, int pv_max, int mana, int mana_max);
	void move(int x, int y);
};

#endif
