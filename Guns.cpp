#include "Guns.h"
#include "Arma.h"
#include<iostream>
using namespace std;

Guns::Guns(int x, int y) :Arma(x, y) {};
void Guns::afis()
{
	cout << "gun";
}