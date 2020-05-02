#include "Guns.h"
#include "Arma.h"
#include<iostream>
using namespace std;

Guns::Guns(int x, int y) :Arma(x, y) {}
Guns::Guns():Arma(0, 0) {}

void Guns::afis()
{
	cout << "gun";
}

void Guns::shootW()
{
	cout << "Gun Activated! Our agent is lucky today!This weapon KILLS" << endl;
}

