#include "Agent.h"
#include "Arma.h"
#include "Armuri.h"
#include "Knives.h"
#include "Cap.h"
#include<vector>
#include<iostream>
#include <cstdlib>
#include<ctime>
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
Agent& Agent::changePosition(Harta& h)
{
	int nr1 = this->getX();		//we get the position where our Agent is
	int nr2 = this->getY();
	int n = h.getSize();
	if (arie == 0 && isFree(nr1, nr2, h) == 1)
	{
		cout << "Oh,no!The agent from position:" << nr1 << "," << nr2 << " cannot move!" << endl;
		cout << "It seems like our agent wasn't in good shape today...He can't see around him." << endl;
		cout << "And he is in danger!Other agents are around him!" << endl;
		cout << "Unfortunately,he will die :(" << endl;
		cout << "There are only " << h.getAgents() - 1 << " agents left!";
		h.deleteAgent(nr1,nr2);
	}
	if (isFree(nr1, nr2, h) == 0)			//we search if there is another Agent
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
		if (h.getValue(select1,select2) =='*')			//if no one is there,the Agent moves
			{
				h.setValue(nr1, nr2, '*');
				h.setValue(select1, select2, 'Agnt');
				cout << "Agent from position" << nr1 << "," << nr2 << " has moved to position" << select1 << "," << select2;
				this->pozitieOx = select1;
				this->pozitieOy = select2;
				if (select1 > nr1)arie += (select1 - nr1);
				else if (select1 < nr1)arie -= (nr1 - select1);
				else if (select2 > nr2)arie += (select2 - nr2);
				else if (select2 < nr2)arie - +(nr2 - select2);		//we change the value depending on our agent move;if he moves back it's viewport decreases,otherwise it increases;
				if (arie < 0)arie = 0;
				if (arie >= n)arie = n - 1;
			}
		else if (h.getValue(select1, select2) != '*')	//if there is a weapon or a self-defense weapon we add it to the Agent's tools
		{

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