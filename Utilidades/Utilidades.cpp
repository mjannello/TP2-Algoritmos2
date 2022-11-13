#include "Utilidades.h"



void Utilidades::dibujarCelula(Box* box, Celula* celula, BMP* bmp) {

    int* genes;
    RGBApixel NewColor;
    genes = celula->getGenes();

    int x = box->getCoordX();
    int y = box->getCoordY();
    int z = box->getCoordZ();

    NewColor.Red = genes[0];
    NewColor.Green = genes[1];
    NewColor.Blue = genes[2];

    for (int i = x; i < x+30; i++) {
        for (int j = y; j < y+30; j++) {
            bmp->SetPixel(x + i, y + j, NewColor);
        }
    }
	
 }