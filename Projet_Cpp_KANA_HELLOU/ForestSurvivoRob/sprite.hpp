#ifndef SPRITE
#define SPRITE

#include <SDL2/SDL.h>        
#include <SDL2/SDL_image.h>        
#include <SDL2/SDL_ttf.h> 
#include <iostream>

#define DIM_X 1280
#define DIM_Y 720

class Sprite
{
protected:
	SDL_Texture* texture;
	SDL_Rect srcRect, dstRect, collider;

	bool anime;
	
	Uint32 animTimer;
	int animSpeed;
	int frame;
	int xFixe;

	int xOffset;
	int yOffset;

public:
	Sprite();
	~Sprite(); 
	Sprite(SDL_Renderer* renderer, const std::string& filename);
	Sprite(SDL_Renderer* renderer, const std::string& filename, Uint32 timer, float speed, float nframe, int xoff);

	void update();
	void init(int src_width, int src_height, int src_x, int src_y, int dst_width, int dst_height, int dst_x, int dst_y);
	void draw(SDL_Renderer* renderer);
	void move(int x, int y);
	void setState(bool b);
	const Uint32& getTimer();
	Uint32 getLaps();
	void setTimer(const Uint32& time);
	SDL_Rect& getRect();
	void setPos(int x, int y);
	bool collision(const SDL_Rect a);

};
#endif