#ifndef ARMURI_H
#define ARMURI_H
class Armuri
{
	int poz1;
	int poz2;
public:
	Armuri(int x=0, int y=0);
	virtual void afisare() = 0;
	int getX() const;
	int getY() const;
	friend class Harta;
	friend class Agent;
};
#endif

