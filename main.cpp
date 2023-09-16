
#include "Lista_DL.h"
#include <iostream>
#include <stdlib.h>


using namespace std;

int main() {

   Lista_DL l = Lista_DL();
    l.crear();
    _sleep(20);
    l.recorrer();
    _sleep(20);
    l.mostrar();
    cout<<" "<<endl;
}
