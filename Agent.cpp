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
void Agent::steal(Agent* a)
{
	for (int i = 0; i < a->weapon.size(); i++)
	{
		if (Hammers* b = dynamic_cast<Hammers*>(a->weapon[i]))
		{
			cout << "The Killer has stolen the weapon:";
			a->weapon[i]->afis();
			cout << " from the agent on the position (" << a->pozitieOx << "," << a->pozitieOy << ")!" << endl;
			this->chargeWeapon(a->weapon[i]);
		}
		if (Guns* b = dynamic_cast<Guns*>(a->weapon[i]))
		{
			cout << "The Killer has stolen the weapon:";
			a->weapon[i]->afis();
			cout << " from the agent on the position (" << a->pozitieOx << "," << a->pozitieOy << ")!" << endl;
			this->chargeWeapon(a->weapon[i]);
		}
	}
	for (int j = 0; j <a->protect.size(); j++)
	{
		if (Scut* b = dynamic_cast<Scut*>(a->protect[j]))
		{
			cout << "The Killer has stolen the self-defense weapon:";
			a->protect[j]->afisare();
			cout << " from the agent on the position (" << a->pozitieOx << "," << a->pozitieOy << ")!" << endl;
			this->chargeDefWeapon(a->protect[j]);
		}
		if (StoneGloves * c = dynamic_cast<StoneGloves*>(a->protect[j]))
		{
			cout << "The Killer has stolen the self-defense weapon:";
			a->protect[j]->afisare();
			cout << " from the agent on the position (" << a->pozitieOx << "," << a->pozitieOy << ")!" << endl;
			this->chargeDefWeapon(a->protect[j]);
		}
	}
	cout << endl;
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
	//this method decides which weapons and which combination one agent will use
	//first, he search for the strongest combination of weapons: hammer and scut, 
	//if he doesn't have such combination then he will look for weapons in the order of the power of combination and weapons
	//then,he has the following combination in order of the strength:
	// hammer and StoneGloves; hammer and cap,so the weapons that protects him, sorted by the power are in this order:scut,StoneGloves,cap
	//the weapons sorted by the power:hammer,gun,knife
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
				int choice1 = 1;
				int choice2 = 1;
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
				if (choice1 == 1)
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
				if (choice2 == 1 && choice1 == 1)
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
					if (choice1 == 1)
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
					if (choice2 == 1 && choice1==1)
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
	if (ok1 == 1 && ok2==1)
	{
		for (int k = 0; k < getWeapons(); k++)
		{
			if (Knives* b = dynamic_cast<Knives*>(weapon[k]))
			{
				poz = k;
				cout << "Agent on the position (" << getX() << "," << getY() << ") tries to attack!";
				if (this->getSFWeapons() > 0)				//if the current agent has a self-defense weapon,we choose randomly one
				{
					int choice1 = 1;
					int choice2 = 1;
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
					if (choice1 == 1)
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
					if (choice2 == 1 && choice1==1)
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
Agent::~Agent() {
	cout << "Agent from the position (" << pozitieOx << "," << pozitieOy << ") died in the game." << endl;
	show();
	weapon.clear();
	protect.clear();	
}
