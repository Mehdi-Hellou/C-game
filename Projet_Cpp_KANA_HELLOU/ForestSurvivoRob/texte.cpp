#include "texte.hpp"

Texte::Texte(const std::string& text){ //Constructeur de base
	txt = text; //Constructeur par copie du string
}

Texte::~Texte(){ //Destructeur
	TTF_CloseFont(police); //On nettoie les differentes structures de SDL utilisees
	SDL_FreeSurface(txtSurf);
	SDL_DestroyTexture(txtTexture);
	//delete txt;
}

void Texte::init(SDL_Renderer* renderer, const std::string& policename, int size, Uint8 r, Uint8 g, Uint8 b, int x, int y){
	police = TTF_OpenFont(policename.c_str(), size); //Ouverture de la polce 
	//color = {r,g,b}; C++11

	color.r = r; //On copie les valeur de la couleur
	color.g = g; 
	color.b = b; 

	txtSurf = TTF_RenderText_Solid(police,txt.c_str(), color); //On convertit le texte en surface de couleur avec la police police
	txtTexture = SDL_CreateTextureFromSurface(renderer,txtSurf); //Conversion en texture afin de pouvoir le renderer
	int texW = 0;
 	int texH = 0;
 	SDL_QueryTexture(txtTexture, NULL, NULL, &texW, &texH); //On recuperer la taille de la texture
 	std::cout << "w = " << texW << ", h = " << texH << std::endl;
 	//dstRect = { x, y, texW, texH };

 	dstRect.x = x; 
 	dstRect.y = y; 
 	dstRect.w = texW; 
 	dstRect.h = texH; 

 	selected = false;
}

void Texte::update(){
	if(selected == true){ //On passe en rouge la couleur si le texte est selectionne, en blanc sinon
		//color = {255,0,0};
		color.r = 255; 
		color.g = 0; 
		color.b = 0; 
	}
	else{
		//color = {255,255,255};
		color.r = 255; 
		color.g = 255; 
		color.b = 255; 
	}
	txtSurf = TTF_RenderText_Solid(police,txt.c_str(), color); //On actualise la surface avec la nouvelle couleur
}

void Texte::render(SDL_Renderer* renderer){
	txtTexture = SDL_CreateTextureFromSurface(renderer,txtSurf); //On actualise la texture
	SDL_RenderCopy(renderer,txtTexture,NULL, &dstRect); //On l'affiche dans dstRect
}

bool Texte::isSelected(){ //Retourne l'etat de selection du texte
	return selected;
}

void Texte::selection(bool t){ //Permet de set l'etat de selection du texte
	selected = t; 
}

void Texte::move(int x, int y) //Fonction de deplacement du texte selon x et y
{
	dstRect.x += x; 
 	dstRect.y += y; 
}
	
