#include "statBar.hpp"

StatBar::StatBar(SDL_Renderer* renderer, const std::string& filename): Sprite(renderer,filename){
	pourcent = 100; //Initialisation du pourcentage a 100
}

StatBar::~StatBar(){
}

void StatBar::update(int stat_max, int stat){
	toPer(stat_max,stat); //On actualise le pourcentage de la barre
	if(pourcent<5) //A chaque cran correspond une partie de l'image du fichier de barre de stat, on a essaye de decouper cela en 7 seuils
		srcRect.y=105;
	else if(pourcent<17)
		srcRect.y=90;
	else if(pourcent<31)
		srcRect.y=75;
	else if(pourcent<45)
		srcRect.y=60;
	else if(pourcent<60)
		srcRect.y=45;
	else if(pourcent<74)
		srcRect.y=30;
	else if(pourcent<88)
		srcRect.y=15;
	else
		srcRect.y=0;
}

void StatBar::toPer(int stat_max, int stat)
{
	pourcent = ceil(100*stat/stat_max);
}
