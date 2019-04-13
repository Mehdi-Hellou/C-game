#include "ninja.hpp"
int timeKey2=0; // compteur des touches qui vérifient qu'on ne touche pas plusieurs fois l'ennemie lors de l'animation d'une attaque 
Ninja::Ninja(const std::string& n, const Controls& controls): Humain(n, controls){
	pv_max = 80;  // Les PV maxs du ninja 
	pv = pv_max;  // Nous intions les pvs de bas du ninja au pv max
	niveau = 1;   // Le niveau du joueur commence au niveau 1
	exp=0; // Il n'a pas de XP au début 
	atk = 7; // son attaque est de 7 au début 
	def = 3; // sa défense est de 3
	mana_max = 20;  // son mana_max est de 20
	mana = mana_max;  // son mana actuelle est égale au mana max 
    sens = 1; // Il est dirigé vers la droite 
    finL = 0; // On initialise la fin de son lancé --> correspond pour l'animation du lancé 
    lance = false; // Il ne lance pas de kunai lorsqu'il est créé
    sensPrec = 1; // Le sens précédent est vers la droite 
}


/**

    Le destructeur des sprites correspondant au lancé de kunai, au dessin du kunai dans les deux sens, à la collision des épées 
**/
Ninja::~Ninja(){
    delete lance_left; 
    delete lance_rigth;  
    delete kunai_left; 
    delete kunai_rigth; 
    delete epeCollR; 
    delete epeCollL; 
}

/*!
 * \param renderer : La fenêtre dans laquelle notre personnage est initialisé
          width  : la largeur du personnage que nous souhaitons avoir.
          height : la hauteur du personnage que nous souhaitons avoir.
          x : sa positions en x initiale lorsque le jeu commence. 
          y : sa positions en y initiale lorsque le jeu commence. 
*/

