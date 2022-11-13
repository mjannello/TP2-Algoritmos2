#ifndef UTILIDADES_H_
#define UTILIDADES_H_

#include "Box.h"
#include "Celula.h"
#include "EasyBMP.h"

class Utilidades {
public:
    void dibujarCelula(Box* box, Celula* celula, BMP* bmp);
};


#endif /* UTILIDADES_H_ */
