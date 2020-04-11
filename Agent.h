#ifndef _AGENT_H_
#define _AGENT_H_
#include<vector>
#include<iostream>
using namespace std;
class Agent:public Harta
{
	const int arie=2;        //un agent poate vedea cu pana la 2 pozitii spre N,S,E,V
	int pozitieOx;
	int pozitieOy;
	vector<Arma> weapon;
	vector<Armuri> protect;  
public:
	Agent(int x=0,int y=0);
	~Agent();
	bool isFree();
	Agent& operator+(const Agent);
	Agent changePosition(Agent&);
	void afisare();
};

#endif