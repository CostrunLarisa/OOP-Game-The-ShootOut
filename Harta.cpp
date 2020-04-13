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
		agent.push_back(a);
		harta[first][second] = 'A';
		int option = rand() % 3 + 1;
		if (option == 1)
		{
			Guns *ar = new Guns(third,four);
			weapons.push_back(ar);
			harta[third][four] = 'G';
		}
		else if (option == 2)
		{
			Hammers *ar = new Hammers(third, four);
			weapons.push_back(ar);
			harta[third][four] = 'H';
		}
		else
		{
			Knives *ar = new Knives(third,four);
			weapons.push_back(ar);
			harta[third][four] = 'K';
		}
		int option2 = rand() % 3 + 1;
		if (option2 == 1)
		{
			Scut *arr = new Scut(five,six);
			harta[five][six] = 'S';
			protection.push_back(arr);
		}
		else if(option2==1)
		{
			Cap *arr = new Cap(five,six);
			harta[five][six] = 'C';
			protection.push_back(arr);
		}
		else {
			StoneGloves *arr = new StoneGloves(five,six);
			harta[five][six] = 'G';
			protection.push_back(arr);
		}
	}

}

void Harta::deleteAgent(int x, int y)
{
	for (int i=0;i<agent.size();i++)
	{
		if (agent[i]->getX() == x && agent[i]->getY() == y)agent.erase(i + agent.begin());
	}
}
void Harta::collectWeapon(int i,int x, int y)		//this method collects the weapon, erases it from the map and then set the weapon to the current agent
{
	try {
		int ok = 0;
		for (int i = 0; i < weapons.size();i++)
			if (weapons[i]->getX() == x && weapons[i]->getY() == y)
			{
				harta[x][y] = '*';
				cout << "Agent from position" << x << "," << y << " has collected the weapon:";
				weapons[i]->afis();
				cout << "!";
				cout << "He has now:" << agent[i]->getWeapons() << " weapons." << endl;
				agent[i]->chargeWeapon(weapons[i]);
				weapons.erase(i + weapons.begin());
				ok = 1;
				setWeapons();
				cout << "There are only " << getWeapons() << "  weapons left to be found on the map!"<<endl;
				cout << "Who's gonna find them?" << endl;
				cout << "...Mistery..." << endl;
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
				//Armuri* g = (Armuri*)protection[i];			//downcast thanks to Bogdan's tutorials,hope I'll remember to delete this before sending it
				cout << "Houurray!" << endl;
				cout<<"Agent from position" << x << ", " << y << " has collected the self-defense weapon : ";
				protection[i]->afisare();
				cout << "!";
				cout << "He has now:" << agent[i]->getSFWeapons() << " self-defense weapons." << endl;
				agent[i]->chargeDefWeapon(protection[i]);
				protection.erase(i + protection.begin());
				setProtect();
				cout << "There are only " << getProtect() << " self-defense weapons left on the map!"<<endl;
			}
		}
	}
}
void Harta::configuration()
{
	for (int i=0;i<agent.size();i++)
	{
		changePosition(agent[i]->getX(), agent[i]->getY(),i);
	}
}

