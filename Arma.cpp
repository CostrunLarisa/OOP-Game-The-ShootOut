#include "Arma.h"
#include <iostream>
using namespace std;

Arma::Arma(int x, int y)
{
	pozX = x;
	pozY = y;
}
int Arma::getX() const
{
	return pozX;
}
int Arma::getY() const
{
	return pozY;
}