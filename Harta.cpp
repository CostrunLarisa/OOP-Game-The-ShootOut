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

Harta::Harta(int x,int y):limitX(x),limitY(y)
{
	harta = new char* [limitX];
	for (int i = 0; i < limitX; i++)
		harta[i] = new char[limitX];
	for (int i = 0; i < limitX; i++)
		for (int j = 0; j < limitX; j++)
		{
			harta[i][j] = '*';
		}
	srand((unsigned)time(0));			//vrem sa generam un numar random diferit de fiecare data pentru pozitiile agentilor
	for (int i = 0; i < limitX-1; i++)		//vrem sa populam aproximativ un sfert de harta
	{
		int first = rand() % (limitX - 1);
		int second = rand() % (limitY - 1);	//incerc sa ma asigur ca pozitiile nu se repeta i.e nu vom avea doua obiecte pe aceeasi pozitie
		int third = rand() % (limitX - 1);
		int four = rand() % (limitY - 1);
		int five = rand() % (limitX - 1);
		int six = rand() % (limitY - 1);
		while (harta[first][second] != '*')
		{
			first = rand() % (limitX - 1);
			second = rand() % (limitY - 1);
		}
		Agent* a = new Agent(first, second);
		agent.push_back(a);
		harta[first][second] = 'A';
		int option = rand() % 3 + 1;
		while (harta[third][four]!='*')
		{
			third = rand() % (limitX - 1);
			four = rand() % (limitY - 1);
		}
		if (option == 1)
			{
				Guns* ar = new Guns(third, four);
				weapons.push_back(ar);
				harta[third][four] = 'G';
			}
		else if (option == 2)
			{
				Hammers* ar = new Hammers(third, four);
				weapons.push_back(ar);
				harta[third][four] = 'H';
			}
		else
			{
				Knives* ar = new Knives(third, four);
				weapons.push_back(ar);
				harta[third][four] = 'K';
			}

		while ( harta[five][six] != '*')
		{
			five = rand() % (limitX - 1);
			six = rand() % (limitY - 1);
		}
		int option2 = rand() % 3 + 1;
			if (option2 == 1)
			{
				Scut* arr = new Scut(five, six);
				harta[five][six] = 'S';
				protection.push_back(arr);
			}
			else if (option2 == 1)
			{
				Cap* arr = new Cap(five, six);
				harta[five][six] = 'C';
				protection.push_back(arr);
			}
		
		setAgents();
		setProtect();
		setWeapons();
	}
}


