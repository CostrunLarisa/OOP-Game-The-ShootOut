#ifndef _CAP_H_
#define _CAP_H_
#include "Armuri.h"
#include "Harta.h"
#include "Agent.h"
#include "Guns.h"
#include "Hammers.h"
#include "Knives.h"
class Cap :
	virtual public Armuri
{
public:
	Cap(int x,int y);
	virtual void afisare();
	virtual void shoot(Guns);
	virtual void shoot(Hammers);
	virtual void shoot(Knives);
};

#endif