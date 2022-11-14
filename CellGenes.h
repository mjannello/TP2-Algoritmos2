#ifndef CELL_GENES_H_
#define CELL_GENES_H_
class CellGenes {
private:
	static const int GENES_QUANTITY = 3;
	int genes[GENES_QUANTITY];
public:
	CellGenes();
	CellGenes(int genes[]);
	void setGenes(int gen[]);
	int * getGenes();
	int getGenesCount();
};
#endif