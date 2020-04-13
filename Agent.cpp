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
int Agent::arie = 3;
Agent::Agent(int poz1, int poz2) :pozitieOx(poz1),pozitieOy(poz2)
{
	Knives* ar = new Knives(this->pozitieOx, this->pozitieOy);	//we want to start the game with each agent having the same tools															
	weapon.push_back(ar);										//hence each object of Agent class will have a weapon-object of type Knives,and a self-defense weapon of type Cap
	Cap* arr = new Cap(this->pozitieOx, this->pozitieOy);
	protect.push_back(arr);
}


void Agent::chargeWeapon(Arma* a)
{
	this->weapon.push_back(a);
}
void Agent::chargeDefWeapon(Armuri* a)
{
	this->protect.push_back(a);
}
void Agent::attack()
{
	srand((unsigned)time(0));
	int option = rand() % getWeapons();
	cout << "Agent on the position (" << getX() << "," << getY() << ") tries to attack!";
		Arma* b = (Arma*)weapon[option];
		if (this->getSFWeapons() > 0)				//if the current agent has a self-defense weapon,we choose randomly one
		{
			int secondop = rand() % getSFWeapons();
			int choose = (rand() % 3) + 1;
			Armuri* a = (Armuri*)protect[secondop];
			if(choose==1)a->shootG(b);
			else if(choose==2)a->shootK(b);
			else a->shootH(b);
						//downcasting,not working
		}
		else { b->shootW(); }			//downcasting
}

void Agent::show()
{
	cout << "He has collected the weapons:";
	for (int i = 0; i < weapon.size(); i++)
	{
		weapon[i]->afis();
		cout << ",";
	}
	cout << endl;
	cout << "And the self-defense weapons:";
	for (int j = 0; j < protect.size(); j++)
	{
		protect[j]->afisare();
		cout << ",";
	}
	cout << endl;
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
