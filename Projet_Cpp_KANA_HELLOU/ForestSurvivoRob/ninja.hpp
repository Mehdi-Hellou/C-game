#ifndef NINJA_HPP
#define NINJA_HPP

#include "humain.hpp"


// Classe ninja, un personnage que pourra choisir le joueur 

class Ninja : public Humain
{
	
private : 
	Sprite* lance_left; // Sprite correspondant au lancé vers la gauche du kunai 
	Sprite* lance_rigth; // Sprite correspondant au lancé vers la droite du kunai

	Sprite* kunai_left; // Sprite correspondant au dessin du kunai ver la gauche 
	Sprite* kunai_rigth;  //Sprite correspondant au dessin du kunai ver la droite 

	Sprite* epeCollR; // Le sprite correspondant au bout de l'épé, lors de l'attaque du ninja à droite
	Sprite* epeCollL; // Le sprite correspondant au bout de l'épé, lors de l'attaque du ninja à gauche

public:
	Ninja(const std::string& n, const Controls& controls); // Contrusteur du ninja 
	~Ninja(); // destructeur du ninja 

	void init(SDL_Renderer* renderer, int width, int height, int x, int y); //Méthode d'initialisation du ninja 
	void update(const Uint8* state); // Méthode permettant de mettre à jour l'état du ninja : s'il bouge, attaque, ne fais rien, lance un kunai 
	void handleEvents(const Uint8* state); // Méthode permettant de connaître en fonction de la touche qu'on a, l'action que doit faire le ninja 
	void draw(SDL_Renderer* renderer,std::vector<Mechant*> mechants);// Méthode permettant de dessinger les sprites correspondant au  ninja, en fonction de la touche désirée 

	void move(const Uint8* state);// Méthode poour faire bouger le personnage 
	void attaque(); // Méthode pour faire attaquer le personnage 
	int kunai(); // Méthode de lancé de kunai 
	void epe();  // méthode d'attaque à l'épé 
	
	void mort(); // Méthode d'animation de la mort du personnage 

};

#endif