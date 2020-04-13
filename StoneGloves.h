#ifndef STONEGLOVES_H
#define STONEGLOVES_H
#include "Armuri.h"
#include "Harta.h"
#include "Agent.h"
#include "Guns.h"
#include "Hammers.h"
#include "Knives.h"
class Guns;
class Hammers;
class Knives;
class Armuri;
class StoneGloves :
	virtual public Armuri
{
public:
	StoneGloves(int, int);
	virtual void afisare();
	virtual void shootG(Arma*);
	virtual void shootH(Arma*);
	virtual void shootK(Arma*);
};
#endif
