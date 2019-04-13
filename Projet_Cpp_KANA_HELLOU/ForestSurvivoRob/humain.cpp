#include "humain.hpp"
 // Constructeur d'un Humain
Humain::Humain(const std::string& n, const Controls& controls): Personnage(){
	touche = new Controls(controls); // On assigne des touches au personnage 
    nom = n; // On assigne le nom n des personnages 
}

// Destructeur du personnage 
Humain::~Humain(){
	delete hud;
	delete immobileL; 
}

void Humain::move(int x, int y){
	Personnage::move(x,y); // nous faisons bouger les sprites du personnages
	hud->move(x,y); // nous faisons bouger la barre de vie et de mana du personnage 
}

void Humain::update()
{
	hud->update(pv_max, pv, mana_max, mana); // Mettre à jour la barre de vie et de mana du personnage 
	regen();// faire regénérer la barre de vie et de mana du personnage 
}

// Méthode de regènération du mana et de vie du personnage 

void Humain::regen(){
	if(SDL_GetTicks()%1000==0) // Toutes les secondes nous vérifions que :
	{
		if(mana<mana_max) // si le mana est inférieur à man_max 
			mana+=3; // on rajoute 3 au mana
		if(pv<pv_max)// si la vie est inférieur à pv_max 
			pv+=2; // on rajoute 2 à la barre de vie
	}
}