void Harta::deleteAgent(int x, int y)
{
	for (int i=0;i<agent.size();i++)
	{
		if (agent[i]->getX() == x && agent[i]->getY() == y)agent.erase(i + agent.begin());
	}
	setAgents();
}
void Harta::collectWeapon(int z,int x, int y,int nr1,int nr2)		//this method collects the weapon, erases it from the map and then set the weapon to the current agent
{
	int ok = 0;
	for (int i = 0; i < weapons.size();i++)
			if (weapons[i]->getX() == x && weapons[i]->getY() == y)
			{
				harta[x][y] = 'A';
				cout << "Agent from position (" << nr1 << "," << nr2 << ") has collected the weapon:";
				harta[nr1][nr2] = '*';
				weapons[i]->afis();
				cout << " when he moved to position ("<<x<<","<<y<<")!"<<endl;
				agent[z]->chargeWeapon(weapons[i]);
				cout << "He has now: " << agent[z]->getWeapons() << " weapons." << endl;
				weapons.erase(i + weapons.begin());
				ok = 1;
				setWeapons();
				cout << endl;
				cout << endl;
				cout << "There are only " << getWeapons() << "  weapons left to be found on the map!"<<endl;
				cout << "Who's gonna find them?" << endl;
				cout << "...Mistery..." << endl;
				break;
			}
		
	if(ok==0)
	{
				for (int i = 0; i < protection.size(); i++)
				{
					if (protection[i]->getX() == x && protection[i]->getY() == y)
					{
						harta[x][y] = 'A';
						harta[nr1][nr2] = '*';
						cout << "Houurray!" << endl;
						cout << "Agent from position (" << nr1 << "," << nr2 << ") has collected the self-defense weapon:";
						protection[i]->afisare();
						cout << " when he moved to position (" << x << "," << y << ")!" << endl;
						cout << endl;
						agent[z]->chargeDefWeapon(protection[i]);
						cout << "He has now:" << agent[z]->getSFWeapons() << " self-defense weapons." << endl;
						protection.erase(i + protection.begin());
						setProtect();
						cout << endl;
						cout << endl;
						cout << "There are only " << getProtect() << " self-defense weapons left on the map!"<<endl;
						break;
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
	nrWeapons = 0;
	for (int i = 0; i < weapons.size(); i++)
		nrWeapons++;
}
void Harta::setProtect()
{
	nrProtect = 0;
	for(int i = 0; i < protection.size(); i++)
			nrProtect++;
}
void Harta::setAgents()
{
	nrAgents = 0;
	for (int i = 0; i < agent.size(); i++)
		nrAgents++;
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
	cout << "from position: (" << agent[0]->getX() << "," << agent[0]->getY() << ").";
	agent[0]->show();
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
	for (int i = x+1; i <= limit1; i++)
			if (getValue(i, y) == 'A')return 1;	//if there is any Agent in N,S,E,V,then our current object cannot move
	for (int j = y+1; j <= limit2; j++)
		if (getValue(x, j) == 'A')return 1;
	limit1 = x - arie;
	limit2 = y - arie;
	if (limit1 < 0)limit1 = 0;
	if (limit2 < 0)limit2 = 0;
	for (int i = x-1; i >= limit1; i--)
			if (getValue(i, y) == 'A')return 1;
	for (int j = y-1; j >= limit2; j--)
		if (getValue(x, j) == 'A')return 1;

	return 0;
}

void Harta::changePosition(int nr1,int nr2,int i)
{

	int n = getSize();
	int arie = agent[i]->getView();
	if (isFree(nr1, nr2, i) == 1)			//we search if there is another Agent
	{
		int n = getSize();
		int ok = 1;
		int arie = agent[i]->getView();
		int limit1 = nr1 + arie;
		if (limit1 >= n)limit1 = n - 1;
		int limit2 = nr2 + arie;
		if (limit2 >= n)limit2 = n - 1;
		int l = nr1+1;
		int ok1 = 1;
		for (l; l <= limit1; l++)
				if (getValue(l, agent[i]->getY()) == 'A')
				{
					agent[i]->attack();
					harta[l][agent[i]->getY()] = '*';
					cout << "Hahaha,it seems like the agent from (" << l << "," << agent[i]->getY() << ") didn't pay attention to who was around him,so he DIED in the game!";
					cout << "Agent from position (" << agent[i]->getX() << "," << agent[i]->getY() << ") killed him!" << endl;
					cout << endl;
					cout << endl;
					deleteAgent(l, agent[i]->getY());
					setAgents();
					cout << "There are only: " << getAgents() << " agents left!" << endl;
					ok = 0;
					ok1 = 0;
					break;
				}
		if (ok1 == 1)
		{
			for (int j = nr2+1; j <= limit2; j++)
				if (getValue(agent[i]->getX(), j) == 'A' )
				{
					agent[i]->attack();
					harta[nr1][j] = '*';
					cout << "Hahaha,it seems like the agent from (" << nr1 << "," << j << ") didn't pay attention to who was around him,so he DIED in the game!";
					cout << "Agent from position (" << nr1 << "," << nr2<< ") killed him!" << endl;
					cout << endl;
					cout << endl;
					deleteAgent(nr1, j);
					setAgents();
					cout << "There are only: " << getAgents() << " agents left!" << endl;
					cout << endl;
					ok = 0;
					break;
				}
		}
		
		if (ok == 1)
		{

			limit1 = nr1 - arie;
			limit2 = nr2 - arie;
			if (limit1 < 0)limit1 = 0;
			if (limit2 < 0)limit2 = 0;
			int ok2 = 1;
		
			for (int l = nr1-1; l >= limit1; l--)
					if (getValue(l, nr2) == 'A' && l!= nr2)
					{
						agent[i]->attack();
						harta[l][nr2] = '*';
						cout << "Hahaha,it seems like the agent from (" << l << "," << nr2 << ") didn't pay attention to who was around him,so he DIED in the game!" << endl;
						cout << "Agent from position (" << agent[i]->getX() << "," << nr2 << ") killed him!" << endl;
						deleteAgent(l, nr2);
						cout << endl;
						cout << "There are only: " << getAgents() << " agents left!" << endl;
						cout << endl;
						ok2 = 0;
						break;
				
					}
			if (ok2 == 1)
			{
				for (int j = nr2-1; j >= limit2; j--)
					if (getValue(nr1, j) == 'A' && j!= nr2)
					{
						agent[i]->attack();
						harta[nr1][j] = '*';
						cout << "Hahaha,it seems like the agent from (" << nr1<< "," << j << ") didn't pay attention to who was around him,so he DIED in the game!" << endl;
						cout << "Agent from position (" << nr1<< "," << nr2 << ") killed him!" << endl;
						deleteAgent(nr1, j);
						setAgents();
						cout << endl;
						cout << endl;
						cout << "There are only: " << getAgents() << " left!" << endl;
						cout << endl;
						break;
					}
			}
		
		}
	}
	else {
		int value1 = nr1 + arie - 1;
		if (value1 >= n)value1 = n - 1;
		int value2 = nr2 + arie - 1;
		if (value2 >= n)value2 = n - 1;
		int value3 = nr1 - arie + 1;
		if (value3 < 0)value3 = 0;
		int value4 = nr2 - arie + 1;
		if (value4 < 0)value4 = 0;
		int select1, select2, ok = 1;
		int option = (rand() % 4) + 1;
		if (option == 1)
		{
			select1 = value1;
			select2 = nr2;
		}
		if (option == 2)
		{
			select1 = value3;
			select2 = nr2;
		}
		if (option == 3)
		{
			select2 = value2;
			select1 = nr1;
		}
		if (option == 4)
		{
			select2 = value4;
			select1 = nr1;
		}
		while (select1 == nr1 && select2 == nr2)
		{
			option = (rand() % 4) + 1;
			if (option == 1)
			{
				select1 = value1;
				select2 = nr2;
			}
			if (option == 2)
			{
				select1 = value3;
				select2 = nr2;
			}
			if (option == 3)
			{
				select2 = value2;
				select1 = nr1;
			}
			if (option == 4)
			{
				select2 = value4;
				select1 = nr1;
			}
		}
		if (harta[select1][select2] == '*')			//if no one is there,the Agent moves
		{
			harta[nr1][nr2]='*';
			harta[select1][select2]='A';
			cout << "Agent from position (" << nr1 << "," << nr2 << ") has moved to position (" << select1 << "," << select2 << ")." << endl;
			cout << endl;
			agent[i]->setX(select1);
			agent[i]->setY(select2);

		}
		else if (harta[select1][select2] != '*')	//if there is a weapon or a self-defense weapon we add it to the Agent's tools
		{
			collectWeapon(i, select1, select2,nr1,nr2);
			agent[i]->setX(select1);
			agent[i]->setY(select2);
		}

	}
		
}
