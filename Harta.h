#ifndef _HARTA_H_
#define _HARTA_H_
#include<vector>
#include "Agent.h"
#include "Arma.h"
#include "Armuri.h"
#include <iostream>
using namespace std;
class Harta
{
	static int runda;
	int limitX;
	int limitY;
	vector<Agent> agent;
	vector<Arma*> weapons;
	vector<Armuri*> protection;
public:
	Harta(int x=25,int y=25);		//in cazul in care nu ne este precizata o anumita dimensiune a hartii,aceasta va avea by default dimensiunea de 25x25
	Harta(const Harta&);			//definim un copy constructor
	~Harta();
	Harta operator=(const Harta);  //avem nevoie de supraincarcarea operatorului pentru a face o copie hartii,astfel putem afisa ce schimbari au avut loc dupa o runda
	void show(vector<Agent>, Harta); //metoda pentru afisarea hartii dupa fiecare runda;
	bool isFinal();					//metoda in care stabilim daca fiecare agent a facut o mutare
	bool endGame();
	void deleteItem(Harta&);
};
#endif