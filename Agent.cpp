#include "Agent.h"
#include "Arma.h"
#include "Armuri.h"
#include "Knives.h"
#include "Cap.h"
#include<vector>
#include<iostream>
using namespace std;


Agent::Agent(int poz1, int poz2) :pozitieOx(poz1),pozitieOy(poz2)
{
	Arma* ar = new Knives(this->pozitieOx, this->pozitieOy);
	weapon.push_back(*ar);
	Armuri* arr = new Cap(this->pozitieOx, this->pozitieOy);
	protect.push_back(*arr);
}

void Agent::afisare()
{

}