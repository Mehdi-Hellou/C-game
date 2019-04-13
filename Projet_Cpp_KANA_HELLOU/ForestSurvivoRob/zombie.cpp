#include "zombie.hpp"
int keyTime=0; // compteur pour l'animation des collisions, afin que les collisions d'attaques ne soient pas perçus plusieurs fois 
Zombie::Zombie():Mechant(){
    pv_max = 15; // Les pv maxs du zombie au niveau 1
    pv = pv_max; // les pv actuelles du zombie 
    atk = 10; // l'attaque du zombie 
    def = 2; //  la défense du zombie 
}

/*!
 * \param hp : les niveau de vie que l'on veut donné au zombie 
          dmg  : les dommages qu'il pouvoir donné avec son attaque  
*/

Zombie::Zombie(int hp, int dmg){
    pv_max = hp; 
    pv = pv_max; 
    niveau = 1; 
    exp=0; 
    atk = dmg; 
    def = 2; 
    sens = -1;
    sensPrec = -1;  
    fin = 0; 
}

Zombie::~Zombie(){}

void Zombie::init(SDL_Renderer* renderer, int width, int height, int x, int y)
{

    // Le chargement des sprites pour l'animation du marcher vers la droite ou vers la gauche, l'immobilité gauche ou droite et l'animation de mort vers la gauche et vers la droite 
    right = new Sprite(renderer, "Zombie3/walkRigth.png", 1000, 200, 10,25);
    left = new Sprite(renderer, "Zombie3/walkLeft.png", 1000, 200, 10,15); 
    
    atk_right = new Sprite(renderer, "Zombie3/atkRight.png", 1000, 200, 6,20);
    atk_left = new Sprite(renderer, "Zombie3/atkLeft.png", 1000, 200, 6, 20);
    
    immobile = new Sprite(renderer, "Zombie3/immobileRight.png", 1000, 200, 15, 15);
    immobileL = new Sprite(renderer, "Zombie3/immobileLeft.png", 1000, 200, 15, 15); 

    deadL = new Sprite(renderer, "Zombie3/deadL.png", 1000, 200, 12, 20);
    deadR = new Sprite(renderer, "Zombie3/dead.png", 1000, 200, 12, 20); 

    atkCollR = new Sprite(renderer, "Zombie3/left_hand.png"); // l'image utilisé pour la collision des attaques de zombie 
    atkCollL = new Sprite(renderer, "Zombie3/left_hand.png"); 

    hpBar = new StatBar(renderer,"healthmeter.png"); // la barre de santé car les zombies n'ont pas de mana 
    
    // Initialisons des différents sprites 
    right->init(430, 519, 0, 0,width,height,x,y);
    left->init(430, 519, 0, 0,width,height,x,y);
    
    atk_right->init(430, 519, 0, 0, width,height, x,y);
    atk_left->init(430, 519, 0, 0, width, height, x,y);
    
    immobile->init(430, 519, 0, 0, width,height, x, y);
    immobileL->init(430, 519, 0, 0, width,height, x, y); 

    atkCollR->init(160, 32, 0, 0, 25 , 103, x+89, y+20);
    atkCollL->init(160, 32, 0, 0, 25 , 103, x+10, y+20); 

    deadL->init(629, 526, 0, 0, width*629/430, height*526/519, x, y); 
    deadR->init(629, 526, 0, 0, width*629/430, height*526/519, x, y); 
    hpBar->init(100, 15, 0,  0, width/2, height/15, x+30, y-10); 

    std::cout << "Init mechant" << std::endl;
}
/*!
Méthode de dessin pour les différentes animations du zombies 
 * \param renderer : La fenêtre dans laquelle notre personnage est initialisé
          gentils : La liste des gentils présents dans le jeu 
*/

void Zombie::draw(SDL_Renderer* renderer, std::vector<Humain*> gentils)
{
    hpBar->draw(renderer); // on desiine la barre de vie 

    if(n_attack==0) // s'il n'attaque pas 
    {
        // suivant le sens, le zombie bouge vers la droite ouo vers la gauche  
        if(sens>0) 
            right->draw(renderer);
        else if(sens < 0 )
            left->draw(renderer);

        // sinon s'il ne bouge pas, il est immobile, en s'orientant vers la gauche ou vers la droite suivant la valeur de sensPrec
        else{
            if (sensPrec > 0)
                immobile->draw(renderer);
            else
                immobileL->draw(renderer);  
        }
    }

    else if(n_attack<0){ // S'il n'a plus de point de vie 

        if (sens>0)
            deadR->draw(renderer); 
        else
            deadL->draw(renderer); 

        //fin++; 
    }

    else{ // S'il attaque 
        if (sens>0)// pour un sens vers la droite 
        {
            atk_right->draw(renderer); // on dessine l'attaque vers la droite 
            for (int i = 0; i < gentils.size(); i++) // on parcourt la liste des gentils 
            {
                if (atkCollR->collision(gentils[i]->getCollider())) // on vérifie s'il y a eu une collision avec un des gentils 
                {   
                    keyTime++; // on augmente la valeur de keyTime 
                    if(keyTime==5)    // si Keytime vaut 5, on peut enlever des pv au gentils touché, pour éviter la collision multiple  
                        gentils[i]->encaisse(atk);
                }   
            }
        }

        // Même principe mais pour l'attaque à gauche 
        else{ 
            atk_left->draw(renderer);
            for (int i = 0; i < gentils.size(); i++)
            {
                if (atkCollL->collision(gentils[i]->getCollider()))
                {
                    keyTime++;
                    if(keyTime==5) 
                        gentils[i]->encaisse(atk);  
                }
                
            } 
        }
    }
}

