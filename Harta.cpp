#include "Harta.h"
#include "Agent.h"
#include "Arma.h"
#include "Armuri.h"
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
		
		int option = rand() % 3 + 1;
		if (option == 1)
		{
			Arma ar = new Guns(nr3, nr4);
			weapons.push_back(ar);
		}
		else if (option == 2)
		{
			Arma ar = new Hammers(nr3, nr4);
			weapons.push_back(ar);
		}
		else
		{
			Arma ar = new Knives(nr3, nr4);
			weapons.push_back(ar);
		}
		int option2 = rand() % 3 + 1;
		if (option2 == 1)
		{
			Armuri arr = new Scut(nr5, nr6);
			protection.push_back(arr);
		}
		else if(option2==1)
		{
			Armuri arr = new Cap(nr5, nr6);
			protection.push_back(arr);
		}
		else {
			Armuri arr = new StoneGloves(nr5, nr6);
			protection.push_back(arr);
		}
	}

}
void Harta::show()
{
	for (int i = 0; i < agent.size(); i++)
	{
		cout << "Agent" <<i+1<<":";
		agent[i].afisare();
	}
	for(int i=0;i<weapons.size();i++)
	for(int i=0;i<protection.size();i++)
}