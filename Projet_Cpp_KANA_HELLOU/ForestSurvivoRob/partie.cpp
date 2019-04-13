#include "partie.hpp"

Partie::Partie(){}

Partie::Partie(SDL_Renderer* renderer){
	nMechants=6; //Nombre de mechants (a choisir)
	vague=0; //Initilisation du nombre de vague
	for (int i = 0; i < nMechants; ++i) //Ajout des mechants
	{
		Zombie* m = new Zombie();
    	m->init(renderer,120,150, 1000-50*i, 500);
    	stockMechants.push_back(m); //On ajoute des mechants en les initialisants au stock
	}

    Robot* m = new Robot(300,25); //Ajout du boss
    m->init(renderer,240,300, 1000, 350);
    stockMechants.push_back(m); //On stocke le boss a la fin
	
    winTxt = new Texte("VICTORY");
    loseTxt = new Texte("DEFEAT"); //On initialise les textes de fin de partie
    winTxt->init(renderer, "Guardians.ttf", 30, 0, 255, 0, 500, 330);
    loseTxt->init(renderer, "Guardians.ttf", 30, 255, 0, 0, 500, 330);

	running = false; //Le jeu ne tourne pas par defaut
}

Partie::~Partie(){
	for(int i = 0; i < gentils.size(); i++) //On libere les trois tableaux ainsi que les deux textes
	{
		delete gentils[i];
	}
	for (int i = 0; i < mechants.size(); ++i)
	{
		delete mechants[i];
	}
	for (int i = 0; i < stockMechants.size(); ++i)
	{
		delete stockMechants[i];
	}
	delete winTxt;
	delete loseTxt;
}

void Partie::init(SDL_Renderer* renderer){
	for(int i=0; i < gentils.size() ; i++){ //On initialise les gentils a la meme taille et decales de 300 pix
		gentils[i]->init(renderer, 120, 150, i*300, 500);
	}
	nGentils=(int)gentils.size(); //On initialise le nombre de gentils dans la partie
}

void Partie::ajoutHumain(Humain* h)
{
	gentils.push_back(h); //Ajout d'humain dans le vector
}

void Partie::ajoutMechant(Mechant* m)
{
	mechants.push_back(m); //De meme
}

bool Partie::update(const Uint8* state)
{
	std::cout << "gentils = " << nGentils << std::endl;
   	for (int i = 0; i < gentils.size(); i++) //Parcours des gentils
   	{
   		gentils[i]->update(state); //On update les personnages en fonctions des appuie sur les touches des joueurs
   		if(gentils[i]->getPV()<0) //On detecte le nombre de personnage mort pour actualise le nombre de la Partie
   			if(nGentils>0)
   				nGentils--;
   	}
    for (int i = 0; i < mechants.size(); ++i) //On nettoie mechants s'ils sont morts, sinon on les update (sprite)
    {
    	if(mechants[i]->getFin()==3*150)
    		mechants.erase(mechants.begin()+i); 

    	else
			mechants[i]->update(gentils);
    }
    timer=SDL_GetTicks()-startTime; //On update le timer de la vague
}

void Partie::render(SDL_Renderer* renderer){
    std::cout<<timer<<","<<vague<< " , " << stockMechants.size() << " , " << mechants.size() << std::endl;
	
	for (int i = 0; i < gentils.size(); i++) //Si la partie est en cours, on affiche les mechants et les gentils
	    {
	    	gentils[i]->draw(renderer, mechants); 
	    }

	    for (int i = 0; i < mechants.size(); i++)
	    {
	    	mechants[i]->draw(renderer, gentils); 
	    }
	
	if(nGentils<1) //S'il n'y a plus de gentils en jeu, on affiche la defaite et on finit la partie
	{
		loseTxt->render(renderer);
		
		if(timer>10000)
		{
			running=false;
		}
	}
	else if(mechants.size()<1 && vague >= 5)
	{
		winTxt->render(renderer); //S'il n'y a plus de boss, on finit la partie et on indique la victoire
		if(timer>5000)
		{
			running=false;
		}
	}
	else{

	    if(timer>10000 && running){ // Toutes les dix secondes, on declenche le timer de la vague
	    	startTime=SDL_GetTicks();
	    	timer=0;
	    	if (vague<5)
				vague++; //On incremente le numero de la vague
	    	if(mechants.empty() && vague<4) //S'il n'y a pas de mechant et qu'on est pas au boss on transfere un mechant du stock vers la Partie
	    	{
				
		    	for(int i = 0; i < vague; i++)
	    		{
					
	    			nouveauMechant(renderer);
	    		}
		    }
		    else if(vague==4 && mechants.empty()) //On transfert le boss
		    {
		    	nouveauMechant(renderer);
			}
		}
	}
}

bool Partie::isRunning(){ //Retourne l'etat de la partie
	return running;
}

void Partie::runGame(){ //Lance de la partie
	running = true;
	startTime=SDL_GetTicks()+6000;
}

void Partie::nouveauMechant(SDL_Renderer* renderer){ 
	ajoutMechant(stockMechants[0]); //On ajoute le premier mechant du stock
    stockMechants.erase(stockMechants.begin()); //On supprime ce dernier du stock
}
