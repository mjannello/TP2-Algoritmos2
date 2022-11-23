
#ifndef CELL_BEHAVIOUR_H_
#define CELL_BEHAVIOUR_H_
#include "CellGenes.h"

class CellBehaviour {
public:
    virtual void apply(CellGenes* fatherGenes, CellGenes* childGenes);
};


class RadiactiveBehaviour : public CellBehaviour {
public:
    void apply(CellGenes* fatherGenes, CellGenes* childGenes);
};

class AryanBehaviour : public CellBehaviour {
public:
    void apply(CellGenes* fatherGenes, CellGenes* childGenes);
};


class ZombieBehaviour : public CellBehaviour {
public:
    void apply(CellGenes* fatherGenes, CellGenes* childGenes);
};

class ScaloCellBehaviour : public CellBehaviour {
public:
    void apply(CellGenes* fatherGenes, CellGenes* childGenes);
};

class PortalBehaviour : public CellBehaviour {
public:
    void apply(CellGenes* fatherGenes, CellGenes* childGenes);
};

class NormalBehaviour : public CellBehaviour {
public:
    void apply(CellGenes* fatherGenes, CellGenes* childGenes);
};


#endif /* CELL_BEHAVIOUR_H_ */