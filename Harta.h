#ifndef _HARTA_H_
#define _HARTA_H_
#include "Agent.h"
#include <vector>
#include <iostream>

using namespace std;
class Agent;
class Arma;
class Armuri;
class Harta
{
private:
	char** harta;	
	int nrAgents;		//number of agents
	int nrWeapons;		//number of weapons
	int nrProtect;		//number of weapons that protect the agent
	int limitX;			//the dimensions of the map
	int limitY;
	vector<Agent*> agent;		//the agents from the map
	vector<Arma*> weapons;		//the weapons from the map
	vector<Armuri*> protection;	//the weapons that protect from the map
public:
	Harta(int x=25,int y=25);		//in case if it is not given a specified value for the dimension of the map,
									//the constructor builds by default one of [25,25]
	~Harta();
	bool isFree(int , int,int);			//method that tells if one agent has other agents in his  area of visibility
	void changePosition(int,int,int);	//method that changes the position of an agent
	void show();						//method that shows the position of the winner
	void deleteAgent(Agent* a,int,int);			//method for removing agents from the map
	void collectWeapon(int, int,int,int,int);	//method used for collecting items from the map
	int getSize() const;
	int getWeapons() const;				//method used for getting the number of the weapons left on the map
	int getProtect() const;				//method used for getting the number of the weapons that protect left on the map
	int getAgents() const;				//method used for getting the number of the agents left on the map
	char getValue(int,int) const;		//method that gives the value from the map at he given position
	void setWeapons();					//method that sets the number of weapons
	void setProtect();					//method that sets the number of weapons that protect
	void setAgents();					//method that sets the number of agents
	void configuration();				//method that ensures that each agent makes a move
	void setValue(int,int,char);
	friend ostream& operator<<(ostream&,const Harta& h);	//overloading the << operator

};
#endif