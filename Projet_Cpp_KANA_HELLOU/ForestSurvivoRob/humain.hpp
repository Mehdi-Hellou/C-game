#ifndef HUMAIN
#define HUMAIN

#include "perso.hpp"
#include "mechant.hpp"
#include "hud.hpp"
#include "controls.hpp"
#include <vector>


// Classe virtuelle contenant tous les personnages que pourront utiliser les joueurs : ici, le ninja et le magicien 


class Mechant;

class Humain: public Personnage
{
protected:
	std::string nom; // nom du personnage 
	int mana_max; // le mana mac du personnage 
	int mana; // le mana actuelle du personnage 
	Hud* hud; // Le affichages du pv et du mana du personnage 
	Controls* touche; // les touches spécifiques à l'humain 

	int finL; // variable compteur, permet de savoir quand est-ce que l'humain lance son attaque : boule de feu pour le magicien, et kunai pour le ninja 
	int fin; // 
	bool lance; // Permet de savoir si on peut lancer le kunai, lors de l'animation du lancé

public:
	Humain(const std::string& n, const Controls& controls); // Constructeur de l'humain
	~Humain(); // destructeur de L'humain

	virtual void update(const Uint8* state)=0; // méthode permettant de mettre à jour à chaque frame le personnage et son état actuelle 
	virtual void move(const Uint8* state)=0; // méthode permettant de faire bouger le personnage lorqu'on appui sur une touche 
	virtual void attaque()=0; // méthode permettant de faire attaquer le personnage 
	virtual void draw(SDL_Renderer* renderer, std::vector<Mechant*> mechants)=0; // Méthode permettant de dessiner le personnage dans la fenêtre 
	virtual void mort()=0; // méthode permettant de faire l'animation de mort du personnage 
	void move(int x, int y); // Méthode utilisant la fonction move du personnage et faire bouger la barre de vie et du mana 
	void update(); // Méthode permettant de mettre à jour la barre de vie et de mana du personnage
	void regen(); // Méthode permettant de faire regénèrer le mana et les pv du personnage 
};

#endif