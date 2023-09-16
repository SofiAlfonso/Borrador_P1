//
// Created by anaso on 12/09/2023.
//

#include "Lista_DL.h"
#include "Nodo.h"
#include <iostream>
#include <time.h>

using namespace std;

//Constructor
Lista_DL::Lista_DL()
{
    this-> head= NULL;
}

//Get
Nodo* Lista_DL:: gethead()
{
    return this-> head;
}
void Lista_DL::sethead(Nodo* head)
{
    this->head= head;
}

//Recorrer
void Lista_DL:: recorrer()
{
   if(this->head)
   {
       Nodo*actual= this->head;
       Nodo* EventoA= NULL;
       Nodo* EventoB=NULL;
       Nodo* EventoC=NULL;
       while(actual->getpfuturo())
       {
           bool TipoA= actual-> ETA(actual);
           if(TipoA)
           {
               cout<<"se encontro un evento Tipo A"<< actual->getnum()<<endl;
               EventoA= actual;
               actual= actual->getpfuturo();
               while(actual->getpfuturo())
               {
                   if(EventoC!=NULL)
                   {
                       EventoA=NULL;
                       EventoB=NULL;
                       EventoC=NULL;
                       break;
                   }
                   bool TipoB= actual->ETB(actual);
                   if (TipoB)
                   {
                       EventoB= actual;
                       cout<<"se encontro un evento Tipo B"<< actual->getnum()<<endl;
                       actual= actual->getpfuturo();
                       while(actual->getpfuturo())
                       {
                           bool TipoC= actual->ETC(actual,EventoA);
                           if(TipoC)
                           {
                               EventoC= actual;
                               cout<<"Se encontro un evento Tipo C"<< actual->getnum()<<endl;
                               cout<<"Ha ocurrido una singularidad"<<endl;
                               break;
                           }
                           else
                           {
                               actual= actual->getpfuturo();
                           }

                       }
                   }
                   else
                   {
                       actual= actual->getpfuturo();
                   }
               }
           }
           else
           {
               actual= actual->getpfuturo();
           }
       }
       cout<<"El recorrido ha acabado"<<endl;
   }
   else
   {
       cout<<"Lo siento, la lista de eventos está vacía"<<endl;
   }


}

//Mostrar
void Lista_DL:: mostrar()
{
    if (head)
    {
        Nodo* actual = head;
        do
        {
            cout<< "["<<actual->getcientifico()<< "|"<<actual->getnum()<< "]->";
            actual= actual->getpfuturo();

        }while(actual);
        cout<<"END"<<endl;
    }
    else
    {
        cout<<"No hay elementos en la lista"<<endl;
    }
}

//crear lista aleatoriamente
void Lista_DL:: crear()
{
    srand(time(NULL));
    char cien= NULL;

    for (int i=1; i<23;i++ )
    {
        Nodo* nuevo= new Nodo();
        int n= 1+ rand()%(101-1);
        int eleccion= 1+ rand()%(2);
        if (eleccion==1)
        {
            cien= 'E';
        }
        else
        {
            cien= 'R';
        }

        nuevo->setcientifico(cien);
        nuevo->setnum(n);
        nuevo->setpfuturo(this->head);
        nuevo->setppasado(NULL);

        this->head= nuevo;
        if(head->getpfuturo())
        {
            Nodo* ant= head->getpfuturo();
            ant->setppasado(head);
        }
    }
}