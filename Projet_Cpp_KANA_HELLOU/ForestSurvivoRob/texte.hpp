#ifndef TXT
#define TXT

#include <SDL2/SDL_ttf.h> 
#include <string>
#include <iostream>

class Texte{
private:
	std::string txt;
	TTF_Font* police;
	SDL_Color color;
 	SDL_Surface* txtSurf;
 	SDL_Texture* txtTexture;
 	SDL_Rect dstRect;
 	bool selected;

public:
	Texte(const std::string& text);
	~Texte();

	void init(SDL_Renderer* renderer, const std::string& policename, int size, Uint8 r, Uint8 g, Uint8 b, int x, int y);
	void render(SDL_Renderer* renderer);
	void update();

	void changeColor(Uint8 r, Uint8 g, Uint8 b);
	bool isSelected();
	void selection(bool t);
	void move(int x, int y);
};
#endif
