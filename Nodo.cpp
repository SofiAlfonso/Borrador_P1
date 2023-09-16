//
// Created by anaso on 12/09/2023.
//

#include "Nodo.h"


using namespace std;
//constructores
Nodo::Nodo()
{

}
Nodo::Nodo(int num, char cientifico, Nodo* ppasado, Nodo* pfuturo)
{
    this-> num= num;
    this->cientifico= cientifico;
    this-> ppasado= ppasado;
    this -> pfuturo= pfuturo;
}

//Getters
char Nodo:: getcientifico()
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
void Nodo:: setcientifico(char cientifico)
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


//  Verificacion de eventos
bool Nodo:: primo(int num)
{
    bool retorno= true;
    for(int i=2; i<num; i++)
    {
        if(num%i==0)
        {
            retorno= false;
            break;
        }
    }

    return retorno;
}

bool Nodo:: coprimo(int a, int b)
{
    bool retorno= true;
    int mayor=0;
    if (a>=b)
    {
        mayor=a;
    }
    else
    {
        mayor=b;
    }

    for (int i=2; i<=mayor;i++)
    {
        if(a%i==0 && b%i==0)
        {
            retorno= false;
            break;
        }
    }
    return retorno;
}

    //Evento tipo A
bool Nodo:: ETA(Nodo* actual)
{
    char c= actual->getcientifico();
    bool primo= actual->primo(actual->getnum());
    bool retorno=false;
    if (primo)
    {
        if (c=='E')
        {
           retorno= true;
        }

    }
    return retorno;
}

  //Evento tipo B
bool Nodo:: ETB(Nodo* actual)
{
    bool primo= actual->primo(actual->getnum());
    bool retorno=false;
    if (primo)
    {
       retorno= true;
    }

    return retorno;
}

 //Evento tipo C
bool Nodo:: ETC (Nodo* actual, Nodo*EventoA)
{
    bool retorno= false;
    int a= actual->getnum();
    int b= EventoA->getnum();
    bool primo= actual->primo(a);
    bool coprimo= actual->coprimo(a,b);
    if (primo)
    {
        retorno= true;
    }
    else if (coprimo)
    {
        retorno= true;
    }
    return retorno;
}