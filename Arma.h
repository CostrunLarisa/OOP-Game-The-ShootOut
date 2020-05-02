#ifndef ARMA_H
#define ARMA_H

class Arma						//abstract class for the weapons
{	int pozX;
	int pozY;
public:
	Arma(int x=0,int y=0);
	virtual void afis() = 0;	//method that displays a message when we collect a weapon
	virtual void shootW() = 0;	//method for shooting
	int getX() const;			//methods for getting the positions of the weapons	
	int getY() const;

};
#endif
