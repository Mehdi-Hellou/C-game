#include "magicien.hpp"
int timeKey=0;// compteur des touches qui vérifient qu'on ne touche pas plusieurs fois l'ennemie lors de l'animation d'une attaque 
/*!

Constructeur du magicien 
 * \param n : Le nom du magicien 
        controls : les controls assimilés au personnage qui change si le joueur qui le controle est le joueur 1 ou 2 
*/

Magicien::Magicien(const std::string& n, const Controls& controls): Humain(n, controls){
	pv_max = 70; 
	pv = pv_max; 
	niveau = 1; 
	exp=0; 
	atk = 5; 
	def = 2; 
	mana_max = 50;
	mana = mana_max;
    sens = 1; 
    sensPrec = 1; 
}

/**

    Le destructeur des sprites correspondant au lancé de boule de feu  
**/
Magicien::~Magicien(){
    delete bdf_r;
    delete bdf_l;
}

/*!

L'initialisation du magicien 
 * \param renderer : La fenêtre dans laquelle notre personnage est initialisé
          width  : la largeur du personnage que nous souhaitons avoir.
          height : la hauteur du personnage que nous souhaitons avoir.
          x : sa positions en x initiale lorsque le jeu commence. 
          y : sa positions en y initiale lorsque le jeu commence. 
*/

void Magicien::init(SDL_Renderer* renderer, int width, int height, int x, int y)
{
	right = new Sprite(renderer, "Wizard/SpritesMagDroite.png", -1, 100, 5, 25);// On charge le sprite correŝpondant marché vers la droite du magicien
    left = new Sprite(renderer, "Wizard/SpritesMagGauche.png", -1, 100, 5, 25); // On charge le sprite correŝpondant marché vers la gauche du magicien
    atk_right = new Sprite(renderer, "Wizard/SpritesMagDroiteAtk.png", -1, 150, 5, 25);// On charge le sprite correŝpondant à l'attaque vers la droit
    atk_left = new Sprite(renderer, "Wizard/SpritesMagGaucheAtk.png", -1, 150, 5, 25);// On charge le sprite correŝpondant à l'attaque vers la gauche du ninja
    immobile = new Sprite(renderer, "Wizard/immobile.png", -1, 100, 5, 20);  // On charge le sprite correŝpondant à l'animation immobile droite
    immobileL = new Sprite(renderer, "Wizard/immobileL.png", -1, 100, 5, 20); // On charge le sprite correŝpondant à l'animation immobile gauche
    bdf_r= new Sprite(renderer,"fireBall_r.png"); // On charge le sprite correspondant à la boule de feu vers la droite
    bdf_l= new Sprite(renderer,"fireBall_l.png");// On charge le sprite correspondant à la boule de feu vers la gauche 
    hud = new Hud(renderer,"healthmeter.png", "manameter.png",nom); // On charge le sprite correŝpondant à la barre de vie et de mana 
    deadR = new Sprite(renderer,"Wizard/deadR.png", -1, 200,5,20); // On charge le sprite correŝpondant à l'animation de mort vers la droite
    deadL = new Sprite(renderer,"Wizard/deadL.png", -1, 200,5,20);// On charge le sprite correŝpondant à l'animation de mort vers la gauche 

    // Nous intialisons les différents sprites suivant la taille de chaque image que nous avons téléchargé 
    right->init(419, 381, 0, 0,width,height,x,y);
    left->init(419, 381, 0, 0,width,height,x,y);

    atk_right->init(685, 474, 0, 0, width*685/419,height*474/381, x-10,y-20);
    atk_left->init(685, 474, 0, 0, width*685/419, height*474/381, x-20 - 685/419 * width/2,y-20);
    
    immobile->init(387, 370, 0, 0, width*387/419, height, x, y); 
    immobileL->init(387,370, 0, 0, width*387/419, height, x, y);

    bdf_r->init(210,160, 0, 0, width * 210/411, height * 160/396, x+width/2, y+height/2);
    bdf_l->init(210,160, 0, 0, width * 210/411, height * 160/396, x+width/2, y+height/2);
    hud->init(renderer, pv_max, pv, mana_max, mana, width, height, x, y); 

    deadR->init(381,363, 0, 0, width*381/419, height*363/381, x, y); 
    deadL->init(381,363, 0, 0, width*381/419, height*363/381, x, y); 

    std::cout << "Init magicien" << std::endl;
}

/*!
 * \param renderer : La fenêtre dans laquelle notre personnage est initialisé
          mechant : La liste des méchants présents dans le jeu 
*/