/*!
    Méthode permettant de mettre à jour l'état du zombie 
 * \param gentils : La liste des gentils passé en argument 
*/

void Zombie::update(std::vector<Humain*> gentils){
    hpBar->update(pv_max,pv); // on met à jour la barre de vie du zombie 
    detecter(gentils); // on utilise une méthode qui permet de détecter les gentils, et des les attaquer si on les détectes 

    if (pv<=0) // S'il n'a plus de vie 
        mort(); // le zombie meurt 
    else{ // sinons il attaque suivant la valeur de la variable de n_attack 
        if(n_attack<1)
            move(sens,0);
        else
            attaque();
    }
}

/*!
    Méthode permettant de vérifier l'état des touches du clavier pour le zombie lorsqu'il bouge 
 * \param x : la coordonée x auxquel on veut faire bouger le zombie 
          y : la coordonnée y auxquel on veut faire bouger le zombie  
*/

void Zombie::move(int x, int y)
{
    // Même principe qu'avec le ninja, ou le magicien à part niveau condition
    if((left->getRect().x < 0) && (sens==-1)){ // Si le zombie touche le bord gauche de l'écran 
        right->setState(true);
        sens = 1;
        sensPrec = 1;
        Personnage::move(sens,0);
        hpBar->move(sens, 0);

        atkCollR->move(sens, 0); 
        atkCollL->move(sens,0); 

        right->update();
    }

    else if((right->getRect().x > 1280-right->getRect().w) && (sens==1)){ //  si le zombie touche le bord droite de l'écran 
        left->setState(true);
        sens = -1;
        sensPrec = -1;
        Personnage::move(sens,0);
        hpBar->move(sens,0);

        atkCollR->move(sens, 0); 
        atkCollL->move(sens,0);  

        left->update();
    }

    else{ //  si le zombie ne touche aucun des bords de l'écran 

        //On fait bouger les sprites du zombie suivant la valeur de sens 
        Personnage::move(sens,0); 
        hpBar->move(sens, 0);

        atkCollR->move(sens, 0); 
        atkCollL->move(sens,0); 

        // on update soit le marcher vers la droite si le zombie bouge déja dans le sens positif ou on update le marché vers la gauche s'il bouge dans l'autre sens 
        if(sens>0)
            right->update(); 
        else if(sens<0)
            left->update();
        else // s'il doit être immobile 
        {
            left->setState(false); 
            right->setState(false);
            sens = 0; 

            if (sensPrec > 0){
                immobile->setState(true); 
                immobile->update(); 
            }
            else{
                immobileL->setState(true); 
                immobileL->update(); 
            }
        }
    }
}

/*!
    Méthode permettant de faire attaquer le zombie ( même principe que celui de ninja ou magicien)
  
*/
void Zombie::attaque(){
    if (atk_right->getTimer() == -1)
    {
        atk_right->setTimer(SDL_GetTicks()); //On declenche le timer attaque
    }
    if (atk_right->getLaps() < 500){ //Si l'animation n'est pas fini & le joueur attaque encore
        if(sens>0) //On anime selon le sens
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
    else if(atk_right->getLaps()>1500)
        atk_right->setTimer(-1);//Sinon, elle est finit, on passe l'etat d'attaque a false
    else
    {
        //atk_right->setTimer(-1);
        n_attack = 0;
        keyTime=0;
    }
}

/*!
    Méthode permettant que le zombie puisse détecter les gentils et les attaquer 
 * \param gentils : liste de gentils dans le jeu 
*/

void Zombie::detecter(std::vector<Humain*> gentils){

    for (int i = 0; i < gentils.size(); i++) // on parcourt la liste des gentils 
    {
        if(abs(right->getRect().x - gentils[i]->getCollider().x)<60) // si la distance entre le zombie et le méchant est de 60, alors le zombie l'attaque 
            n_attack = 1; 
        else // sinon le zombie continue de bouger 
            n_attack = 0; 

    }
}

/*!
    Méthode permettant que le zombie puisse détecter les gentils et les attaquer 
 * \param gentils : liste de gentils dans le jeu 
*/

void Zombie::mort(){
    n_attack = -1; // on passe le zombie en mode mort en changeant la variable de n_attack 
    
    if (sens>0){ // si le sens est positif on anime la mort vers la droite 
        fin++; // on incrémente la variable fin 

        if(fin==199*2) // si l'incrément vaut 2*199, car la vitesse de l'animation du sprite pour la mort vaut 200
            deadR->setState(false); // on fige l'animation de la mort 
        deadR->update(); // on met à jour le sprite de la mort à droite 
    }
    // si le sens du zombie est à gauche  
    else{
        fin++; 

        if(fin==199*2)
            deadL->setState(false); 
        deadL->update();  
    }
}