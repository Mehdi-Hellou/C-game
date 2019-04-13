#include "ecranChoix.hpp"

EcranChoix::EcranChoix(){	
	mage = NULL; //On initialise les pointeurs vers les Sprite à NULL afin de ne pas avoir de problème d'adressage
	ninja = NULL;
}

EcranChoix::~EcranChoix(){ //On libère la mémoire sur tous les objets créés
	gentils.clear();
	delete mage;
	delete ninja;

	delete mag_txt;
	delete ninja_txt;
	delete choix;
}

void EcranChoix::init(SDL_Renderer* renderer, int nJoueurs)
{
	TTF_Init(); // Initialisation de TTF (texte, couleur, ...)

	nJ=nJoueurs; //On copie la valeur du nombre de joueurs qui veulent jouer

 	loadBackground(renderer, "fond.jpg"); //Chargement du fond 

	mage = new Sprite(renderer, "Wizard/immobile.png", -1, 150, 5, 20); //On initialise les sprites immobile qui vont permettre aux joueurs de visualiser les personnages disponibles
	ninja = new Sprite(renderer, "Ninja/Immobile.png", -1, 100, 10, 0);

	mage->init(387, 370, 0, 0, 140, 160, 300 , 500); //Initialisation avec taille et position
	ninja->init(252, 459, 0, 0, 120, 150, 900, 500);

	int xoff = 15; //Ces offsets permettent de créer un rectangle en fonction de la taille de l'image
	int yoff = 20;
	//mag_rect = {300-xoff, 500-yoff, 140+2*xoff, 160+2*yoff}; C++11
	mag_rect.x = 300-xoff; 
 	mag_rect.y = 500-yoff; 
 	mag_rect.w = 140+2*xoff; 
 	mag_rect.h = 160+2*yoff; 

	//ninja_rect = {900-xoff, 500-yoff, 120+2*xoff, 150+2*yoff}; C++11
	ninja_rect.x = 900-xoff; 
 	ninja_rect.y = 500-yoff; 
 	ninja_rect.w = 120+2*xoff; 
 	ninja_rect.h = 150+2*yoff; 

	mag_txt = new Texte("Magicien"); //On crée de nouveau texte à afficher à l'écran, deux qui donnent la classe du personnage et un qui indique que J1 choisit toujours
 	ninja_txt = new Texte("Ninja");
 	choix = new Texte("J1 choisit");

 	mag_txt->init(renderer, "Guardians.ttf", 20, 255, 255, 255, 290, 430); //Initialisation des textes avec la police, la taille, la couleur et la position
 	mag_txt->selection(true); //On décide que "Magicien" est selectionne par defaut
 	ninja_txt->init(renderer, "Guardians.ttf", 20, 255, 255, 255, 910, 430);
 	choix->init(renderer, "Guardians.ttf", 25, 255, 255, 255, 520, DIM_Y/4);

 	sel=0; //Sel indique le texte selectionne, zero = "Magicien"
}

void EcranChoix::update(){ //On anime les sprites
	mag_txt->update();
	ninja_txt->update();
	mage->update();
	ninja->update();
}

void EcranChoix::handleEvents(){
	SDL_PollEvent(&event); //On check l'event
	Controls* c2; //Definition de deux pointeurs pour d'eventuels Controls 
	Controls* c1;
	switch(event.type){
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym){ //Si une touche est appuyée, on détecte si c'est droite, gauche ou entrée
				case SDLK_RIGHT:
					ninja_txt->selection(true); //Si droite, on dit que Ninja est selectionné et magicien non
					mag_txt->selection(false);
					sel=1;
					break;
				case SDLK_LEFT:
					ninja_txt->selection(false); //Inverse
					mag_txt->selection(true);	
					sel=0;
					break;
				case SDLK_RETURN:
					c1 = new Controls(SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_RSHIFT, SDL_SCANCODE_N); //Entrée implique que l'on choisi le personnage sur lequel on se trouve
					if(mag_txt->isSelected()) //On verifie quel personnage est selectionne, on lui attribue les Controls
						gentils.push_back(new Magicien("Gandalf", *c1)); //On copie les controls dans le constructeur
					else
						gentils.push_back(new Ninja("Maitre Yi", *c1));
					if(nJ>1) //Si un deuxieme joueur joue, on lui attribue les Controls restants
					{
						c2 = new Controls(SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_Q, SDL_SCANCODE_E); 
						if(mag_txt->isSelected()){
							gentils.push_back(new Ninja("Maitre Yi", *c2));
						}
						else{
							gentils.push_back(new Magicien("Gandalf", *c2));
						}
						delete c2; //On peut donc liberer la memoire des maintenant
					}
					delete c1; //De meme
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}

void EcranChoix::render(SDL_Renderer* renderer){
	SDL_RenderCopy(renderer, bg_texture, NULL, NULL); //Affichage préalable du bg
	renderRect(renderer,sel); //Appel de la fonction de rendu des rect
    mag_txt->render(renderer); //On rend les personnage et les textes
    ninja_txt->render(renderer);
    choix->render(renderer);
	mage->draw(renderer);
	ninja->draw(renderer);
}

void EcranChoix::loadBackground(SDL_Renderer* renderer, const char* filename){ //Fonction generique
	SDL_Surface* tmp_surf; 
	tmp_surf = IMG_Load(filename);
	bg_texture = SDL_CreateTextureFromSurface(renderer,tmp_surf);
	SDL_FreeSurface(tmp_surf);
	std::cout << "Background menu charge" << std::endl;
}

void EcranChoix::close(){ //On detruit la texture allouee par SDL
	SDL_DestroyTexture(bg_texture);
}

void EcranChoix::renderRect(SDL_Renderer* renderer, int sel){
	if(sel == 0){ //On dessine un rectangle jaune en fonction du texte selectionne
		SDL_SetRenderDrawColor(renderer, 255, 200, 20, 100);
    	SDL_RenderFillRect(renderer, &mag_rect);
	}
	else{
		SDL_SetRenderDrawColor(renderer, 255, 200, 20, 100);
    	SDL_RenderFillRect(renderer, &ninja_rect);
	}
}

std::vector<Humain*> EcranChoix::getTab(){ //On retourne la liste des gentils qui a été déclarée
	return gentils; 
}
