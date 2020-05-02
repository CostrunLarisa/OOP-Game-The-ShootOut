#ifndef HAMMERS_H
#define HAMMERS_H
#include "Arma.h"

class Hammers :virtual public Arma
{
public:
	Hammers(int,int);
	Hammers();
	virtual void afis();
	virtual void shootW();
};
#endif
