#include "Guns.h"
#include "Arma.h"
#include<iostream>
using namespace std;

Guns::Guns(int x, int y) :Arma(x, y) {};

void Guns::afis()
{
	cout << "gun";
}

void Guns::shootW()
{
	cout << "Gun Activated! Our agent is lucky today!This weapon KILLS" << endl;
}

