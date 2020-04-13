#include "StoneGloves.h"
#include "Armuri.h"
#include<iostream>
#include "Guns.h"
#include "Hammers.h"
#include "Knives.h"
using namespace std;

StoneGloves::StoneGloves(int x,int y):Armuri(x,y){}

void StoneGloves::afisare()
{
	cout << "stone gloves";
}

void StoneGloves::shoot(Guns g)
{
	cout << "Oh no!!The StoneGloves have been activated!The enemy stands no chances in winning" << endl;
	cout << "This combination is LETAL!!!! ^o^" << endl;
}

void StoneGloves::shoot(Hammers h)
{
	cout << "The agent has only a knife and a cap, unfortunately he can't attack with this combination. :(" << endl;
	cout << "But thanks to the cap,he won't die." << endl;
}

void StoneGloves::shoot(Knives k)
{
	cout << "Yees! It looks like somebody it's safe from the guns." << endl;
}