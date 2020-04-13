#ifndef SCUT_H
#define SCUT_H
#include "Armuri.h"
#include "Harta.h"
#include "Agent.h"
#include "Guns.h"
#include "Hammers.h"
#include "Knives.h"
class Scut :
	virtual public Armuri
{
public:
	Scut(int, int);
	virtual void afisare();
	virtual void shoot(Guns);
	virtual void shoot(Hammers);
	virtual void shoot(Knives);
};

#endif