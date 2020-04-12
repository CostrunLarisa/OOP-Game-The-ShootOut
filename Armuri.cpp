#include "Armuri.h"
#include <iostream>
using namespace std;
Armuri::Armuri(int x, int y)
{
	poz1 = x;
	poz2 = y;
}

int Armuri::getX() const
{
	return poz1;
}
int Armuri::getY() const
{
	return poz2;
}