void Magicien::draw(SDL_Renderer* renderer, std::vector<Mechant*> mechants)
{
    hud->draw(renderer); //Dessin de la barre de vie

    if(n_attack == 1) //Si on utilise la tempête, on dessine l'animation
    {
        if ((sens>0) || (sensPrec>0)) // Si le magicien court vers la droite ou est immobile vers la droite 
        {
            atk_right->draw(renderer); //on lance l'animation de l'attaque vers la droite 
            for (int i = 0; i < mechants.size(); i++) // on parcourt la liste des méchants
            {
                if (atk_right->collision(mechants[i]->getCollider())) // on regarde s'il y a eu collision avec un des méchants 
                {
                    if(timeKey==15) // si oui, on vérifie si timekey vaut 15, pour éviter les collisions multiple lors de l'animation de l'attaque  
                        mechants[i]->encaisse(atk);// si oui, l'ennemie encaisse les dégats de la tempête.
                } 
                
            }
        }
        //On fait la même chose mais pour l'animation de gauche 
        else{
            atk_left->draw(renderer); 
            for (int i = 0; i < mechants.size(); i++)
            {
                if (atk_left->collision(mechants[i]->getCollider()))
                {
                    if(timeKey==15)
                        mechants[i]->encaisse(atk); 
                }
            }
        }
    }
    else if(n_attack == 2) //Si on utilise l'attaque 2
    {
        if((sens>0) || (sensPrec>0)) // Si le magicien est orienté vers la droite 
        {
            if(mechants.size()>0)//On dit que le premier ennemi prend forcement le coup par manque de temps de a coder
            {                    
                if(!(bdf_r->collision(mechants[0]->getCollider()))) //On verifie que la bdf ne frappe pas le premier ennemi
                {
                    bdf_r->move(3,0); //On la fait avancer
                    bdf_r->draw(renderer); //On la dessine
                }
                else // si la boule de feu a touché un ennemie 
                {
                    timeKey=0; // on met reset l'appui de touche de l'attaque à 0
                    n_attack=0; //on remet le magicien en mode passif 
                    bdf_r->setPos(right->getRect().x,right->getRect().y); //Sinon elle revient dans les mains du Mage
                    mechants[0]->encaisse(atk); // on fait encaissé l'attaque du magicien au méchant 
                    std::cout<<"Touché !!!!"<< std::endl; 
                } 
            }
            // S'il n'y a pas de méchant présent dans la fenêtre on fait dessine comme même la boule de feu   
            else
            {
                if(bdf_r->getRect().x<1280) //On verifie que la bdf ne frappe pas le premier ennemi
                {
                    bdf_r->move(3,0); //On la fait avancer
                    bdf_r->draw(renderer); //On la dessine
                }
                else
                {
                    timeKey=0;
                    n_attack=0;
                    bdf_r->setPos(right->getRect().x,right->getRect().y);
                } 
            }
        }
        // Même chose pour l'animation de la boule de feu vers la gauche 
        else
        {
            if(mechants.size()>0)
            {                    
                if(!(bdf_l->collision(mechants[0]->getCollider()))) //On verifie que la bdf ne frappe pas le premier ennemi
                {
                    bdf_l->move(-3,0); //On la fait avancer
                    bdf_l->draw(renderer); //On la dessine
                }
                else
                {
                    timeKey=0;
                    n_attack=0;
                    bdf_l->setPos(right->getRect().x,right->getRect().y); //Sinon elle revient dans les mains du Mage
                    mechants[0]->encaisse(atk); 
                    std::cout<<"Touché !!!!"<< std::endl; 
                } 
            }
            else
            {
                if(bdf_l->getRect().x>0) //On verifie que la bdf ne frappe pas le premier ennemi
                {
                    bdf_l->move(-3,0); //On la fait avancer
                    bdf_l->draw(renderer); //On la dessine
                }
                else
                {
                    timeKey=0;
                    n_attack=0;
                    bdf_l->setPos(right->getRect().x,right->getRect().y);
                } 
            } 
        }
    }

    else if(n_attack==-1){
        if ((sens>0) || (sensPrec>0))
            deadR->draw(renderer); 
        else
            deadL->draw(renderer);
    }
    else //Si on bouge, on dessine les actions de mouvement en fonction du sens
    {
        if(sens>0)
            right->draw(renderer);
        else if(sens<0)
            left->draw(renderer);
        else{
            if (sensPrec>0)
                immobile->draw(renderer); 
            else
                immobileL->draw(renderer); 
        }      
    }
}


/*!
    Méthode permettant de mettre à jour l'état du magicien en fonction de la touche appuyé 
 * \param state : Un tableau de l'état des touches du clavier 
*/
void Magicien::update(const Uint8* state){
    handleEvents(state);// on fait appel à la méthode permettant de savoir la touche qu'on a appuyé 


    Humain::update();// On fait appel méthode d'update d'humain 
    if (pv<=0)// si le magicien n'a plus de vie, il meurt 
        mort();
    else{ // si il a encore de la vie
        if(n_attack < 1){// s'il n'est pas en mode attaque 
            move(state);// on le fait bouger 
        }
        else// sinon il attaque suivant la touche à laquellle on a appuyé 
            attaque();
    }
}


