#ifndef GUNS_H
#define GUNS_H
#include "Arma.h"

class Guns :virtual public Arma
{
public:
	Guns(int,int);
	virtual void afis();
	virtual void shootW();
};

#endif 