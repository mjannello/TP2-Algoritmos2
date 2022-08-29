#ifndef Cell_h
#define Cell_h

class Cell
{
private:
	int state = 0;

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


