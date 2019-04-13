#include "interface.hpp"


int main(int argc, char* argv[])
{

	Interface* interface = new Interface(); //Nouvelle interface qui va contenir l'affichage de la partie
	interface->init("Nouveau jeu",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DIM_X, DIM_Y, false); //On initialise l'interface
	while (interface->running()) //Tant qu'elle est active
	{
		interface->handleEvents(); //On gere d'abord les evenements, on l'actualise en fonction de ces derniers puis on l'affiche
		interface->update();
		interface->render();
	}
	interface->clean(); //Si elle n'est plus active, on la nettoie
	delete interface; //On libere son espace memoire

	return 0;
}
