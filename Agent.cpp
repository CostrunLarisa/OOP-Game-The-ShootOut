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
void Agent::steal(Agent* a)												//we check if the agent has more weapons, others than the ones from the starter-pack
																		//if so,then the Killer steals the weapons
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
int Agent::getOpponentCombo(Agent* a)
{
	int ok1 = 1;
	int ok2 = 1;
	for (int k = 0; k < a->getWeapons(); k++)
	{
		if (Hammers* b = dynamic_cast<Hammers*>(a->weapon[k]))
		{
				ok2 = 0;
				int choice1 = 1;
				int choice2 = 1;
				for (int l = 0; l < a->getSFWeapons(); l++)
				{
					if (Scut* c = dynamic_cast<Scut*>(a->protect[l]))
					{
						choice1 = 0;
						return 11;
					}
				}
				if (choice1 == 1)
				{
					for (int l = 0; l < a->getSFWeapons(); l++)
					{
						if (StoneGloves* c = dynamic_cast<StoneGloves*>(a->protect[l]))
						{
							choice2 = 0;
							return 12;
						}
					}
				}
				if (choice2 == 1 && choice1 == 1)
				{
					for (int l = 0; l < a->getSFWeapons(); l++)
					{
						if (Cap* c = dynamic_cast<Cap*>(a->protect[l])) {
							return 13;
						}
					}
				}
			
		}
	}

	if (ok2 == 1)
	{
		for (int k = 0; k < a->getWeapons(); k++)
		{
			if (Guns* b = dynamic_cast<Guns*>(a->weapon[k]))
			{
				ok1 = 0;
				int choice1 = 1;
				int choice2 = 1;
				
					for (int l = 0; l <a-> getSFWeapons(); l++)
					{
						if (Scut* c = dynamic_cast<Scut*>(a->protect[l]))
						{
							choice1 = 0;
							return 21;
						}
					}
					if (choice1 == 1)
					{
						for (int l = 0; l < a->getSFWeapons(); l++)
						{
							if (StoneGloves* c = dynamic_cast<StoneGloves*>(a->protect[l]))
							{
								choice2 = 0;
								return 22;
							}
						}
					}
					if (choice2 == 1)
					{
						for (int l = 0; l < a->getSFWeapons(); l++)
						{
							if (Cap* c = dynamic_cast<Cap*>(a->protect[l])) {
								return 23;
							}
						}
					}
				
		
			}
		}
	}
	if (ok1 == 1)
	{
		for (int k = 0; k < a->getWeapons(); k++)
		{
			if (Knives* b = dynamic_cast<Knives*>(a->weapon[k]))
			{
				
					int choice1 = 1;
					int choice2 = 1;
					for (int l = 0; l < a->getSFWeapons(); l++)
					{
						if (Scut* c = dynamic_cast<Scut*>(a->protect[l]))
						{
							choice1 = 0;
							return 31;
						}
					}
					if (choice1 == 1)
					{
						for (int l = 0; l < a->getSFWeapons(); l++)
						{
							if (StoneGloves* c = dynamic_cast<StoneGloves*>(a->protect[l]))
							{
								choice2 = 0;
								return 32;
							}
						}
					}
			}
		}
	}
	return 33;		//if he gets here,then the only weapons he has are cap and knife
}
Agent Agent::attack(Agent* opponent)
{
	//this method decides which weapons and which combination one agent will use
	//first, he search for the strongest combination of weapons: hammer and scut, 
	//if he doesn't have such combination then he will look for weapons in the order of the power of combination and weapons
	//then,he has the following combination in order of the strength:
	// hammer and StoneGloves; hammer and cap,so the weapons that protects him, sorted by the power are in this order:scut,StoneGloves,cap
	//the weapons sorted by the power:hammer,gun,knife
	int power = getOpponentCombo(opponent);
	for (int k = 0; k < getWeapons(); k++)
	{
		if (Hammers* b = dynamic_cast<Hammers*>(weapon[k]))
		{
			
			cout << "Agent on the position (" << this->getX() << "," <<this->getY() << ") tries to attack!";
				for (int l = 0; l < getSFWeapons(); l++)
				{
					if (Scut* c = dynamic_cast<Scut*>(protect[l]))
					{
						b->shootW();
						c->shootH(b);
						return *this;
					}
				}
				for (int l = 0; l < getSFWeapons(); l++)
					{
						if (StoneGloves* c = dynamic_cast<StoneGloves*>(protect[l]))
						{
							
							if (power >= 12)			//if the opponent has a weaker combination or equal,he loses
							{
								b->shootW();
								c->shootG(b);
								return *this;
							}
							if (power==11){
								Scut* p = new Scut();
								b->shootW();
								p->shootH(b);			//else that means he has hammer+scut,he shoots,he isthe winner
								return *opponent;
							}
						}
					}
				
				for (int l = 0; l < getSFWeapons(); l++)
					{
						if (Cap* c = dynamic_cast<Cap*>(protect[l])) {
							if (power >= 13)			//if the opponent has a weaker combination or equal,he loses
							{	
								b->shootW();
								c->shootH(b);
								return *this;
							}
							if (power==11){
								Scut* p= new Scut();
								b->shootW();
								p->shootH(b);			//else that means he has hammer+scut,he shoots,he is the winner
								return *opponent;
							}
							 if (power == 12) {
								StoneGloves* p = new StoneGloves();
								b->shootW();
								p->shootH(b);
								return *opponent;
							}
						
						}
					}
				
			
		}
	}
	
	for (int k = 0; k < getWeapons(); k++)
		{
			if (Guns* b = dynamic_cast<Guns*>(weapon[k]))
			{
				
				cout << "Agent on the position (" <<this->getX() << "," << this->getY() << ") tries to attack!";
					for (int l = 0; l < getSFWeapons(); l++)
					{
						if (Scut* c = dynamic_cast<Scut*>(protect[l]))
						{
							if (power >= 21)
							{
								b->shootW();
								c->shootG(b);
								return *this;

							}
							if (power==11){
								Scut* p= new Scut();
								Hammers* h = new Hammers();
								h->shootW();
								p->shootH(h);			//else that means he has hammer+scut,he shoots,he is the winner
								return *opponent;
							}
							if (power == 12) {
								StoneGloves* p = new StoneGloves();
								Hammers* h = new Hammers();
								h->shootW();
								p->shootH(h);
								return *opponent;
							}
							
						}
					}
					for (int l = 0; l < getSFWeapons(); l++)
					{
							if (StoneGloves* c = dynamic_cast<StoneGloves*>(protect[l]))
							{
								
								if (power >= 22)
								{
									b->shootW();
									c->shootG(b);
									return *this;
								}
								if (power == 21)
								{
									Scut* p = new Scut();
									b->shootW();
									p->shootG(b);
									return *opponent;
								}
								if (power == 11) {
									Scut* p = new Scut();
									Hammers* h = new Hammers();
									h->shootW();
									p->shootH(h);			//else that means he has hammer+scut,he shoots,he is the winner
									return *opponent;
								}
								if (power == 12) {
									StoneGloves* p = new StoneGloves();
									Hammers* h = new Hammers();
									h->shootW();
									p->shootH(h);
									return *opponent;
								}
							}
					}
					
					for (int l = 0; l < getSFWeapons(); l++)
						{
							if (Cap* c = dynamic_cast<Cap*>(protect[l])) 
							{
								if (power >= 23)
								{
									b->shootW();
									c->shootG(b);
									return *this;
								}
								if (power == 22)
								{
									StoneGloves* p = new StoneGloves();
									b->shootW();
									p->shootG(b);
									return *opponent;
								}
								if (power == 21)
								{
									Scut* p = new Scut();
									b->shootW();
									p->shootG(b);
									return *opponent;
								}
								if (power == 11) {
									Scut* p = new Scut();
									Hammers* h = new Hammers();
									h->shootW();
									p->shootH(h);			//else that means he has hammer+scut,he shoots,he is the winner
									return *opponent;
								}
								if (power == 12) {
									StoneGloves* p = new StoneGloves();
									Hammers* h = new Hammers();
									h->shootW();
									p->shootH(h);
									return *opponent;
								}
							}
					}
					
				
	
			}
		}
	
	for (int k = 0; k < getWeapons(); k++)
	{
			if (Knives* b = dynamic_cast<Knives*>(weapon[k]))
			{
				
					cout << "Agent on the position (" << this->getX() << "," << this->getY() << ") tries to attack!";
					for (int l = 0; l < getSFWeapons(); l++)
					{
						if (Scut* c = dynamic_cast<Scut*>(protect[l]))
						{
							
							if (power >= 31)
							{
								b->shootW();
								c->shootK(b);
								return *this;
								
							}
							if (power == 23)
							{
								Cap* p = new Cap();
								b->shootW();
								p->shootG(b);
								return *opponent;
							}
							if (power == 22)
							{	
								StoneGloves* p = new StoneGloves();
								b->shootW();
								p->shootG(b);
								return *opponent;
							}
							if (power == 21)
							{
								Scut* p = new Scut();
								b->shootW();
								p->shootG(b);
								return *opponent;
							}
							if (power == 11) {
								Scut* p = new Scut();
								Hammers* h = new Hammers();
								h->shootW();
								p->shootH(h);			//else that means he has hammer+scut,he shoots,he is the winner
								return *opponent;
							}
							if (power == 12) {
								StoneGloves* p = new StoneGloves();
								Hammers* h = new Hammers();
								h->shootW();
								p->shootH(h);
								return *opponent;
							}
							
						}
					}
					for (int l = 0; l < getSFWeapons(); l++)
						{
							if (StoneGloves* c = dynamic_cast<StoneGloves*>(protect[l]))
							{
								
								if (power >= 32)
								{
									b->shootW();
									c->shootK(b);
									return *this;
									
								}
								if (power == 31)
								{
									Knives* p = new Knives();
									Scut* q = new Scut();
									p->shootW();
									q->shootK(p);
									return *opponent;
								}
								if (power == 23)
								{
									Cap* p = new Cap();
									b->shootW();
									p->shootG(b);
									return *opponent;
								}
								 if (power == 22)
								{
									StoneGloves* p = new StoneGloves();
									b->shootW();
									p->shootG(b);
									return *opponent;
								}
								 if (power == 21)
								{
									Scut* p = new Scut();
									b->shootW();
									p->shootG(b);
									return *opponent;
								}
								 if (power == 11) {
									Scut* p = new Scut();
									Hammers* h = new Hammers();
									h->shootW();
									p->shootH(h);			//else that means he has hammer+scut,he shoots,he is the winner
									return *opponent;
								}
								 if (power == 12) {
									StoneGloves* p = new StoneGloves();
									Hammers* h = new Hammers();
									h->shootW();
									p->shootH(h);
									return *opponent;
								}
								
							}
						}
					
					for (int l = 0; l < getSFWeapons(); l++)
					{
							if (Cap* c = dynamic_cast<Cap*>(protect[l])) {
								 if (power == 32)
								{
									Knives* p = new Knives();
									StoneGloves* q = new StoneGloves();
									p->shootW();
									q->shootK(p);
									return *opponent;
								}
								if (power == 31)
								{
									Knives* p = new Knives();
									Scut* q = new Scut();
									p->shootW();
									q->shootK(p);
									return *opponent;
								}
								if (power == 23)
								{
									Cap* p = new Cap();
									b->shootW();
									p->shootG(b);
									return *opponent;
								}
								if (power == 22)
								{
									StoneGloves* p = new StoneGloves();
									b->shootW();
									p->shootG(b);
									return *opponent;
								}
								if (power == 21)
								{
									Scut* p = new Scut();
									b->shootW();
									p->shootG(b);
									return *opponent;
								}
								if (power == 11) {
									Scut* p = new Scut();
									Hammers* h = new Hammers();
									h->shootW();
									p->shootH(h);		
									return *opponent;
								}
								if (power == 12) {	
									StoneGloves* p = new StoneGloves();
									Hammers* h = new Hammers();
									h->shootW();
									p->shootH(h);
									return *opponent;
								}
								
							}
					}
						
	
			}
	}
	
	return *this;			//if we arrived here neither one of them has a stronger combo,they have the basic starter-pack,or the same combos
							//in this case the priority has the one who initiated the battle,hence return *this
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
void Agent::Death() {
	cout << "Agent from the position (" << pozitieOx << "," << pozitieOy << ") died in the game." << endl;
	show();
	weapon.clear();
	protect.clear();	
}
