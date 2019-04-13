#ifndef PERSO
#define PERSO
#include "sprite.hpp"
#include "controls.hpp"

/**

Classe virtuelle de notre programme ayant pour classe fille, les méchants et gentils 
*/
class Personnage{
	protected:
		Sprite* left, *right, *atk_right, *atk_left, *immobile, *immobileL, *deadR, *deadL; // Sprite correspondant aux actions principales marcher à droite, à gauche, attaquer à gauche, à droite 
																							// être immobile à gauche, à droite et mourir à gauche et à droite 
		int sens; // variable permettant de savoir le sens du personnage lorsqu'il bouge 
		int n_attack;// varibale permettant de connaitre le type de l'attaque qu'éxécute le personnage 	
		int sensPrec;// variable utile pour le sens du personnage lorsqu'il est immobile ou qu'il attaque

		int pv_max; // les pv maximums du personnage 
		int pv; // les pv actuels du peronnage 	
		int niveau; // le niveau du personnage 	
		int exp; // les EXP que gagnent le personnage à chaque fois qu'il tue un ennemie 
		int atk; // la valeur de l'attaque du personnage 
		int def;  // la valeur de la défense du personnage 

		int fin; // variable utile pour l'animation de la mort d'un perso lorsqu'il n'a plus de pv

	public:
		Personnage(); 
		~Personnage();


		virtual void init(SDL_Renderer* renderer, int width, int height, int x, int y)=0; // méthode pour créer un personnage 
		virtual void mort()=0;  // méthode lorqu'un personnage meurt
		void encaisse(int degats); // méthode lorsq'un personnage subit une attaque 

		void move(int x, int y); // méthode pour faire bouger notre personnage dans la fenêtre 	

		SDL_Rect& getCollider(){ // retourne le rectangle de collision, correspondant au sprite du personnage
			return right->getRect(); 
		}
		const int& getPV(){ // /retourne les pv du personnage
			return pv;
		}
};

#endif