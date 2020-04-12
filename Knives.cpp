#include "Knives.h"
#include "Arma.h"
#include<iostream>
using namespace std;

Knives::Knives(int x,int y):Arma(x,y){}
void Knives::afis()
{
	cout << "knife";
}