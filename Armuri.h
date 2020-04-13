#ifndef ARMURI_H
#define ARMURI_H
#include "Guns.h"
#include "Knives.h"
#include "Hammers.h"
class Armuri
{
	int poz1;
	int poz2;
public:
	Armuri(int x=0, int y=0);
	virtual void afisare() = 0;
	virtual void shoot(Guns) = 0;		//we create virtual method for the attack,depending oh the parameters wich method"shoot" will receive
										//the current weapon will shoot differently
	virtual void shoot(Knives) = 0;
	virtual void shoot(Hammers) = 0;
	int getX() const;
	int getY() const;
};
#endif

