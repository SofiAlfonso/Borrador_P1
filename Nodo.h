//
// Created by anaso on 12/09/2023.
//

#ifndef BORRADOR_P1_NODO_H
#define BORRADOR_P1_NODO_H
#include <iostream>
#include <stdlib.h>

using namespace std;

class Nodo
{
private:

    char cientifico;
    int num;
    Nodo* ppasado;
    Nodo* pfuturo;

public:

    //constructores
    Nodo();
    Nodo(int num, char cientifico, Nodo* ppasado, Nodo* pfuturo);

    //Getters
    char getcientifico();
    int getnum();
    Nodo* getppasado();
    Nodo* getpfuturo();

    //Setters
    void setcientifico(char cientifico);
    void setnum(int num);
    void setppasado(Nodo* ppasado);
    void setpfuturo(Nodo* pfuturo);

    // Verificación de eventos
    bool primo(int num);
    bool coprimo(int a, int b);
    bool ETA(Nodo* actual);
    bool ETB(Nodo*actual);
    bool ETC (Nodo* actual, Nodo*EventoA);



};


#endif //BORRADOR_P1_NODO_H
