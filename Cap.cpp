#include "Cap.h"
#include "Armuri.h"
#include "Guns.h"
#include "Hammers.h"
#include "Knives.h"
#include<iostream>
using namespace std;

Cap::Cap(int x, int y) :Armuri(x, y) {}

void Cap::afisare()
{
	cout << "cap";
}
void Cap::shoot(Guns g)
{
	cout << "Oh no!!The StoneGloves gave been activated!The enemy stands no chances in winning" << endl;
	cout << "This combination is LETAL!!!! ^o^" << endl;
}

void Cap::shoot(Knives k)
{
	cout << "The agent has only a knife and a cap, unfortunately he can't attack with this combination. :(" << endl;
	cout << "But thanks to the cap,he won't die." << endl;
}

void Cap::shoot(Hammers h)
{
	cout << "Yees! It looks like somebody it's safe from the guns." << endl;
}