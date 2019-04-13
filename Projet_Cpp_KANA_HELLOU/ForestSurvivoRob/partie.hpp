#ifndef PARTIE
#define PARTIE

#include "magicien.hpp"
#include "ninja.hpp"
#include "zombie.hpp"
#include "robot.hpp"
#include "texte.hpp"
#include <vector>

class Partie
{
private:
	bool running;
	std::vector<Humain*> gentils;
	std::vector<Mechant*> mechants;
	std::vector<Mechant*> stockMechants;
	int nMechants;
	int nGentils;
	int vague;
	Uint32 timer, startTime;
	Texte* winTxt, *loseTxt;

public:
	Partie();
	Partie(SDL_Renderer* renderer);
	~Partie();

	void ajoutHumain(Humain* h);
	void ajoutMechant(Mechant* m);

	void init(SDL_Renderer* renderer);
	bool update(const Uint8*);
	void render(SDL_Renderer* rend);
	bool isRunning();
	void runGame();
	void nouveauMechant(SDL_Renderer* renderer);
};
#endif