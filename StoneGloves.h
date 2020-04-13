#ifndef STONEGLOVES_H
#define STONEGLOVES_H
#include "Armuri.h"
#include "Harta.h"
#include "Agent.h"
#include "Guns.h"
#include "Hammers.h"
#include "Knives.h"
class StoneGloves :
	virtual public Armuri
{
public:
	StoneGloves(int, int);
	virtual void afisare();
	virtual void shoot(Guns);
	virtual void shoot(Hammers);
	virtual void shoot(Knives);
};
#endif
