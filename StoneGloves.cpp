#include "StoneGloves.h"
#include "Armuri.h"
#include<iostream>
#include "Guns.h"
#include "Hammers.h"
#include "Knives.h"
using namespace std;

StoneGloves::StoneGloves(int x,int y):Armuri(x,y){}
StoneGloves::StoneGloves() :Armuri(0,0){}
void StoneGloves::afisare()
{
	cout << "stone gloves";
}

void StoneGloves::shootG(Arma* g)
{
	cout << "STONE GLOVES ACTIVATED" << endl;
	cout << "Stonne Gloves and ";
	g->afis();
	cout << "!" << endl;
	cout << "Oh no!!The StoneGloves have been activated!The enemy stands no chances in winning" << endl;
	cout << "This combination is LETAL!!!! ^o^" << endl;
}

void StoneGloves::shootH(Arma* h)
{
	cout << "STONE GLOVES ACTIVATED" << endl;
	cout << "Stone Gloves and ";
	h->afis();
	cout<< ", I'd better watch out!";
	cout << "This will empower the shoot!" << endl;
}

void StoneGloves::shootK(Arma* k)
{
	cout << "STONE GLOVES ACTIVATED" << endl;
	cout << "Oh,man!" << endl;
	cout << "Stonne Gloves and ";
	k->afis();
	cout << ", I'd better watch out!This combination is just frizzing the enemy!"<<endl;
}