void Harta::setWeapons()
{
	for (nrWeapons = 0; nrWeapons < weapons.size(); nrWeapons++);
}
void Harta::setProtect()
{
	for (nrProtect = 0; nrProtect < protection.size(); nrProtect++);
}
void Harta::setAgents()
{
	for (nrAgents = 0; nrAgents < agent.size(); nrAgents++);
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
ostream& operator<<(ostream& out, const Harta& h) {
	for (int i = 0; i < h.getSize(); i++) {
		for (int j = 0; j < h.getSize(); j++)
			out << h.harta[i][j] << " ";
		out << '\n';
	}
	out << '\n';
	return out;
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

Harta::~Harta()
{
	for (int i = 0; i < limitX; i++)
		delete harta[i];
	delete harta;
	if (getAgents() > 0)
	{
		for (int i = 0; i < agent.size(); i++)
			agent.erase(i + agent.begin());
	}
	if (getWeapons() > 0)
	{
		for (int i = 0; i < weapons.size(); i++)
			weapons.erase(i + weapons.begin());
	}
	if (getProtect() > 0)
	{
		for (int i = 0; i < protection.size(); i++)
			protection.erase(i + protection.begin());
	}
	nrAgents = 0;
	nrWeapons = 0;
	nrProtect = 0;
	limitX = limitY = 0;
}
bool Harta::isFree(int x, int y,int i)
{
	int n = getSize();
	int arie = agent[i]->getView();
	int limit1 = x + arie;
	if (limit1 >= n)limit1 = n - 1;				//we check if our viewport doesn't cross the map
	int limit2 = y + arie;
	if (limit2 >= n)limit2 = n - 1;
	for (int i = x; i <= limit1; i++)
		for (int j = y; j <= limit2; j++)
			if (getValue(i, j) == 'A' && (i != x || j != y))return 1;	//if there is any Agent,then our current object cannot move
	limit1 = x - arie;
	limit2 = y - arie;
	if (limit1 < 0)limit1 = 0;
	if (limit2 < 0)limit2 = 0;
	for (int i = limit1; i >= 0; i--)
		for (int j = limit2; j >= 0; j--)
			if (getValue(i, j) == 'A' && (i != x || j != y))return 1;

	return 0;
}

void Harta::changePosition(int nr1,int nr2,int i)
{
	
	int n = getSize();
	int arie = agent[i]->getView();
	if (arie == 0 && isFree(nr1, nr2, i) == 1)
	{
		cout << "Oh,no!The agent from position:" << nr1 << "," << nr2 << " cannot move!" << endl;
		cout << "It seems like our agent wasn't in good shape today...He can't see around him." << endl;
		cout << "And he is in danger!Other agents are around him!" << endl;
		cout << "Unfortunately,he will die :(" << endl;
		cout << "There are only " << getAgents() - 1 << " agents left!";
		deleteAgent(nr1, nr2);
		setAgents();
	}
	else if (isFree(nr1, nr2, i) == 0)			//we search if there is another Agent
	{
		int value1 = nr1 + arie;
		if (value1 >= n)value1 = n - 1;
		int value2 = nr2 + arie;
		if (value2 >= n)value2 = n - 1;
		int value3 = nr1 - arie;
		if (value3 < 0)value3 = 0;
		int value4 = nr2 - arie;
		if (value4 < 0)value4 = 0;
		srand((unsigned)time(0));
		int select1 = (rand() % value1) + value3; //generates a random number from value3 to value1->the X coordonate
		int select2 = (rand() % value2) + value4;
		int option = (rand() % 2) + 1;
		if (option == 1)
			if (select1 == nr1)
			{
				select1 = (rand() % value1) + value3;
				select2 = nr2;
			}
			else select2 = nr2;
		else if (option == 2)
		{
			if (select2 == nr2)select2 = (rand() % value2) + value4;
			select1 = nr1;
		}
		if (getValue(select1, select2) == '*')			//if no one is there,the Agent moves
		{
			setValue(nr1, nr2, '*');
			setValue(select1, select2, 'A');
			cout << "Agent from position" << nr1 << "," << nr2 << " has moved to position" << select1 << "," << select2;
			agent[i]->setX(select1);
			agent[i]->setY(select2);
			if (select1 > nr1)
			{
				arie += (select1 - nr1);
				agent[i]->setArie(arie);
			}
			else if (select1 < nr1)
			{
				arie -= (nr1 - select1);
				agent[i]->setArie(arie);
			}
			else if (select2 > nr2)
			{
				arie += (select2 - nr2);
				agent[i]->setArie(arie);
			}
			else if (select2 < nr2)
			{
				arie -= (nr2 - select2);		//we change the value depending on our agent move;if he moves back it's viewport decreases,otherwise it increases;
				agent[i]->setArie(arie);
			}
			if (arie < 0)
			{
				arie = 0;
				agent[i]->setArie(arie);
			}
			if (arie >= n)
			{
				arie = n - 1;
				agent[i]->setArie(arie);
			}
		}
		else if (getValue(select1, select2) != '*')	//if there is a weapon or a self-defense weapon we add it to the Agent's tools
		{
			collectWeapon(i, select1, select2);
		}

	}
	else {
		int n = getSize();
		int ok = 1;
		int arie = agent[i]->getView();
		int limit1 = agent[i]->getX() + arie;
		if (limit1 >= n)limit1 = n - 1;
		int limit2 = agent[i]->getY() + arie;
		if (limit2 >= n)limit2 = n - 1;
		int l = agent[i]->getX();
		for (l ; l <= limit1; l++)
			for (int j = agent[i]->getY(); j <= limit2; j++)
				if (getValue(l, j) == 'A' && (l != agent[i]->getX() || j != agent[i]->getY()))
				{
					agent[i]->attack();
					harta[l][j] = '*';
					deleteAgent(l , j);
					ok = 0;
				}
		if (ok == 0)
		{

			limit1 = agent[i]->getX() - arie;
			limit2 = agent[i]->getY() - arie;
			if (limit1 < 0)limit1 = 0;
			if (limit2 < 0)limit2 = 0;
			for (int l = limit1; l >= 0; l--)
				for (int j = limit2; j >= 0; j--)
					if (getValue(l, j) == 'A' && (l != agent[i]->getX() || j != agent[i]->getY()))
					{
						agent[i]->attack();
						harta[l][j] = '*';
						deleteAgent(l, j);
					}
		}
	}
}
