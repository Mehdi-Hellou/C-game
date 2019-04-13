#include "menu.hpp"

#define DIM_X 1280
#define DIM_Y 720

Menu::Menu(){ //On declare le nombre de joueurs a 0
	nJoueurs=0;
}

Menu::~Menu(){ //Liberation de l'espace memoire des differents objets alloues
	delete titre;
	delete combien;
	delete txt_j1;
	delete txt_j2;
}

void Menu::init(SDL_Renderer* renderer){
	TTF_Init(); //On initialise TTF pour utiliser les Textes

 	loadBackground(renderer, "fond.jpg"); //Chargement du fond

 	titre = new Texte("BIENVENUE DANS FOREST SURVIVOROB"); //Declaration du titre, et des textes indicateurs
 	combien = new Texte("A COMBIEN VOULEZ VOUS JOUER ?");
 	txt_j1 = new Texte("1 JOUEUR");
 	txt_j2 = new Texte("2 JOUEURS");

 	titre->init(renderer, "Guardians.ttf", 25, 255, 255 , 255, 270, DIM_Y/4); //Initialisation avec la police Guardians, la taille la couleur et la position de chaque texte
 	combien->init(renderer, "Guardians.ttf", 20, 255, 255 , 255, 330, DIM_Y/2);
 	txt_j1->init(renderer, "Guardians.ttf", 15, 255, 0 , 0, 360, 600);
 	txt_j1->selection(true); //Par defaut, 1 seul joueur est selectionne, c'est pour ca que l'on initialise le texte en rouge
 	txt_j2->init(renderer, "Guardians.ttf", 15, 255, 255 , 255, 760, 600);
}

void Menu::render(SDL_Renderer* renderer){

	//Affichage message accueil + titre
	
	SDL_RenderCopy(renderer, bg_texture, NULL, NULL);
	titre->render(renderer);
	combien->render(renderer);
	txt_j1->render(renderer);
	txt_j2->render(renderer);
	//Affichage choix du nombre de joueurs
}

void Menu::update(){
	titre->update();
	combien->update();
	txt_j1->update();
	txt_j2->update();
	//Update des sprites immobiles
	//Update des couleurs en fonction de la selection 
}

void Menu::handleEvents(){ //Fonction qui gere les evenements et actions 
	SDL_PollEvent(&event);
	switch(event.type){
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym){
				case SDLK_RIGHT://Si on appuie sur la touche fleche droite, on selectrionne j2 qui va passer en rouge et j1 en blanc
					txt_j2->selection(true);
					txt_j1->selection(false);
					break;
				case SDLK_LEFT: //Vice verse
					txt_j2->selection(false);
					txt_j1->selection(true);
					break;
				case SDLK_RETURN: //Si on appuie sur entree, on detecte quel texte est selectionne et cela nous donne le nombre de joueurs a stocker
					if(txt_j1->isSelected())
						nJoueurs=1;
					else
						nJoueurs=2;
				default:
					break;
			}
			break;
		default:
			break;
	}
}

void Menu::close(){
 	SDL_DestroyTexture(bg_texture); //On detruit la texture
}

void Menu::loadBackground(SDL_Renderer* renderer, const char* filename) //Fonction generique
{
	SDL_Surface* tmp_surf;
	tmp_surf = IMG_Load(filename);
	bg_texture = SDL_CreateTextureFromSurface(renderer,tmp_surf);
	SDL_FreeSurface(tmp_surf);
	//std::cout << "Background menu charge" << std::endl;
}

int Menu::getJoueurs(){ //Accesseur du nombre de joueur
	return nJoueurs;
}
