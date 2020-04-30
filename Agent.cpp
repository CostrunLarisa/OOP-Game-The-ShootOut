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
	int ok1 = 1;
	int ok2 = 1;
	int poz = 0;
	for (int k = 0; k < getWeapons(); k++)
	{
		if (Hammers* b = dynamic_cast<Hammers*>(weapon[k]))
		{
			ok2 = 0;
			poz = k;
			cout << "Agent on the position (" << getX() << "," << getY() << ") tries to attack!";
			if (this->getSFWeapons() > 0)				//if the current agent has a self-defense weapon,we choose randomly one
			{
				for (int l = 0; l < getSFWeapons(); l++)
				{
					if (Scut* c = dynamic_cast<Scut*>(protect[l]))
					{
						c->shootH(b);
						break;
					}
					else if (StoneGloves* c = dynamic_cast<StoneGloves*>(protect[l]))
					{
						c->shootH(b);
						break;
					}
					else if (Cap* c = dynamic_cast<Cap*>(protect[l])) {
						c->shootH(b);
						break;
					}
				}
			}
			else {
				b->shootW();
			}
			break;
		}
	}
	
	if (ok2 == 1)
	{
		for (int k = 0; k < getWeapons(); k++)
		{
			if (Guns* b = dynamic_cast<Guns*>(weapon[k]))
			{
				ok1 = 0;
				poz = k;
				cout << "Agent on the position (" << getX() << "," << getY() << ") tries to attack!";
				if (this->getSFWeapons() > 0)				//if the current agent has a self-defense weapon,we choose randomly one
				{
					int choice1 = 1;
					int choice2 = 1;
					int choice3 = 1;
					int poz2 = 0;
					for (int l = 0; l < getSFWeapons(); l++)
					{
						if (Scut* c = dynamic_cast<Scut*>(protect[l]))
						{
							choice1 = 0;
							c->shootG(b);
							break;
						}
					}
					if (choice1 == 0)
					{
						for (int l = 0; l < getSFWeapons(); l++)
						{
							if (StoneGloves* c = dynamic_cast<StoneGloves*>(protect[l]))
							{
								choice2 = 0;
								c->shootG(b);
								break;
							}
						}
					}
					if (choice2 == 0)
					{
						for (int l = 0; l < getSFWeapons(); l++)
						{
							if (Cap* c = dynamic_cast<Cap*>(protect[l])) {
								c->shootG(b);
								break;
							}
						}
					}
				}
				else {
					b->shootW();
				}
				break;
			}
		}
	}
	if (ok1 == 1)
	{
		for (int k = 0; k < getWeapons(); k++)
		{
			if (Knives* b = dynamic_cast<Knives*>(weapon[k]))
			{
				poz = k;
				cout << "Agent on the position (" << getX() << "," << getY() << ") tries to attack!";
				if (this->getSFWeapons() > 0)				//if the current agent has a self-defense weapon,we choose randomly one
				{
					for (int l = 0; l < getSFWeapons(); l++)
					{
						if (Scut* c = dynamic_cast<Scut*>(protect[l]))
						{
							c->shootK(b);
							break;
						}
						else if (StoneGloves* c = dynamic_cast<StoneGloves*>(protect[l]))
						{
							c->shootK(b);
							break;
						}
						else if (Cap* c = dynamic_cast<Cap*>(protect[l]))
						{
							c->shootK(b);
							break;
						}
					}
				}
				else {
					b->shootW();
				}
				break;
			}
		}
	}
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
