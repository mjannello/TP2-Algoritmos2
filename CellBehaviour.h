
#ifndef CELL_BEHAVIOUR_H_
#define CELL_BEHAVIOUR_H_
#include "CellGenes.h"

class CellBehaviour {
public:
    int debugBehaviourInt = 0;

    virtual void apply(CellGenes* fatherGenes, CellGenes* childGenes);
};


class RadiactiveBehaviour : public CellBehaviour {
public:
    int debugBehaviourInt = 1;
    void apply(CellGenes* fatherGenes, CellGenes* childGenes);
};

class AryanBehaviour : public CellBehaviour {
public:
    void apply(CellGenes* fatherGenes, CellGenes* childGenes);
};
/*
class ScaloCellBehaviour : public CellBehaviour {
public:
    void apply(int fatherGenes[], int childGenes[]);
};

class ZombieBehaviour : public CellBehaviour {
public:
    void apply(int fatherGenes[], int childGenes[]);
};

class PortalBehaviour : public CellBehaviour {
public:
    void apply(int fatherGenes[], int childGenes[]);
};
*/
class NormalBehaviour : public CellBehaviour {
public:
    void apply();
};


#endif /* CELL_BEHAVIOUR_H_ */