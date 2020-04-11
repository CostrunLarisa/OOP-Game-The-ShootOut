#include "Agent.h"
#include "Arma.h"
#include "Armuri.h"
#include "Knives.h"
#include "Cap.h"
#include<vector>
#include<iostream>
using namespace std;

int Agent::arie = 2;
Agent::Agent(int poz1, int poz2) :pozitieOx(poz1),pozitieOy(poz2)
{
	Arma* ar = new Knives(this->pozitieOx, this->pozitieOy);	//we want to start the game with each agent having the same tools															
	weapon.push_back(*ar);										//hence each object of Agent class will have a weapon-object of type Knives,and a self-defense weapon of type Cap
	Armuri* arr = new Cap(this->pozitieOx, this->pozitieOy);
	protect.push_back(*arr);
}

bool Agent::isFree(int x, int y, Harta h)
{
	int n = h.getSize();
	int limit1 = x + arie;
	if (limit1 >= n)limit1 = n - 1;				//we check if our viewport doesn't cross the map
	int limit2 = y + arie;
	if (limit2 >= n)limit2 = n - 1;
	for (int i = x; i <= limit1; i++)
		for (int j = y; j <= limit2; j++)
			if (h.getValue(i,j) == 'Agnt' && (i != x || j != y))return 1;	//if there is any Agent,then our current object cannot move
	int limit1 = x - arie;
	int limit2 = y - arie;
	if (limit1 < 0)limit1 = 0;		
	if (limit2 < 0)limit2 = 0;
	for(int i=limit1;i>=0;i--)
		for(int j=limit2;j>=0;j--)
			if (h.getValue(i,j) == 'Agnt' && (i != x || j != y))return 1;

	return 0;
}
Agent& Agent::changePosition(Harta h)
{
	int nr1 = this->getX();		//we get the position where our Agent is
	int nr2 = this->getY();
	if (isFree(nr1, nr2, h) == 0)			//we search if there is another Agent
	{		if (nr1+arie<n && nr2+arie<n && h.getValue(nr1+arie,nr2) =='*')			//if there is no one,the Agent moves
			{
				h.setValue(x, y, '*');
				h.setValue(nr1 + arie, nr2, 'Agnt');
				cout << "Agent from position" << nr1 << "," << nr2 << " has moved to position" << nr1 + arie << "," << nr2;
			}

	}
	else {																		//else he attacks
	}
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
void Agent::afisare()
{

}