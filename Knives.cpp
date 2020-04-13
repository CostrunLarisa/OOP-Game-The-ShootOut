#include "Knives.h"
#include "Arma.h"
#include<iostream>
using namespace std;

Knives::Knives(int x,int y):Arma(x,y){}
void Knives::afis()
{
	cout << "knife";
}

void Knives::shootW()
{
	cout << "Knife Activated!This weapon keeps you alive,but doesn't kill!" << endl;
}


