#ifndef HAMMERS_H
#define HAMMERS_H
#include "Arma.h"
#include "Harta.h"
#include "Agent.h"
class Hammers :public Arma
{
public:
	Hammers(int,int);
	virtual void afis();
	virtual void shootW();
};
#endif
