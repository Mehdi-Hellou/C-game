#include "sprite.hpp"

Sprite::Sprite(){}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

Sprite::Sprite(SDL_Renderer* renderer, const std::string& filename){ //Constructeur pour sprite non anime
	anime = false; //On initialise le sprite non anime
	animTimer=0; //Timer = 0
	SDL_Surface* loadSurf=IMG_Load(filename.c_str()); //On charge la texture dans une surface temporaire
	texture=SDL_CreateTextureFromSurface(renderer,loadSurf); //On la transforme en texture puis on la libere
	SDL_FreeSurface(loadSurf);
}

Sprite::Sprite(SDL_Renderer* renderer, const std::string& filename, Uint32 timer, float speed, float nframe, int xoff){//Constructeur pour sprite anime
	SDL_Surface* loadSurf=IMG_Load(filename.c_str()); //Meme chargement que plus haut
	texture=SDL_CreateTextureFromSurface(renderer,loadSurf);
	SDL_FreeSurface(loadSurf);
	anime=true; //On initialise le sprite anime

	animTimer = timer; //On copie les valeurs du timer de l'animation, de la vitesse du nombre de frame et du decalage entre chaque image du spreadsheet
	animSpeed = speed;
	frame = nframe;

	xOffset = xoff;
}

void Sprite::init(int src_width, int src_height, int src_x, int src_y, int dst_width, int dst_height, int dst_x, int dst_y){ //Initialisation du sprite en fonction de l'image de depart et de l'ecran d'arrivee
	srcRect.x = src_x; //On copie par valeur la position du rectangle source
	srcRect.y = src_y;
	srcRect.w = src_width;
	srcRect.h = src_height;

	dstRect.x = dst_x; //De meme pour le rectangle destination, cela permet de placer le sprite où l'on desire lors de son initialisation
    dstRect.y = dst_y;
    dstRect.w = dst_width;
    dstRect.h = dst_height;

	xFixe = src_x; //xFixe represente la position de l'image initiale du spreadsheet
	std::cout << "Init sprite" << std::endl;
}

void Sprite::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, &srcRect, &dstRect); //On copie l'image de la source au renderer grace au dstRect
}

void Sprite::update()
{
	if(anime){ //Si l'objet est anime, on modifie la position de son rectangle source 
		srcRect.x = (srcRect.w+xOffset) * static_cast<int>((SDL_GetTicks() / animSpeed) % frame); //A chaque tick de SDL, en fonction de la vitesse definie du sprite, on affiche une frame differente du spreadsheet
        xFixe = srcRect.x;//xFixe permet de savoir où l'animation s'est arretee apres l'update plus haut
    }
	else
		srcRect.x = xFixe;//xFixe represente la position de l'image initiale du spreadsheet
}

void Sprite::setState(bool b){ //On modifie l'etat du sprite
	anime=b;
}

const Uint32& Sprite::getTimer(){ //Retourne le timer d'animation
	return animTimer;
}

Uint32 Sprite::getLaps(){ //Retour le temps depuis lequel l'animation a commence
	return SDL_GetTicks() - animTimer;
}

void Sprite::setTimer(const Uint32& time){ //Set le timer animation
	animTimer = time;
}

SDL_Rect& Sprite::getRect() //Retourne le rectangle de destination (peut servir pour les collisions)
{
	return dstRect;
}

void Sprite::move(int x, int y) //Mouvement du rectangle de destination
{
	dstRect.x += x;
	dstRect.y += y;
}

void Sprite::setPos(int x, int y) //Permet de placer le centre du sprite a un point precis de l'ecran
{
	dstRect.x = x+dstRect.w/2; 
	dstRect.y = y+dstRect.h/2;	
}

bool Sprite::collision(SDL_Rect a){
	//Declaration des cotes des rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //On calcule les cotes du rectangle A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //On calcule les cotes du rectangle B
    leftB = dstRect.x;
    rightB = dstRect.x + dstRect.w;
    topB = dstRect.y;
    bottomB = dstRect.y + dstRect.h;

    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //On return true si aucun des cotes n'a d'intersection, false sinon
    return true;
}
