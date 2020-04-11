#include "Agent.h"
#include "Arma.h"
#include "Armuri.h"
#include "Knives.h"
#include "Cap.h"
#include<vector>
#include<iostream>
using namespace std;

int Agent::arie = 2;
Agent::Agent(int poz1, int poz2) :pozitieOx(poz1),pozitieOy(poz2)
{
	Arma* ar = new Knives(this->pozitieOx, this->pozitieOy);	//we want to start the game with each agent having the same tools															
	weapon.push_back(*ar);										//hence each object of Agent class will have a weapon-object of type Knives,and a self-defense weapon of type Cap
	Armuri* arr = new Cap(this->pozitieOx, this->pozitieOy);
	protect.push_back(*arr);
}

bool Agent::isFree(int x, int y)			
{
	if (((pozitieOx-arie<=x || pozitieOx + arie >= x) && y==pozitieOy) || ((pozitieOy-arie <= y || pozitieOy + arie >= y) && x=pozitieOx))return 1;
	return 0;
}

int Agent::getView()
{
	return arie;
}
void Agent::afisare()
{

}