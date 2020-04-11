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
#include <cstdlib>
#include<ctime>
#include <iostream>
using namespace std;
int Harta::runda = 0;

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

void Harta::AgentMoves()
{
	for (auto elem: Harta::agent)
	{
		int arie = elem.getView();
	}
}
void Harta::show()
{
	for(int i=0;i<)
}
void Harta::configuration()
{
	for (int i = 0; i < agent.size(); i++)
	{
		cout << "Agent" <<i+1<<":";
		agent[i].afisare();
	}
	for(int i=0;i<weapons.size();i++)
	for(int i=0;i<protection.size();i++)
}

int Harta::getSize() const
{
	return limitX;
}
int Harta::getWeapons() const
{
	return weapons.size();
}
int Harta::getProtect() const
{
	return protection.size();
}
int Harta::getAgents() const
{
	return agent.size();
}