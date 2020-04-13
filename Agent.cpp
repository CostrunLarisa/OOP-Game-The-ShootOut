#include "Agent.h"
#include "Arma.h"
#include "Armuri.h"
#include "Knives.h"
#include "Cap.h"
#include "StoneGloves.h"
#include "Scut.h"
#include<vector>
#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

int Agent::arie = 2;

Agent::Agent(int poz1, int poz2) :pozitieOx(poz1),pozitieOy(poz2)
{
	Knives* ar = new Knives(this->pozitieOx, this->pozitieOy);	//we want to start the game with each agent having the same tools															
	weapon.push_back(ar);										//hence each object of Agent class will have a weapon-object of type Knives,and a self-defense weapon of type Cap
	Cap* arr = new Cap(this->pozitieOx, this->pozitieOy);
	protect.push_back(arr);
}


void Agent::chargeWeapon(Arma* a)
{
	weapon.push_back(a);
}
void Agent::chargeDefWeapon(Armuri* a)
{
	protect.push_back(a);
}
void Agent::attack()
{
	int option = rand() % getWeapons();
		Arma* b = (Arma*)weapon[option];

		if (this->getSFWeapons() > 0)				//if the current agent has a self-defense weapon,we choose randomly one
		{
			int secondop = rand() % getSFWeapons();
			Armuri* a = (Armuri*)protect[secondop];
			//a->shoot(*b);				//downcasting,not working
		}
		else { b->shootW(); }			//downcasting
}

void Agent::setArie(int x)
{
	arie = x;
}
void Agent::setX(int x)
{
	pozitieOx = x;
}
void Agent::setY(int y)
{
	pozitieOy = y;
}
int Agent::getWeapons()
{
	int nr = 0;
	for (int i = 0; i < weapon.size(); i++)
		nr++;
	return nr;
}
int Agent::getSFWeapons()
{
	int nr = 0;
	for (int i = 0; i < protect.size(); i++)
		nr++;
	return nr;
}
int Agent::getX() const {
	return pozitieOx;
}
int Agent::getY() const{
	return pozitieOy;
}
int Agent::getView()
{
	return arie;
}
