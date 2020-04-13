#ifndef _HARTA_H_
#define _HARTA_H_
#include "Agent.h"
#include<vector>
#include <iostream>

using namespace std;

class Harta
{
private:
	char** harta;
	int nrAgents;
	int nrWeapons;
	int nrProtect;
	int limitX;
	int limitY;
	vector<Agent*> agent;
	vector<Arma*> weapons;
	vector<Armuri*> protection;
public:
	Harta(int x=25,int y=25);		//in cazul in care nu ne este precizata o anumita dimensiune a hartii,aceasta va avea by default dimensiunea de 25x25
	//Harta(const Harta&);			//definim un copy constructor
	~Harta();
	void show(); //metoda pentru afisarea hartii dupa fiecare runda;
	void deleteAgent(int,int);
	void collectWeapon(Agent& a,int, int);
	int getSize() const;
	int getWeapons() const;
	int getProtect() const;
	int getAgents() const;
	char getValue(int,int) const;
	void setWeapons();
	void setProtect();
	void setAgents();
	void configuration();
	void setValue(int,int,char);
	//friend ostream& operator<<(ostream&,const Harta&);

};
#endif