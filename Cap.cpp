#include "Cap.h"
#include "Armuri.h"
#include "Guns.h"
#include "Hammers.h"
#include "Knives.h"
#include<iostream>
using namespace std;

Cap::Cap(int x, int y) :Armuri(x, y) {}
Cap::Cap():Armuri(0,0){}
void Cap::afisare()
{
	cout << "cap";
}
void Cap::shootG(Arma* g)
{
	cout << "CAP ACTIVATED!" << endl;
	cout << "Cap and ";
	g->afis();
	cout << ", I'd better watch out!"<<endl;
	cout << " With this combination,the agent is invincible AND he can kill!" << endl;
}

void Cap::shootK(Arma* k)
{
	cout << "CAP ACTIVATED!" << endl;
	cout << "Cap and ";
	k->afis();
	cout << "!"<<endl;
	cout << "Unfortunately,the cap protects him,but isn't allowing him to give a LETAL shoot." << endl;
}

void Cap::shootH(Arma* h)
{
	cout << "CAP ACTIVATED!" << endl;
	cout << "Cap and ";
	h->afis();
	cout << ", I'd better watch out!"<<endl;
	cout << "Our agent isn't lucky today...the cap just protects him" << endl;
}