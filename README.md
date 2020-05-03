# OOP-Game-The-ShootOut(C++ language and OOP concepts,written in Visual Studio 2019)

This is an individual University project at Faculty of Mathematics and Informatics,Bucharest.
The project contains a programme, made with **Object Oriented Programming concepts**, which simulates a game called **"The ShootOut".** The only interaction user-game is when the user is asked: ***"Do you want to continue the game?"*** if the answer is True,then the message ***"How many rounds do you want the game to run?"*** is displayed and the user introduces the number of rounds he wants the game to simulate,otherwise the game is stopped.
The strategy of the game is pretty simple. At the very beginning is created a map of [25,25] populated randomly with the characters:
* **For players:**
* "A" agent;
* **For weapons:**
* "K" knife;
* "H" hammer;
* "G" gun;
* **For weapons that protect the agents:**
* "C" cap;
* "T" stone gloves;
* "S" scut;\
\
Each agent has as **"starter pack weapons"** a knife and a cap; he can use them when he attacks,this happens if he has other agents nearby(area of visibility=3 positions further in N,S,E,V),otherwise he can move randomly with 1 position smaller than his area of visibility in N,S,E,V.\
Each agent can collect the weapons found on the map.\
Each round is finished when all the agents make a move.One move involves an attack or a change of position; one agent cannot attack and change his position at the same type.If there are no enemies near him,then he moves.If when he moves finds a weapon, then he collects it.\
**The game is finished when:**
1. **The user chooses.**
1. **Is only one agent left on the map, hence the winner of the game.**\
\
During the game, if the agent has more weapons, then he can choose wich one he wants to use; the most powerful combinations being: hammer and scut, hammer and cap, hammer and StoneGloves then any weapon that he owns (if he doesn't have a hammer) and scut,then the weapon and cap and in the end, the weapon and StoneGloves, if it happens to doesn't have weapons that protect him,then he simply shoots.\
Each combination of weapons has its own method of shooting.\
If one agent changes his position and on his road finds weapons,then it will be displayed when he found that weapon, for example:\
**" Agent from position (0,3) found the weapon:hammer when we moved to position (0,4).**
**Agent from position (0,3) found theweapon:knife when he moved to position (0,5).**
**Agent from position (0,3) has moved to position (0,5)."**\
What you can see is the fact the the game shows the steps followed by the agent,then,at the end he shows:
**"initial position->final position."**\
If one agent attacks then he gives a battle with the one he attacked.Each of them chooses the best combination that he has. If they have only he starter pack weapons
or the same combinations of weapons it is obvious that it will win the one who initiated the battle. If the one who attacked first dies
the other agent can make a move when his turn comes, because the current battle was because he had to protect himself.\
The winner of the battle becomes The Killer and he has the power to steal the weapons of the agent.He steals only if the
agent had more weapons,not just only those from the starter-pack(cap and knife).
