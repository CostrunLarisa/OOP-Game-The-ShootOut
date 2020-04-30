#include "Game.h"
#include "Harta.h"
#include "Agent.h"
#include "Arma.h"
#include "Armuri.h"
#include "Knives.h"
#include "Hammers.h"
#include "Guns.h"
#include "Scut.h"
#include "Cap.h"
#include "StoneGloves.h"
#include<iostream>

using namespace std;
int Game::currentRound = 0;
int Game::Rounds = 0;

void Game::StartGame()
{
	Harta h(7, 7);
	cout << "Insert the number of rounds you want the game to run:";
	int nr;
	cin >> nr;
	Rounds = nr; int ok = 1;
	cout << h << endl;
	int count = 0; 
	while (h.getAgents() > 0 && ok == 1)
	{
		while (count < Rounds && h.getAgents()>1)
		{
			currentRound++;
			count++;
			cout << "---ROUND" << " " << currentRound << "---" << endl;
			h.configuration();
			cout << h;
			cout << endl;
		}
		if (h.getAgents() == 1)
		{
			ok = 0;
			cout << "End Game!" << endl;
			cout << "The winner is Agent : ";
			h.show(); cout << endl;
			cout << h;
		}
		else {
			cout << "Continue?(Answer 1 means yes, answer 0 means no).";
			int answer;
			cin >> answer;
			if (answer == 1)
			{
				int nr;
				cout << "Insert the number of rounds you want the game to run:";
				cin >> nr;
				Rounds = nr;
				currentRound += nr;
				ok = 1;
				count = 0;
			}
			else
			{
				cout << "Oh,noo! You've stopped the game! :(" << endl;
				ok = 0;
			}

			if (h.getAgents() == 1)
			{
				ok = 0;
				cout << "End Game!" << endl;
				cout << "The winner is Agent : ";
				h.show(); cout << endl;
				cout << h; 
			}
		}
		
	}
}

Game::~Game()
{
	Rounds = 0;
	currentRound = 0;
	cout << "Game OVER!Exit.";
}
