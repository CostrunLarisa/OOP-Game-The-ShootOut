#ifndef _GAME_H_
#define _GAME_H_
class Game
{
private:
	static int Rounds;			//the number of rounds inserted by the user
	static int currentRound;	//the TOTAL current rounds
public:
	void StartGame();
	~Game();
};
#endif

