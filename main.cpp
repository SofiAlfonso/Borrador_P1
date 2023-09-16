
#include "Lista_DL.h"
#include "Nodo.h"
#include <iostream>

using namespace std;

int main() {

   Lista_DL l = Lista_DL();
    l.crear();
    Nodo* n= l.gethead();
    cout<<n->primo(n->getnum())<<endl;
    cout<< n->ETA(n)<<endl;
    l.mostrar();
    l.recorrer();
}
