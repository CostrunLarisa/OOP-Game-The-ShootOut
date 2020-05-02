#include "Game.h"
#include "Harta.h"
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
	Rounds = nr; int ok = 1;
	cout << endl;
	cout << "The initial map is:" << endl;
	cout << h << endl;													//it is displayed the initial configuration of the map
	int count = 0; 
	while (h.getAgents() > 0 && ok == 1)
	{
		while (count < Rounds && h.getAgents()>1)
		{
			currentRound++;		
			count++;
			cout << "---ROUND" << " " << currentRound << "---" << endl;
			h.configuration();											//the round is being played
			cout << h;													//after each round we show the map
			cout << endl;
		}
		if (h.getAgents() == 1)											//if after the number of rounds is only one agent,then the game stops
		{
			ok = 0;
			cout << "End Game!" << endl;
			cout << "The winner is Agent : ";
			h.show(); cout << endl;										//it is shown the characteristics of the winner
			cout << h;
		}
		else {															//else we have the possibility to continue the game
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

		}
		
	}
}

Game::~Game()
{
	Rounds = 0;
	currentRound = 0;
	cout << "Game OVER!Exit.";
}
