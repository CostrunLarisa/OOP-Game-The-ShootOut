#include "Scut.h"
#include "Armuri.h"
#include<iostream>
#include "Guns.h"
#include "Hammers.h"
#include "Knives.h"
using namespace std;

Scut::Scut(int x,int y):Armuri(x,y){}
Scut::Scut():Armuri(0,0){}
void Scut::afisare()
{
	cout << "scut";
}
void Scut::shootG(Arma* g)
{
	cout << "SCUT ACTIVATED!" << endl;
	cout << "Scut and ";
	g->afis();
	cout << ", I'd better watch out!";
	cout << "This time the scut has recovered from the damages and it's ready to hurt the enemy while protecting!" << endl;
}

void Scut::shootK(Arma* k)
{
	cout << "SCUT ACTIVATED!" << endl;
	cout << "Scut and ";
	k->afis();
	cout << "!"<<endl;
	cout << "Unfortunately,this combination just protects him!" << endl;
}

void Scut::shootH(Arma* h)
{
	cout << "SCUT ACTIVATED!" << endl;
	cout << "Scut and ";
	h->afis();
	cout << ", I'd better watch out!"<<endl;
	cout << "Yees! It looks like somebody it's safe from the guns." << endl;
}