//
// Created by anaso on 12/09/2023.
//

#ifndef BORRADOR_P1_LISTA_DL_H
#define BORRADOR_P1_LISTA_DL_H
#include "Nodo.h"


class Lista_DL
{
private:
    Nodo* head;
public:

    //Constructor
    Lista_DL();

    //Get y set
    Nodo* gethead();
    void sethead(Nodo* head);

    //Recorrer
    void recorrer();

    //Mostrar
    void mostrar();

    //crear
    void crear();

};


#endif //BORRADOR_P1_LISTA_DL_H