void Ninja::init(SDL_Renderer* renderer, int width, int height, int x, int y)
{
	right = new Sprite(renderer, "Ninja/runR.png", -1, 100, 9, 0); // On charge le sprite correŝpondant marché vers la droite du ninja
    left = new Sprite(renderer, "Ninja/runL.png", -1, 100, 9, 0); // On charge le sprite correŝpondant marché vers la gauche du ninja
    atk_right = new Sprite(renderer, "Ninja/NinjaAtkRigth.png", -1, 150, 10, 0);// On charge le sprite correŝpondant à l'attaque vers la droite du ninja
    atk_left = new Sprite(renderer, "Ninja/atkL.png", -1, 150, 10, 0);// On charge le sprite correŝpondant à l'attaque vers la gauche du ninja
    lance_left = new Sprite(renderer, "Ninja/throwLeft.png", -1, 100, 10, 20); // On charge le sprite correŝpondant au lancé de kunai vers la droite du ninja
    lance_rigth = new Sprite(renderer, "Ninja/throwRigth.png", -1, 100, 10, 20); // On charge le sprite correŝpondant au lancé de kunai vers la gauche du ninja
    kunai_rigth = new Sprite(renderer, "Ninja/kunaiR.png"); // On charge le sprite correŝpondant au kunai vers la droite du ninja
    kunai_left = new Sprite(renderer, "Ninja/kunaiL.png"); // On charge le sprite correŝpondant au kunai vers la gauche du ninja
    immobile = new Sprite(renderer, "Ninja/Immobile.png", -1, 100, 10, 20); // On charge le sprite correŝpondant à l'animation immobile vers la droite du ninja
    immobileL = new Sprite(renderer, "Ninja/ImmobileL.png", -1, 100, 10, 20);// On charge le sprite correŝpondant à l'animation immobile vers la gauche du ninja
    hud = new Hud(renderer,"healthmeter.png", "manameter.png",nom); // On charge le sprite correŝpondant à la barre de vie et de mana 
    epeCollR = new Sprite(renderer, "Ninja/kunaiR.png"); // On charge le sprite correŝpondant à la collision de l'épé vers la droite 
    epeCollL = new Sprite(renderer, "Ninja/kunaiL.png"); // On charge le sprite correŝpondant à la collision de l'épé vers la gauche 

    deadR = new Sprite(renderer,"Ninja/deadR.png", -1, 200,10,20); // On charge le sprite correŝpondant à l'animation de mort vers la droite 
    deadL = new Sprite(renderer,"Ninja/deadL.png", -1, 200,10,20); // On charge le sprite correŝpondant à l'animation de mort vers la gauche  


    right->init(383, 478, 0, 0,width,height,x,y); //On intialise le sprite correspondant au marché vers la droite du ninja 
    left->init(383, 478, 0, 0,width,height,x,y);   //On intialise le sprite correspondant au marché vers la gauche du ninja  
    atk_right->init(556, 515, 0, 0, width*556/383,height*515/478, x-10,y); //On intialise le sprite correspondant à l'attaque vers la droite du ninja  
    atk_left->init(556, 515, 0, 0, width*556/383, height*515/478, x-20 - 556/383 * width/2,y); //On intialise le sprite correspondant à l'attaque vers la gauche du ninja  
    
    epeCollR->init(160, 32, 0, 0, 44 , 133, x+130, y+19); //On intialise le sprite correspondant à la collision de l'épée vers la droite 
    epeCollL->init(160, 32, 0, 0, 44, 133, x-90, y+19); //On intialise le sprite correspondant à la collision de l'épée vers la gauche 

    lance_left->init(377, 451, 0, 0, width*377/383, height*451/478, x, y); //On intialise le sprite correspondant au lancé du kunai vers la droite 
    lance_rigth->init(377, 451, 0, 0, width*377/383, height*451/478, x, y); //On intialise le sprite correspondant au lancé du kunai vers la gauche  

    kunai_rigth->init(160,32, 0, 0, width * 160/383, height * 32/478, x+width/2, y+height/2); //On intialise le sprite correspondant à l'animation du kunai vers la droite 
    kunai_left->init(160,32, 0, 0, width * 160/383, height * 32/478, x+width/2, y+height/2);//On intialise le sprite correspondant à l'animation du kunai vers la gauche 
    
    hud->init(renderer, pv_max, pv, mana_max, mana, width, height, x, y); //On intialise le sprite correspondant à la barre de vie et de mana 
    immobile->init(232, 439, 0, 0, width*232/383, height*439/478, x, y);//On intialise le sprite correspondant à l'animation immobile vers la droite 
    immobileL->init(232, 439, 0, 0, width*232/383, height*439/478, x, y); //On intialise le sprite correspondant à l'animation du immobile vers la gauche 

    deadR->init(482,498, 0, 0, width*482/383, height*498/478, x, y); //On intialise le sprite correspondant à l'animation de la mort vers la droite 
    deadL->init(482,498, 0, 0, width*482/383, height*498/478, x, y); //On intialise le sprite correspondant à l'animation de la mort vers la gauche 


    std::cout << "Init ninja" << std::endl;
}

/*!
 * \param renderer : La fenêtre dans laquelle notre personnage est initialisé
          mechant : La liste des méchants présents dans le jeu 
*/

