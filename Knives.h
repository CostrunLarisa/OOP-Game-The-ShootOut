#ifndef KNIVES_H
#define KNIVES_H
#include "Arma.h"
class Knives :virtual public Arma
{
public:
	Knives(int,int);
	virtual void afis();		
	virtual void shootW();
};
#endif

