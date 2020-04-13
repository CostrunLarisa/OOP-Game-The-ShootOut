#ifndef AGENT_H
#define AGENT_H

#include "Arma.h"
#include "Armuri.h"
#include <vector>
#pragma once
using namespace std;
class Arma;
class Armuri;
class Agent
{
	static int arie;        //an agent can see with maximum 2 positions ahead N,S,E,V
	int pozitieOx;
	int pozitieOy;
	vector<Arma*> weapon;	//we use a vector,due to the fact that each Agent can collect weapons and self-defense weapons during the game
	vector<Armuri*> protect;  
public:
	Agent(int x=0,int y=0);
	//~Agent();
	int getView();                  //returns the viewport
	void chargeWeapon(Arma* a);
	void chargeDefWeapon(Armuri* a);
	void attack();
	void show();
	void setArie(int x);
	void setX(int x);
	void setY(int y);
	int getWeapons();
	int getSFWeapons();
	int getX() const;
	int getY() const;
};

#endif