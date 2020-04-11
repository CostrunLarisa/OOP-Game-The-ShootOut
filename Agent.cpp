#include "Agent.h"
#include<vector>
#include<iostream>
using namespace std;

Agent::Agent()
{
	this->pozitieOx = 0;			
	this->pozitieOy = 0;
}

Agent::Agent(int poz1, int poz2) :pozitieOx(poz1),pozitieOy(poz2),Agent(){}

void Agent::afisare()
{

}