void Ninja::draw(SDL_Renderer* renderer, std::vector<Mechant*> mechants)
{
    hud->draw(renderer); //Dessin de la barre de vie et de mana

    if(n_attack == 1) //Si on utilise le kunai, on dessine l'animation
    {
        if((sens>0) || (sensPrec>0)) // Si le ninja coure vers la droite ou est immobile vers la droite 
        {
            lance_rigth->draw(renderer); //on lance l'animation du lancé de kunai vers la droite 
            finL++; // on incrémente finL 

            if(finL==25) // puis on regarde si lancé vaut 25
                lance = true; // si oui, on met lance à true, pour lancer le kunai vers la droite 
        }

        else // si on est dans l'autre sens 
        { 
            lance_left->draw(renderer); //on lance l'animation du lancé de kunai vers la gauche
            finL++;// on incrémente finL 

            if(finL==25)// puis on regarde si lancé vaut 25
                lance = true; // si oui, on met lance à true, pour lancer le kunai vers la gauche 
        }
    }

    else if(n_attack == 2){ // Si on utiliser l'attaque de l'épée 
        if ((sens>0) || (sensPrec>0)) // Si le ninja coure vers la droite ou est immobile vers la droite 
        {
            atk_right->draw(renderer);  //On fait l'animation de l'attaque vers la droite 
            for (int i = 0; i < mechants.size(); i++) // On parcourt la liste des méchants
            {
                if (epeCollR->collision(mechants[i]->getCollider())) // on vérifie si la collision correspondant à l'épée touche un ennemie 
                {
                    if(timeKey2==15)   // si oui, on vérifie si timekey vaut 15, pour éviter les collisions multiple lors de l'animation de l'attaque 
                        mechants[i]->encaisse(atk);  // si oui, l'ennemie encaisse les dégats de l'épée.
                }
                
            }
        }

        else{ // même principe pour l'animation de gauche 
            atk_left->draw(renderer); 
            for (int i = 0; i < mechants.size(); i++)
            {
                if (epeCollL->collision(mechants[i]->getCollider()))
                {
                    if(timeKey2==15)
                        mechants[i]->encaisse(atk); 
                }
            }
        }
    }

    else if(n_attack==-1){ // Animation de la mort vers du ninja 
        if ((sens>0) || (sensPrec>0))
            deadR->draw(renderer); 
        else
            deadL->draw(renderer); 
    }

   else //Si on bouge, on dessine les actions de mouvement en fonction du sens
    {
        if(sens>0)
            right->draw(renderer); //  animation vers la droite 

        else if(sens < 0) 
            left->draw(renderer); // animation vers la gauche 

        else{
            if (sensPrec > 0) // Animation d el'immobilité vers la droite, si sensPrec est positif 
                immobile->draw(renderer);
            else
                immobileL->draw(renderer);   // animation de l'immobilité vers la gauche, si sensPrec est négatif 
        }

        if(lance){ // si on a le lancé qui vaut true 
            if(mechants.size()>0) //On dit que le premier ennemi prend forcement le coup par manque de temps de a coder
            { 
                if((sens>0) || (sensPrec>0)){ //si le sens est vers la droite 
                    if((kunai_rigth->collision(mechants[0]->getCollider())) || (kunai_rigth->getRect().x>1280)){ // On vérfie que le kunai touche un ennemie ou dépasse la bordure droite de la fenêtre 
                        timeKey2=0; // timekey2, du compteur de la touche por lancé le kunai ou l'attaque épée on la met à 0
                        n_attack=0; // On repasse le ninja à en mode passif  
                        kunai_rigth->setPos(right->getRect().x+right->getRect().w/2,right->getRect().y+right->getRect().h/2); //le kunai revient dans les mains du Ninja
                        mechants[0]->encaisse(atk); // le premier méchants encaisse l'attaque 
                        finL = 0; // La fin du compteur pour le lancé revient à 0
                        lance = false; // le lancé redevient false 
                    }

                    else{ // sinon on déssiner le kunai vers la droite qu'on fait bouger à l'écran.
                        kunai_rigth->draw(renderer); 
                        kunai_rigth->move(4,0); 
                    }
                }
                else{// Si le lancé est fait lorsque le ninja est dirigé vers la droite 
                    if((kunai_left->collision(mechants[0]->getCollider())) || (kunai_left->getRect().x<0)){
                        timeKey2=0;
                        n_attack=0;
                        kunai_left->setPos(right->getRect().x+right->getRect().w/2,right->getRect().y+right->getRect().h/2); //Sinon elle revient dans les mains du Ninja
                        mechants[0]->encaisse(atk); 
                        finL = 0; 
                        lance = false; 
                    }

                    else{
                        kunai_left->draw(renderer); 
                        kunai_left->move(-4,0); 
                    }
                }
            }
            else // S'il n'y pas de méchant non plus, l'animation de lancé de kunai est valabl aussi 
            {
                if((sens>0) || (sensPrec>0)){
                    if(kunai_rigth->getRect().x>1280){
                        timeKey2=0;
                        n_attack=0;
                        kunai_rigth->setPos(right->getRect().x+right->getRect().w/2,right->getRect().y+right->getRect().h/2); //Sinon elle revient dans les mains du Ninja
                        finL = 0; 
                        lance = false; 
                    }
                    else{
                        kunai_rigth->draw(renderer); 
                        kunai_rigth->move(4,0); 
                    }
                }
                else{
                    if(kunai_left->getRect().x<0){
                        timeKey2=0;
                        n_attack=0;
                        kunai_left->setPos(right->getRect().x+right->getRect().w/2,right->getRect().y+right->getRect().h/2); //Sinon elle revient dans les mains du Ninja
                        finL = 0; 
                        lance = false; 
                    }
                    else{
                        kunai_left->draw(renderer); 
                        kunai_left->move(-4,0); 
                    }
                }
            }
        } 
    }
}

