#include "interface.hpp"

Interface::Interface(){
	state = SDL_GetKeyboardState(NULL);
	nJoueurs = 0;
}

Interface::~Interface(){
	delete game; //On libere la partie, le menu et l'ecran de choix
	delete menu;
	delete choix;
}

void Interface::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags=0; //flag pour l'etat de l'ecran
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN; //fullscreen si le lag correspond
	}
	SDL_Init(SDL_INIT_VIDEO); //Initialisation de la video
	window = SDL_CreateWindow(title, xpos, ypos, width, height,flags); //Creation de la fenetre
	
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0) //Initialisation du reste de SDL
	{
		if(window) //Si la fenetre marche
		{
			std::cout << "Fenetre creee" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if(renderer) //On peut declarer le renderer
		{
			int flags = 0;
			std::cout << "Renderer cree" << std::endl;
			loadBackground("fond.jpg"); //Chargement du fond
		}
		menu = new Menu(); //Declaration du menu
		menu->init(renderer); //Initialisation 
		isChoosing = false; //On ne choisit pas encore, on ne joue pas et l'interface tourne
		isPlaying = false;
		isRunning = true;
	}
	else
		isRunning = false;
}


void Interface::loadBackground(const char* filename) //Fonction qui charge le fond
{
	SDL_Surface* tmp_surf; //Declaration d'une surface temporaire
	tmp_surf = IMG_Load(filename); //On charge le fichier du fond
	bg_texture = SDL_CreateTextureFromSurface(renderer,tmp_surf); //On convertit la surface en texture
	SDL_FreeSurface(tmp_surf); //On libere la surface
	std::cout << "Background charge" << std::endl;
}

void Interface::handleEvents() //Fonction qui gere les evenements
{
	nJoueurs = menu->getJoueurs(); //On recupere le nombre de joueur dans le menu a chaque tour
	if(nJoueurs<1){ //Tant qu'on en a aucun, on continue de gerer le menu
		menu->handleEvents();
	}
	else if(!isChoosing && !isPlaying){ //Si l'on pas choisit son personnage et que la partie n'est pas lancee mais que le choix du nombre de joueur est effectue
		choix = new EcranChoix(); //On declare et initialise l'ecran de choix
		choix->init(renderer, nJoueurs);
		isChoosing = true; //On choisit
	}
	else if(!isPlaying){ //Sinon tant qu'on ne joue pas
		choix->handleEvents(); //On gere les evenement du choix du personnage
			if(!choix->getTab().empty()) //Si la liste de personnage de l'ecran n'est pas vide, on va charger la partie
			{
				isChoosing = false; //Arrete du choix
				game = new Partie(renderer); //Declaration de la partie
				for(int i = 0; i < choix->getTab().size(); i++){ //Copie des joueurs
					game->ajoutHumain(choix->getTab()[i]);
				}
				game->init(renderer); //Initialisation de la partie
				isPlaying=true; //L'interface sait que la partie tourne
				game->runGame(); //La partie tourne
			}
	}

	SDL_PollEvent(&event); //On check l'etat de l'evenement afin de fermer la fenetre si on ATL F4 ou clic sur la croix
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
        }
}

void Interface::update(){ //Fonction qui actualise l'etat de l'interface
	if(nJoueurs<1) //Tant que l'on a pas choisi le nombre de joueurs, on update le menu
		menu->update();
	else if(isChoosing){ //Sinon on update l'ecran de choix
		choix->update();
	}
	else if(isPlaying){ //Si la partie est lancee, on update la partie
		game->update(state);
		if (!game->isRunning()) //Si on detecte que la partie n'est plus active, on dit a l'interface de ne plus l'etre egalement
		{
			isRunning=false;
		}
	} 
}

void Interface::render() //Fonction d'affichage
{
	SDL_RenderClear(renderer); //On nettoie l'ecran
	if(nJoueurs<1) //Memes conditions que la fonction update
		menu->render(renderer);
	else if(isChoosing)
		choix->render(renderer);
	else if(isPlaying)
	{
		SDL_RenderCopy(renderer, bg_texture, NULL, NULL); //On affiche le fond, puis la partie par dessus (cela permet de changer le fond facilement a partir de l'interface)
		game->render(renderer);
	}
	SDL_RenderPresent(renderer); //On affiche le tout
}

void Interface::clean() //Fonction de nettoyage
{
	menu->close(); //On close le menu, l'ecran de choix
	choix->close();
	SDL_RenderClear(renderer); //On libere la memoire sur les structures SDL utilisees
	SDL_DestroyTexture(bg_texture);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit(); //On quitte les differents modules de SDL
	IMG_Quit();
	TTF_Quit();
	std::cout << "Interface nettoyee" << std::endl;
}

bool Interface::running()
{
	return isRunning; //Retourne l'etat d'activité de l'interface
}
