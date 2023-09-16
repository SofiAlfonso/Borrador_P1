
#include "Lista_DL.h"
#include <iostream>
#include <stdlib.h>


using namespace std;

int main() {
    //Se crea la lista y se ejecutan sus funciones
   Lista_DL l = Lista_DL();
    l.crear();
    //El sleep me ayuda a esperar 20 ms entre una función y otra (Se agrego para evitar un error de superposición)
    _sleep(20);
    l.recorrer();
    _sleep(20);
    l.mostrar();
    cout<<" "<<endl;
}
