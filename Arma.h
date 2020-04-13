#ifndef ARMA_H
#define ARMA_H

class Arma
{	int pozX;
	int pozY;
public:
	Arma(int x=0,int y=0);
	virtual void afis() = 0; 
	virtual void shootW() = 0;
	int getX() const;
	int getY() const;

};
#endif
