#include "Tablero.h"
#include <iostream>

using namespace std;

int main() {

    Tablero * tab = new Tablero(3,3,3);

    cout << tab->casillero(1,2,1) << endl;

    delete tab;

    return 0;
}