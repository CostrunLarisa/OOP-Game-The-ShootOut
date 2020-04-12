#ifndef STONEGLOVES_H
#define STONEGLOVES_H
#include "Armuri.h"
#include "Harta.h"
#include "Agent.h"
class StoneGloves :
	virtual public Armuri
{
public:
	StoneGloves(int, int);
	virtual void afisare();
};
#endif
