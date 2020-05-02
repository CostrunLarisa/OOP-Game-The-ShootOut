#include "Hammers.h"
#include "Arma.h"
#include<iostream>
using namespace std;
Hammers::Hammers(int x, int y) :Arma(x, y) {}
Hammers::Hammers():Arma(0,0){}
void Hammers::afis()
{
	cout << "hammer";
}

void Hammers::shootW()
{
	cout << "Hammer Activated!" << endl;
	cout << "Hm..." << endl;
	cout << "This weapon is like throwing with a flower." << endl;
	cout << "But it will be useful for keeping the agent alive!" << endl;
}
