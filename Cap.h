#ifndef _CAP_H_
#define _CAP_H_
#include "Armuri.h"
#include "Harta.h"
#include "Agent.h"
class Cap :
	virtual public Armuri
{
public:
	Cap(int x,int y);
	virtual void afisare();
};

#endif