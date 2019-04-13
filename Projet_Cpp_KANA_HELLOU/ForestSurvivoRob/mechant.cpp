#include "mechant.hpp"

/*!

	Constructeur du méchant  

*/

Mechant::Mechant(){
    niveau = 1; // on intialise le niveau à 1
    exp=0; // son Xp à 0 
    sens = -1; // son sens à -1  car les méchants sont crées vers la droite de l'écran et doit donc marcher vers la gauche pour arriver jusqu'au gentil 
    sensPrec = -1;  // de même pour sensPrec
    fin = 0; // fin à 0 car le méchant n'est pas encore mort 
}
/*!
	Destructeur des collisions d'attaques pour le méchant 
*/
Mechant::~Mechant(){
    delete atkCollR; 
    delete atkCollL; 
}

