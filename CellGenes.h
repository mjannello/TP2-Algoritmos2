#ifndef CELL_GENES_H_
#define CELL_GENES_H_
class CellGenes {
private:
	static const int GENES_QUANTITY = 3;
	int genes[GENES_QUANTITY];
public:
	CellGenes();
	CellGenes(int genes[]);
	void setGenesValues(int gen[]);
	int* getGenesValues();
	int getGenesCount();
};
#endif