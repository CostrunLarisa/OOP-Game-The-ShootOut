#include "Scut.h"
#include "Armuri.h"
#include<iostream>
#include "Guns.h"
#include "Hammers.h"
#include "Knives.h"
using namespace std;

Scut::Scut(int x,int y):Armuri(x,y){}

void Scut::afisare()
{
	cout << "scut";
}
void Scut::shoot(Guns g)
{
	cout << "Oh no!!The StoneGloves gave been activated!The enemy stands no chances in winning" << endl;
	cout << "This combination is LETAL!!!! ^o^" << endl;
}

void Scut::shoot(Knives k)
{
	cout << "The agent has only a knife and a cap, unfortunately he can't attack with this combination. :(" << endl;
	cout << "But thanks to the cap,he won't die." << endl;
}

void Scut::shoot(Hammers h)
{
	cout << "Yees! It looks like somebody it's safe from the guns." << endl;
}