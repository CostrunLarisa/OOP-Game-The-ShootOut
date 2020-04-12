#include "Harta.h"
#include "Agent.h"
#include "Arma.h"
#include "Armuri.h"
#include "Knives.h"
#include "Hammers.h"
#include "Guns.h"
#include "Scut.h"
#include "Cap.h"
#include "StoneGloves.h"
#include<vector>
#include<string>
#include <cstdlib>
#include<ctime>
#include <iostream>
using namespace std;

Harta::Harta(int x,int y)
{
	limitX = x;		
	limitY = y;
	harta = new char* [limitX];
	for (int i = 0; i < limitX; i++)
		harta[i] = new char[limitX];
	for (int i = 0; i < limitX; i++)
		for (int j = 0; j < limitX; i++)
			harta[i][j] = '*';
	srand((unsigned)time(0));			//vrem sa generam un numar random diferit de fiecare data pentru pozitiile agentilor
	for (int i = 0; i < limitX/8; i++)		//vrem sa populam aproximativ un sfert de harta
	{
		int first = rand() % (limitX-1);
		int second = rand() % (limitY-1);	//incerc sa ma asigur ca pozitiile nu se repeta i.e nu vom avea doua obiecte pe aceeasi pozitie
		int third = rand() % (limitX-1);
		int four = rand() % (limitY-1);
		int five = rand() % (limitX-1);
		int six = rand() % (limitY-1);
		Agent* a = new Agent(first,second);
		agent.push_back(*a);
		harta[first][second] = 'Agnt';
		int option = rand() % 3 + 1;
		if (option == 1)
		{
			Guns *ar = new Guns(third,four);
			weapons.push_back(ar);
			harta[third][four] = 'Gun';
		}
		else if (option == 2)
		{
			Hammers *ar = new Hammers(third, four);
			weapons.push_back(ar);
			harta[third][four] = 'Ham';
		}
		else
		{
			Knives *ar = new Knives(third,four);
			weapons.push_back(ar);
			harta[third][four] = 'Knf';
		}
		int option2 = rand() % 3 + 1;
		if (option2 == 1)
		{
			Scut *arr = new Scut(five,six);
			harta[five][six] = 'Scut';
			protection.push_back(arr);
		}
		else if(option2==1)
		{
			Cap *arr = new Cap(five,six);
			harta[five][six] = 'Cap';
			protection.push_back(arr);
		}
		else {
			StoneGloves *arr = new StoneGloves(five,six);
			harta[five][six] = 'Glv';
			protection.push_back(arr);
		}
	}

}

void Harta::deleteAgent(int x, int y)
{
	for (int i=0;i<agent.size();i++)
	{
		if (agent[i].getX() == x && agent[i].getY() == y)agent.erase(i + agent.begin());
	}
}
void Harta::collectWeapon(Agent &a,int x, int y)		//this method collects the weapon, erases it from the map and then set the weapon to the current agent
{
	try {
		int ok = 0;
		for (int i = 0; i < weapons.size();i++)
			if (weapons[i]->getX() == x && weapons[i]->getY() == y)
			{
				harta[x][y] = '*';
				weapons[i]->afis();
				a.chargeWeapon(weapons[i]);
				weapons.erase(i + weapons.begin());
				ok = 1;
				setWeapons();
				cout << "There are only " << getWeapons() << "  weapons left on the map!"<<endl;
			}
		
		if(ok==0)throw false;
	}
	catch (...)
	{
		for (int i = 0; i < protection.size(); i++)
		{
			if (protection[i]->getX() == x && protection[i]->getY() == y)
			{
				harta[x][y] = '*';
				Armuri* g = (Armuri*)protection[i];			//downcast thanks to Bogdan's tutorials,hope I'll remember to delete this before sending it
				a.chargeDefWeapon(protection[i]);
				protection.erase(i + protection.begin());
				setProtect();
				cout << "There are only " << getProtect() << " self-defense weapons left on the map!"<<endl;
			}
		}
	}
}
void Harta::configuration()
{
	for (auto elem : agent)
	{
		elem.changePosition(*this);
	}
}
void Harta::setWeapons()
{
	nrWeapons = weapons.size();
}
void Harta::setProtect()
{
	nrProtect = protection.size();
}
void Harta::setAgents()
{
	nrAgents = agent.size();
}
void Harta::setValue(int x, int y, int a)
{
	harta[x][y] = a;
}
int Harta::getSize() const
{
	return limitX;
}
int Harta::getWeapons() const
{
	return nrWeapons;
}
int Harta::getProtect() const
{
	return nrProtect;
}
int Harta::getAgents() const
{
	return nrAgents;
}
char Harta::getValue(int i,int j) const
{
	return harta[i][j];
}
void Harta::show()
{
	for (int i = 0; i < limitX; i++)
	{
		for (int j = 0; j < limitX; i++)
			cout << harta[i][j];
		cout << endl;
	}
}
