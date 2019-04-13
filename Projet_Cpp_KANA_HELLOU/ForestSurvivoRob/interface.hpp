#ifndef INTERFACE
#define INTERFACE

#include "partie.hpp"
#include "menu.hpp"
#include "ecranChoix.hpp"

class Interface
{
	public:
		Interface();
		~Interface();

		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

		void handleEvents();
		void update();
		void render();
		void clean();

		void loadBackground(const char* filename);	

		bool running();

	private:
		bool isRunning;
		bool isChoosing;
		bool isPlaying;

		int nJoueurs;

		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Texture* bg_texture;
		SDL_Event event;

		Partie* game;
		Menu* menu;
		EcranChoix* choix;

		const Uint8 *state;
};
#endif