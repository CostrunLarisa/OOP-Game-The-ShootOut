#ifndef ARMURI_H
#define ARMURI_H
#include "Guns.h"
#include "Knives.h"
#include "Hammers.h"


class Guns;
class Hammers;
class Knives;

class Armuri							//abstract class for the weapons that protect the agent
{
	int poz1;
	int poz2;
public:
	Armuri(int x=0, int y=0);
	virtual void afisare() = 0;			//method that displays a message when we collect a weapon that protects
	virtual void shootG(Arma*) = 0;		//we create virtual methods for shooting in a specific way,depending of the weapon
	virtual void shootK(Arma*) = 0;
	virtual void shootH(Arma*) = 0;
	int getX() const;
	int getY() const;
};
#endif

