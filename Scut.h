#ifndef SCUT_H
#define SCUT_H
#include "Armuri.h"
#include "Harta.h"
#include "Agent.h"
class Scut :
	virtual public Armuri
{
public:
	Scut(int, int);
	virtual void afisare();
};

#endif