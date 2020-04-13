#ifndef ARMURI_H
#define ARMURI_H
#include "Guns.h"
#include "Knives.h"
#include "Hammers.h"


class Guns;
class Hammers;
class Knives;

class Armuri
{
	int poz1;
	int poz2;
public:
	Armuri(int x=0, int y=0);
	virtual void afisare() = 0;
	virtual void shootG(Arma*) = 0;		//we create virtual method for the attack,depending oh the parameters wich method"shoot" will receive
										//the current weapon will shoot differently
	virtual void shootK(Arma*) = 0;
	virtual void shootH(Arma*) = 0;
	int getX() const;
	int getY() const;
};
#endif