/*!
    Méthode permettant de mettre à jour l'état du ninja en fonction de la touche appuyé 
 * \param state : Un tableau de l'état des touches du clavier 
*/

void Ninja::update(const Uint8* state){
    handleEvents(state);// on fait appel à la méthode permettant de savoir la touché qu'on a appuyé 

    Humain::update();  // On fait appel méthode d'update d'humain 
    if (pv<=0) // si le ninja n'a plus de vie, il meurt 
        mort();
    else{  // si il a encore de la vie 
        if(n_attack < 1){ // s'il n'est pas en mode attaque 
            move(state);// on le fait bouger 
        }
        else// sinon il attaque suivant la touche à laquellle on a appuyé 
            attaque();
    }
}


/*!
    Méthode permettant de vérifier l'éta des touches du clavier pour le ninja 
 * \param state : Un tableau de l'état des touches du clavier 
*/

void Ninja::handleEvents(const Uint8* state)
{
    if (state[touche->getAtk2()]) //Si on appuie pour attaquer et on a le mana suffisant
        {
        if (mana > 9)
        {
            n_attack = 1; //On passe le joueur en etat attaquant
            timeKey2++; //On stocke le temps d'appui de la touche
        }
        else
            std::cout << "No mana for kunai" << std::endl;
    }
   
   else if(state[touche->getAtk1()]) // si on appuie sur la petite attaque 
    {
        if (mana > 4) // on vérifie qu'il a assez de mana 
        {
            n_attack = 2; // si oui on passe la variable numattack à 2, afin qu'il puisse lancé la deuxième attaque 
            timeKey2++; // On stocke le temps d'appui de touche 
        }
        else
            std::cout << "No mana for sword" << std::endl;
    }
}

