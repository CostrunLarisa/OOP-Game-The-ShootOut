#include "Game.h"
#include "Harta.h"
#include<iostream>
#include<string>
using namespace std;
int Game::currentRound = 0;
int Game::Rounds = 0;

void Game::StartGame()
{
	Harta h(25, 25);
	cout << "Insert the number of rounds you want the game to run:";
	int nr;
	cin >> nr;
	Rounds = nr;
	while (h.getAgents() > 0)
	{
		while (currentRound < Rounds && h.getAgents()>1)
		{
			currentRound++;
			cout << "---ROUND" << " " << currentRound << "---";
			h.configuration();
			h.show();
			h.changes();
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
				currentRound = 0;
				break;
			}
			case 0:
			{
				cout << "Oh,noo! You've stopped the game! :(";
				break;
			}
			break;
			}
		}
		else if (h.getAgents() == 1)
		{
			cout << "End Game!"<<endl;
			h.show();
			h.changes();
			break;
		}
	}
}