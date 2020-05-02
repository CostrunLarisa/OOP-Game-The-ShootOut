#ifndef _CAP_H_
#define _CAP_H_
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
class Cap :virtual public Armuri
{
public:
	Cap(int x,int y);
	Cap();
	virtual void afisare();
	virtual void shootG(Arma*);
	virtual void shootH(Arma*);
	virtual void shootK(Arma*);
};

#endif