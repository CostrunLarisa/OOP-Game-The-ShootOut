#ifndef _AGENT_H_
#define _AGENT_H_
#include<vector>
#include "Harta.h"
#include"Arma.h"
#include "Armuri.h"
#include<iostream>
using namespace std;
class Agent:public Harta
{
	static int arie;        //an agent can see with maximum 2 positions ahead N,S,E,V
	int pozitieOx;
	int pozitieOy;
	vector<Arma> weapon;	//we use a vector,due to the fact that each Agent can collect weapons and self-defense weapons during the game
	vector<Armuri> protect;  
public:
	Agent(int x=0,int y=0);
	~Agent();
	int getView();                  //returns the viewport
	bool isFree(int,int,Harta);						//boolean method which tells us wether or not we have another Agent with the given position:x,y nearby
	Agent& changePosition(Harta);		//method for changing the position
	void afisare();
	int getX() const;
	int getY() const;
};

#endif