#ifndef KNIVES_H
#define KNIVES_H
#include "Arma.h"
#include "Harta.h"
#include "Agent.h"
class Arma;
class Knives : public Arma
{
public:
	Knives(int,int);
	virtual void afis();
	virtual void shootW();
};
#endif

