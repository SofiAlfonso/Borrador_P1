//
// Created by anaso on 12/09/2023.
//

#include "Nodo.h"
#include "Lista_DL.h"
#include <time.h>
#include<stdlib.h>
#include <string>

using namespace std;
//constructores
Nodo::Nodo()
{

}
Nodo::Nodo(int num, string cientifico, Nodo* ppasado, Nodo* pfuturo)
{
    this-> num= num;
    this->cientifico= cientifico;
    this-> ppasado= ppasado;
    this -> pfuturo= pfuturo;
}

//Getters
string Nodo:: getcientifico()
{
    return this-> cientifico;

}
int Nodo::getnum()
{
    return this-> num;
}
Nodo* Nodo:: getppasado()
{
    return this -> ppasado;
}
Nodo*  Nodo::getpfuturo()
{
    return this-> pfuturo;
}

//Setters
void Nodo:: setcientifico(string cientifico)
{
    this->cientifico= cientifico;

}
void Nodo::setnum(int num)
{
    this-> num= num;

}
void Nodo:: setppasado(Nodo* ppasado)
{
    this-> ppasado= ppasado;

}
void Nodo:: setpfuturo(Nodo* pfuturo)
{
    this -> pfuturo= pfuturo;
}

