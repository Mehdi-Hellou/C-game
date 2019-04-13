#include "robot.hpp"
/*!

Les méthode sont le même principe que celle de zombie, à part au niveau des point de vies qui sont supérieurs à celle du zombie. 
Il peut-être fait au plus tard une méthode détecter plus compléte, avec une IA du robot plus poussé et des animations en plus, comme l'attaque jumpé
ou une glissade. 
*/
int keyTime2=0;// compteur pour l'animation des collisions, afin que les collisions d'attaques ne soient pas perçus plusieurs fois 
/*!
Le constructeur par défault de robot 
*/
Robot::Robot():Mechant(){
    pv_max = 15; 
    pv = pv_max; 
    atk = 10; 
    def = 2; 
}
/*!
 * \param hp : les niveau de vie que l'on veut donné au robot 
          dmg  : les dommages qu'il pouvoir donné avec son attaque  
*/

Robot::Robot(int hp, int dmg){
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

Robot::~Robot(){}

/*!
    Même principe que pour la méthode avec zombie 
*/
void Robot::init(SDL_Renderer* renderer, int width, int height, int x, int y)
{
    // Le chargement des sprites pour l'animation du marcher vers la droite ou vers la gauche, l'immobilité gauche ou droite et l'animation de mort vers la gauche et vers la droite 
    right = new Sprite(renderer, "Robot/runRight.png", 1000, 200, 7,25);
    left = new Sprite(renderer, "Robot/runLeft.png", 1000, 200, 7,15); 
    
    atk_right = new Sprite(renderer, "Robot/atkRight.png", 1000, 200, 8,20);
    atk_left = new Sprite(renderer, "Robot/atkLeft.png", 1000, 200, 8, 20);
    
    immobile = new Sprite(renderer, "Robot/immobileRight.png", 1000, 200, 10, 15);
    immobileL = new Sprite(renderer, "Robot/immobileLeft.png", 1000, 200, 10, 15); 

    deadL = new Sprite(renderer, "Robot/deadL.png", 1000, 200, 10, 20);
    deadR = new Sprite(renderer, "Robot/dead.png", 1000, 200, 10, 20); 

    atkCollR = new Sprite(renderer, "Robot/left_hand.png"); 
    atkCollL = new Sprite(renderer, "Robot/left_hand.png"); 

    hpBar = new StatBar(renderer,"healthmeter.png"); 
    
    right->init(567, 556, 0, 0,width,height,x,y);
    left->init(567, 556, 0, 0,width,height,x,y);
    
    atk_right->init(567, 556, 0, 0, width,height, x,y);
    atk_left->init(567, 556, 0, 0, width, height, x,y);
    
    immobile->init(567, 556, 0, 0, width,height, x, y);
    immobileL->init(567, 556, 0, 0, width,height, x, y); 

    atkCollR->init(160, 32, 0, 0, 25 , 103, x+89, y+20);
    atkCollL->init(160, 32, 0, 0, 25 , 103, x+10, y+20); 

    deadL->init(562, 519, 0, 0, width*562/567, height*519/556, x, y); 
    deadR->init(562, 519, 0, 0, width*562/567, height*519/556, x, y); 
    hpBar->init(100, 15, 0,  0, width/2, height/15, x+30, y-10); 

    std::cout << "Init mechant" << std::endl;
}

void Robot::draw(SDL_Renderer* renderer, std::vector<Humain*> gentils)
{
    hpBar->draw(renderer); 

    if(n_attack==0)
    {
        if(sens>0)
            right->draw(renderer);
        else if(sens < 0 )
            left->draw(renderer);
        else{
            if (sensPrec > 0)
                immobile->draw(renderer);
            else
                immobileL->draw(renderer);  
        }
    }

    else if(n_attack<0){

        if (sens>0)
            deadR->draw(renderer); 
        else
            deadL->draw(renderer); 

        //fin++; 
    }

    else{
        if (sens>0)
        {
            atk_right->draw(renderer);
            for (int i = 0; i < gentils.size(); i++)
            {
                if (atkCollR->collision(gentils[i]->getCollider()))
                {   
                    keyTime2++;
                    if(keyTime2==5)    
                        gentils[i]->encaisse(atk);
                }   
            }
        }
        else{
            atk_left->draw(renderer);
            for (int i = 0; i < gentils.size(); i++)
            {
                if (atkCollL->collision(gentils[i]->getCollider()))
                {
                    keyTime2++;
                    if(keyTime2==5) 
                        gentils[i]->encaisse(atk);  
                }
                
            } 
        }
    }
}

void Robot::update(std::vector<Humain*> gentils){
    hpBar->update(pv_max,pv);
    detecter(gentils); 

    if (pv<=0)
        mort();
    else{
        if(n_attack<1)
            move(sens,0);
        else
            attaque();
    }
}

void Robot::move(int x, int y)
{
    if((left->getRect().x < 0) && (sens==-1)){
        right->setState(true);
        sens = 1;
        sensPrec = 1;
        Personnage::move(sens,0);
        hpBar->move(sens, 0);

        atkCollR->move(sens, 0); 
        atkCollL->move(sens,0); 

        right->update();
    }

    else if((right->getRect().x > 1280-right->getRect().w) && (sens==1)){
        left->setState(true);
        sens = -1;
        sensPrec = -1;
        Personnage::move(sens,0);
        hpBar->move(sens,0);

        atkCollR->move(sens, 0); 
        atkCollL->move(sens,0);  

        left->update();
    }

    else{

        Personnage::move(sens,0); 
        hpBar->move(sens, 0);

        atkCollR->move(sens, 0); 
        atkCollL->move(sens,0); 

        if(sens>0)
            right->update(); 
        else if(sens<0)
            left->update();
        else
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

void Robot::attaque(){
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
        keyTime2=0;
    }
}



void Robot::detecter(std::vector<Humain*> gentils){

    for (int i = 0; i < gentils.size(); i++)
    {
        if(abs(right->getRect().x - gentils[i]->getCollider().x)<60)
            n_attack = 1; 
        else
            n_attack = 0; 

    }
}

void Robot::mort(){
    n_attack = -1; 
    
    if (sens>0){
        fin++; 

        if(fin==199*2)
            deadR->setState(false); 
        deadR->update();
    }
    else{
        fin++; 

        if(fin==199*2)
            deadL->setState(false); 
        deadL->update();  
    }
}