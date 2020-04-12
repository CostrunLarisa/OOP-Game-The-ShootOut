#ifndef KNIVES_H
#define KNIVES_H
#include "Arma.h"
#include "Harta.h"
#include "Agent.h"
class Knives : virtual public Arma
{
public:
	Knives(int,int);
	virtual void afis();
};
#endif

