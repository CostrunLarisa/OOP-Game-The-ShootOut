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
	
	Harta h(25, 25);
	cout << "Insert the number of rounds you want the game to run:";
	int nr;
	cin >> nr;
	Rounds = nr;int ok = 1;
	while (h.getAgents() > 0 && ok==1)
	{
		while (currentRound < Rounds && h.getAgents()>1)
		{
			currentRound++;
			
			cout << "---ROUND" << " " << currentRound << "---"<<endl;
			h.configuration();
			cout<<h;
			cout<<endl;
		}
		if (h.getAgents() > 1)
		{
			cout << "Continue?(Answer 1 means yes, answer 0 means no).";
			int answer;
			cin >> answer;
			switch (answer)
			{
				case 1:
				{
					int nr;
					cout << "Insert the number of rounds you want the game to run:";
					cin >> nr;
					Rounds = nr;
					currentRound += nr;
					break;
				}
				case 0:
				{
					cout << "Oh,noo! You've stopped the game! :("<<endl; 
					ok = 0;
					break;
				}
			break;
			}
			break;
		}
		else if (h.getAgents() == 1)
		{
			cout << "End Game!"<<endl;
			cout<<h;
			break;
		}
	}
}

Game::~Game()
{
	Rounds = 0;
	currentRound = 0;
	cout << "Game OVER!Exit.";
}
