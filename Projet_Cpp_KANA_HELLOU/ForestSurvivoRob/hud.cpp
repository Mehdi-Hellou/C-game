#include "hud.hpp"

Hud::Hud(SDL_Renderer* renderer, const std::string& hpBar_fname, const std::string& manaBar_fname, const std::string& name)
{
	hpBar = new StatBar(renderer, hpBar_fname); //On declare les nouvelles barres avec leurs noms de fichier
	manaBar = new StatBar(renderer, manaBar_fname);
	name_txt = new Texte(name);
}

Hud::~Hud(){
	delete hpBar; //On les efface
	delete manaBar;
	delete name_txt;
}

void Hud::init(SDL_Renderer* renderer, int pv_max, int pv, int mana_max, int mana, int width, int height, int x, int y)
{
	hpBar->init(100, 15, 0,  0, width/2, height/15, x+30, y-25);
	manaBar->init(100, 15, 0,  0, width/2, height/15, x+30, y-10); //Initialisation des barres en fonction de la position du personnage
	name_txt->init(renderer, "Guardians.ttf", 15, 255, 255, 255, x, y-55); //Initialisation du texte au dessus du personnage
}

void Hud::update(int pv_max, int pv, int mana_max, int mana)
{
	hpBar->update(pv_max, pv); //On actualise les barres en fonctions des stats
	manaBar->update(mana_max, mana);
}

void Hud::draw(SDL_Renderer* renderer){ //Affichage des barres et du nom
	hpBar->draw(renderer);
	manaBar->draw(renderer);
	name_txt->render(renderer);
}

void Hud::move(int x, int y){ //On bouge les objets avec le personnage
	hpBar->move(x,y);
	manaBar->move(x,y);
	name_txt->move(x,y);
}
