#include "perso.hpp"

// Constructeur du personnage 
Personnage::Personnage(){
	n_attack=0;  // De base le personnage n'attaque pas. 
}

// destructeur du personnage, nous détruisons tous les sprites initialiser avec le constructeur 

Personnage::~Personnage(){
	delete right;
	delete left;
	delete atk_right;
	delete atk_left;
	delete immobile;
	delete deadR; 
	delete deadL; 
}
// Méthode pour faire bouger le personnage, nous faisons mouvoir tous les sprites spécifiques au personnage 
void Personnage::move(int x, int y){
	right->move(x,y);
	left->move(x,y);
	atk_right->move(x,y);
	atk_left->move(x,y);
	immobile->move(x, y); 
	immobileL->move(x,y); 
	deadR->move(x,y);
	deadL->move(x,y);
}

void Personnage::encaisse(int degats){
    pv-=degats;    // les PV du personnage subissent les dégats qu'ils reçoient 
}