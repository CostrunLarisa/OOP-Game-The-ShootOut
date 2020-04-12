#include "Hammers.h"
#include "Arma.h"
#include<iostream>
using namespace std;
Hammers::Hammers(int x, int y) :Arma(x, y) {};

void Hammers::afis()
{
	cout << "hammer";
}