/*!
    Méthode permettant de vérifier l'éta des touches du clavier pour le magicien 
 * \param state : Un tableau de l'état des touches du clavier 
*/

void Magicien::handleEvents(const Uint8* state)
{
    if (state[touche->getAtk1()]) //Si on appuie pour attaquer et on a le mana suffisant
        {
        if (mana > 9) 
        {
            n_attack = 1; //On passe le joueur en etat attaquant
            timeKey++; //On stocke le temps d'appui de la touche
        }
        else
            std::cout << "No mana for tempete" << std::endl;
    }
    else if(state[touche->getAtk2()])// si on appuie sur la petite attaque 
    {
        if (mana > 4 && bdf_r->getLaps()>1000)// on vérifie qu'il a assez de mana et que l'animation de la boule de feu dure au moins 1 seconde avant de réattaquer 
        {
            n_attack = 2;
            timeKey++;
        }
        else
            std::cout << "No mana for fireBall or cooldown" << std::endl;
    }
}
/*!
    Méthode permettant de vérifier l'éta des touches du clavier pour le magicien lorsqu'il bouge 
 * \param state : Un tableau de l'état des touches du clavier 
*/
void Magicien::move(const Uint8* state)
{

    // même principe qu'avec la classe ninja 
	if (state[touche->getDroite()]) {// Si on appui sur une touche pour aller à droite 
        right->setState(true);
        immobile->setState(false); 
        immobileL->setState(false); 

        sens = 1;
        sensPrec = 1; 

        Humain::move(sens,0);
        bdf_r->move(sens,0);
        bdf_l->move(sens,0);
        right->update();
    }
    else if (state[touche->getGauche()]) {// Si on appui sur une touche pour aller à droite, on procéde de la même manière mais avec un sens négatif cette fois 
        left->setState(true);
        immobile->setState(false); 
        immobileL->setState(false);

        sens = -1;
        sensPrec = -1; 

        Humain::move(sens,0);
        bdf_r->move(sens,0);
        bdf_l->move(sens,0);
        left->update();
    }
    else{
        left->setState(false); 
        right->setState(false);
        sens = 0; 
        Humain::move(sens,0); 
        bdf_r->move(sens,0);
        bdf_l->move(sens,0);
        
        if(sensPrec>0){
            immobile->setState(true); 
            immobile->update(); 
        }
        else{
            immobileL->setState(true); 
            immobileL->update(); 
        }
    }
}

/*!
    Méthode permettant de mettre en place l'attaque du magicien en fonction de la valeur du numattack 
*/

void Magicien::attaque(){
    if(n_attack==1)// Pour lancer l'attaque tempête 
    {
        tempete();
    }
    else if(n_attack==2)// Pour lancer l'attaque boule de feu
    {
        bouleDeFeu();
    }   
}


/*!
    Méthode permettant de mettre en place l'attaque tempête du magicien 

*/


void Magicien::tempete()	
{
    if (atk_right->getTimer() == -1)
    {
        atk_right->setTimer(SDL_GetTicks()); //On declenche le timer attaque
    }
	if (atk_right->getLaps() < 500){ //Si l'animation n'est pas fini & le joueur attaque encore
        if(sens>0 || sensPrec>0) //On anime selon le sens
        {
            atk_right->setState(true);
            atk_right->update(); 
        }
        else
        {
            atk_left->setState(true);
            atk_left->update();
        } 
    }
    else //Sinon, elle est finit, on passe l'etat d'attaque a false
    {
        atk_right->setTimer(-1);
        std::cout << "Fin d'attaque : " << timeKey << std::endl;        
    	n_attack = 0;
    	timeKey=0;
    }

    if(timeKey == 15) //Si on a detecte un appui long, on reset l'appui et on enleve le mana consomme
    {
        if(mana>9){
    	   mana-=10;
        }
    }
}


/*!
    Méthode permettant de mettre en place l'attaque boule de feu du magicien 
    \return La valeur de l'attaque boule de feu du magicien  
*/


int Magicien::bouleDeFeu()
{
	if(timeKey == 15 && bdf_r->getLaps()>1000) //Si on a detecte un appui long, on reset l'appui et on enleve le mana consomme
    {
        bdf_r->setTimer(SDL_GetTicks());
        if(mana>4)
        {
    	   mana-=5;
        }
    	return atk;
    }
}

/*!
    Méthode permettant de mettre en place la mort du magicien quand il a plus de pv 
*/
void Magicien::mort(){

    // les mêmes principes que la mort du ninja 
    n_attack = -1; 
    
    if ((sens>0) || (sensPrec>0)){
        fin++; 

        if(fin==198)
            deadR->setState(false); 
        deadR->update();
    }
    else{
        fin++; 
        
        if(fin==198)
            deadL->setState(false); 
        deadL->update();  
    }
}
