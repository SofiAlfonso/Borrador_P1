//
// Created by anaso on 12/09/2023.
//

#ifndef BORRADOR_P1_NODO_H
#define BORRADOR_P1_NODO_H
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Nodo
{
private:

    string cientifico;
    int num;
    Nodo* ppasado;
    Nodo* pfuturo;

public:

    //constructores
    Nodo();
    Nodo(int num, string cientifico, Nodo* ppasado, Nodo* pfuturo);

    //Getters
    string getcientifico();
    int getnum();
    Nodo* getppasado();
    Nodo* getpfuturo();

    //Setters
    void setcientifico(string cientifico);
    void setnum(int num);
    void setppasado(Nodo* ppasado);
    void setpfuturo(Nodo* pfuturo);




};


#endif //BORRADOR_P1_NODO_H
