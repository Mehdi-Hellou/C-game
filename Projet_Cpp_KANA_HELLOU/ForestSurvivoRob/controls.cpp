#include "controls.hpp"

Controls::Controls(const Uint8& g, const Uint8& d, const Uint8& a1, const Uint8& a2){
	gauche = g; //Constructeur par copie des valeurs des touches
	droite = d;
	atk1 = a1;
	atk2 = a2;
}

Controls::~Controls(){} //Destructeur vide

void Controls::operator=(Controls* c){ //Operateur permettant de copier les valeurs d'un pointeur sur un Controls
	gauche = c->getGauche(); //On utilise les accesseurs sur l'objet à copier
	droite = c->getDroite();
	atk1 = c->getAtk1();
	atk2 = c->getAtk2();
}

const Uint8& Controls::getGauche(){ //Accesseurs
	return gauche;
}

const Uint8& Controls::getDroite(){
	return droite;
}

const Uint8& Controls::getAtk1(){
	return atk1;
}

const Uint8& Controls::getAtk2(){
	return atk2;
}