/*!
    Méthode permettant de vérifier l'état des touches du clavier pour le ninja lorsqu'il bouge 
 * \param state : Un tableau de l'état des touches du clavier 
*/
void Ninja::move(const Uint8* state)
{
    if (state[touche->getDroite()]) { // Si on appui sur une touche pour aller à droite 
        right->setState(true);    // on anime le sprite pour courir à droite 
        immobile->setState(false); // on met l'animation de l'immobile du ninja à false à gauche et à droite 
        immobileL->setState(false); 

        sens = 1; // sens devient possitif 
        sensPrec = 1; //  de même pour sensPrec

        Humain::move(sens,0); // on fait bouger les sprites spécifiques à l'humain 

        // on fait bouger les sprites spécifiques au ninja 
        lance_rigth->move(sens,0);  
        lance_left->move(sens,0); 
        kunai_rigth->move(sens,0); 
        kunai_left->move(sens, 0); 
        epeCollR->move(sens,0); 
        epeCollL->move(sens, 0); 

        // On update le sprite right, pour avoir l'animation de marcher à droite 
        right->update();
    }
    else if (state[touche->getGauche()]) { // Si on appui sur une touche pour aller à droite, on procéde de la même manière mais avec un sens négatif cette fois 
        left->setState(true);
        immobile->setState(false); 
        immobileL->setState(false); 

        sens = -1;
        sensPrec = -1; 

        Humain::move(sens,0);
        lance_rigth->move(sens,0); 
        lance_left->move(sens,0); 
        kunai_rigth->move(sens, 0); 
        kunai_left->move(sens, 0); 
        epeCollR->move(sens, 0); 
        epeCollL->move(sens, 0);

        left->update();
    }
    else{ // Sinon, si on appui sur aucune touche pour bouger , on fait animer l'immobilité 
        left->setState(false); // on passe l'animation marcher à droite à false 
        right->setState(false);// on passe l'animation marcher à gauche à false 
        sens = 0; // le sens devient null

        // on utiliser la varibale sensPrec pour savoir si on été à gauche ou à droite, pour animer la bonne animation de l'immobilité 
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

/*!
    Méthode permettant de mettre en place l'attaque du ninja en fonction de la valeur du numattack 
*/


void Ninja::attaque(){
    if(n_attack==1) // Pour lancer l'attaque kunai 
    {
        kunai(); 
    }
    else if(n_attack==2) // Pour lancer l'attaque épée 
    {
        epe(); 
      
    }   
}


/*!
    Méthode permettant de mettre en place l'attaque kunai du ninja 
    \return La valeur de l'attaque kunai du ninja  
*/


int Ninja::kunai(){

    if (lance_rigth->getTimer() == -1)
    {
        lance_rigth->setTimer(SDL_GetTicks()); //On declenche le timer attaque
    }
    if (lance_rigth->getLaps() < 500){ //Si l'animation n'est pas fini & le joueur attaque encore
        if((sens>0) || (sensPrec>0)) //On anime selon le sens
        {
            lance_rigth->setState(true);
            lance_rigth->update(); 
        }
        else
        {
            lance_left->setState(true);
            lance_left->update();
        } 
    }
    else //Sinon, elle est finit, on passe l'etat d'attaque a false
    {
        lance_rigth->setTimer(-1);
        std::cout << "Fin d'attaque : " << timeKey2 << std::endl;        
        n_attack = 0;
        timeKey2=0;
    }

    if(timeKey2 == 15) //Si on a detecte un appui long, on reset l'appui et on enleve le mana consomme
    {
        if(mana>4)
        {
           mana-=4;
        }
        return atk;
    }
}

/*!
    Méthode permettant de mettre en place l'attaque épé du ninja 
*/

void Ninja::epe(){
    if (atk_right->getTimer() == -1)
    {
        atk_right->setTimer(SDL_GetTicks()); //On declenche le timer attaque
    }
    if (atk_right->getLaps() < 500){ //Si l'animation n'est pas fini & le joueur attaque encore
        if((sens>0) || (sensPrec>0)) //On anime selon le sens
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
        std::cout << "Fin d'attaque : " << timeKey2 << std::endl;        
        n_attack = 0;
        timeKey2=0;
    }

   /* if(timeKey2 == 15) //Si on a detecte un appui long, on reset l'appui et on enleve le mana consomme
    {
        //pv-=10;
        if(mana>9)
        {
           mana-=10;
        }
    }*/
}

/*!
    Méthode permettant de mettre en place la mort du ninja quand il a plus de pv 
*/

void Ninja::mort(){
    n_attack = -1; // on passe le numéro d'attaque à zéro
    
    // on regarde en fonction du sens si on fait une animation de mort à gauche ou à droite 
    if ((sens>0) || (sensPrec>0)){
        fin++; // on incrémennte notre compteur de fin, pou éviter que l'animation se passe indéfiniment 

        if(fin==198) // si l'incrément vaut 198, car la vitesse de l'animation du sprite pour la mort vaut 200
            deadR->setState(false); // on passe le sprite de mort à false pour figer le personnage 
        deadR->update();// on update le ninja dans les deux cas. 
    }
    // même chose si le ninja est tourné vers la gauche
    else{
        fin++; 
        
        if(fin==198)
            deadL->setState(false);
        deadL->update();  
    }
}
