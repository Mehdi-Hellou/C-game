#ifndef CONTROL
#define CONTROL

#include "SDL2/SDL.h"

class Controls{
private:
	Uint8 gauche;
	Uint8 droite;
	Uint8 atk1;
	Uint8 atk2;
public:
	Controls(const Uint8& g, const Uint8& d, const Uint8& a1, const Uint8& a2);
	~Controls();

	void operator=(Controls* c);

	const Uint8& getGauche();
	const Uint8& getDroite();
	const Uint8& getAtk1();
	const Uint8& getAtk2();
};
#endif