#ifndef CELL_GENES_H_
#define CELL_GENES_H_
class CellGenes {
private:
	static const int GENES_QUANTITY = 3;
	int genes[GENES_QUANTITY];
public:
	CellGenes();
	~CellGenes();
	CellGenes(int genes[]);
	CellGenes(int red, int green, int blue);
	void setGenesValues(int gen[]);
	int* getGenesValues();
	int getGenesCount();
};
#endif