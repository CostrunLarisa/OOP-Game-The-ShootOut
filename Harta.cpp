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

Harta::Harta(int x,int y=2)
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
		int nr1 = rand() % (limitX-1);
		int nr2 = rand() % (limitY-1);	//incerc sa ma asigur ca pozitiile nu se repeta i.e nu vom avea doua obiecte pe aceeasi pozitie
		int nr3 = rand() % (limitX-1);
		int nr4 = rand() % (limitY-1);
		int nr5 = rand() % (limitX-1);
		int nr6 = rand() % (limitY-1);
		Agent* a = new Agent(nr1,nr2);
		agent.push_back(*a);
		harta[nr1][nr2] = 'Agnt';
		int option = rand() % 3 + 1;
		if (option == 1)
		{
			Arma *ar = new Guns(nr3, nr4);
			weapons.push_back(*ar);
			harta[nr3][nr4] = 'Gun';
		}
		else if (option == 2)
		{
			Arma *ar = new Hammers(nr3, nr4);
			weapons.push_back(*ar);
			harta[nr3][nr4] = 'Ham';
		}
		else
		{
			Arma *ar = new Knives(nr3, nr4);
			weapons.push_back(*ar);
			harta[nr3][nr4] = 'Knf';
		}
		int option2 = rand() % 3 + 1;
		if (option2 == 1)
		{
			Armuri *arr = new Scut(nr5, nr6);
			harta[nr5][nr6] = 'Scut';
			protection.push_back(*arr);
		}
		else if(option2==1)
		{
			Armuri *arr = new Cap(nr5, nr6);
			harta[nr5][nr6] = 'Cap';
			protection.push_back(*arr);
		}
		else {
			Armuri *arr = new StoneGloves(nr5, nr6);
			harta[nr5][nr6] = 'Glv';
			protection.push_back(*arr);
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

void Harta::configuration()
{
	for (auto elem : Harta::agent)
	{
		elem.changePosition(harta&);
	}
	for (int i = 0; i < agent.size(); i++)
	{
		cout << "Agent" <<i+1<<":";
		agent[i].afisare();
	}
	for(int i=0;i<weapons.size();i++)
	for(int i=0;i<protection.size();i++)
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
void Harta::setValue(int x, int y, char a)
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
