#ifndef Cell_h
#define Cell_h

#define STATE_DEAD 0
#define STATE_ALIVE 1

class Cell
{
private:
	int state = STATE_DEAD;

public:

	Cell();
	Cell(int);
	~Cell();
	void setState(int);
	int getState();
	Cell& operator= (const Cell&);
	Cell* getNextStatus(int neighborsAlive);
};

#endif 


