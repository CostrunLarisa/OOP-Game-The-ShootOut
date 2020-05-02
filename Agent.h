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
	static int arie;				//an agent can see with maximum 2 positions ahead N,S,E,V
	int pozitieOx;
	int pozitieOy;
	vector<Arma*> weapon;			// each Agent has by default a knife and a cap; he can collect weapons and self-defense weapons during the game
	vector<Armuri*> protect;  
public:
	Agent(int x=0,int y=0);
	~Agent();
	int getView();                  //returns the area of visibility
	void chargeWeapon(Arma* a);		//method used if he collected a weapon 
	void chargeDefWeapon(Armuri* a);//method used if he collected a weapon that protects him
	void attack();
	void show();					//if one agent is the winner,this method displays the weapons he collected during the game
	void setX(int x);				//methods used to set the coordonates for a new position
	void setY(int y);
	int getWeapons();				//returns the number of weapons
	int getSFWeapons();				//return the number of the weapons that protects him
	int getX() const;				//methods which return the coordonates of one agent's position
	int getY() const;
};

#endif