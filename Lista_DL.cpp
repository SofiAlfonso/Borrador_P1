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

//Recorreremos la lista para encontrar los eventos y las singularidades
void Lista_DL:: recorrer()
{
    //Comprobamos que la lista no este vacía
   if(this->head)
   {
       //Establecemos los nodos a usar
       Nodo*actual= this->head;
       Nodo* EventoA= NULL;
       Nodo* EventoB=NULL;
       Nodo* EventoC=NULL;
       int contadorA=0;
       int contadorB=0;
       int contadorC= 0;
       int contador= 0;

       // Recorremos la lista hasta el final
       while(actual)
       {
           //Buscamos un evento tipo A
           bool TipoA= actual-> ETA(actual);
           if(TipoA)
           {
               contadorA ++;
               cout<<"se encontro un evento Tipo A: "<< actual->getnum()<<endl;
               cout<<"["<<actual->getcientifico()<< "|"<<actual->getnum()<< "]->"<<endl;
               cout<<"__________________________________________________________"<< endl;
               EventoA= actual;
               actual= actual->getpfuturo();
               contador ++;

               //Recorremos la lista desde el evento A encontrado hasta hallar uno B
               while(actual)
               {
                   //Comprobamos que ya no haya encontrado un evento tipo C (Para saber si debo volver a buscar uno tipo A)
                   if(EventoC!=NULL)
                   {
                       //Seteamos los eventos a Null, pues ahora voy a buscar si hay otra singularidad en la lista, desde el evento C donde terminé
                       EventoA=NULL;
                       EventoB=NULL;
                       EventoC=NULL;
                       break;
                   }
                   bool TipoB= actual->ETB(actual);
                   if (TipoB)
                   {
                       contadorB ++;
                       EventoB= actual;
                       cout<<"se encontro un evento Tipo B: "<< actual->getnum()<<endl;
                       cout<<"["<<EventoA->getcientifico()<< "|"<<EventoA->getnum()<< "]->";
                       cout<<"["<<actual->getcientifico()<< "|"<<actual->getnum()<< "]->"<<endl;
                       cout<<"__________________________________________________________"<< endl;
                       actual= actual->getpfuturo();
                       contador ++;

                       //Buscamos un evento tipo C
                       while(actual)
                       {
                           bool TipoC= actual->ETC(actual,EventoA);
                           if(TipoC)
                           {
                               contadorC++;
                               EventoC= actual;
                               bool primo= actual->primo(actual->getnum());
                               cout<<"Se encontro un evento Tipo C: "<< actual->getnum()<<endl;
                               cout<<"Ha ocurrido una singularidad"<<endl;
                               if(primo)
                               {
                                   cout<<"El cientifico "<< "["<<EventoB->getcientifico()<< "|"<<EventoB->getnum()<< "] " << "pudo entregarle informacion al cientifico "<<"["<<EventoA->getcientifico()<< "|"<<EventoA->getnum()<< "]"<< endl;
                               }
                               else
                               {
                                   cout<<"El cientifico "<< "["<<EventoB->getcientifico()<< "|"<<EventoB->getnum()<< "] " << "Solo pudo observar al cientifico "<<"["<<EventoA->getcientifico()<< "|"<<EventoA->getnum()<< "]"<< endl;
                               }
                               cout<<"["<<EventoA->getcientifico()<< "|"<<EventoA->getnum()<< "]->";
                               cout<<"["<<EventoB->getcientifico()<< "|"<<EventoB->getnum()<< "]->";
                               cout<<"["<<actual->getcientifico()<< "|"<<actual->getnum()<< "]"<<endl;
                               cout<<"__________________________________________________________"<< endl;
                               //Salimos del ciclo al encontrarlo, para volver a buscar uno tipo A en lo que queda de la lista
                               break;
                           }
                           //Todos los else me ayudan a ir al siguiente nodo cuando el actual no cumple con ser un evento del que estoy buscando
                           else
                           {
                               actual= actual->getpfuturo();
                               contador ++;
                           }

                       }
                   }
                   else
                   {
                       actual= actual->getpfuturo();
                       contador ++;
                   }
               }
           }
           else
           {
               actual= actual->getpfuturo();
               contador ++;
           }
       }
       cout<<"El recorrido ha acabado. Con un total de "<< contador<<" Nodos"<<endl;
       cout<<"Se encontraron: "<<"\n"<< "-"<< contadorA<< " Eventos A."<<"\n"<< "-"<< contadorB<< " Eventos B."<<"\n"<< "-"<< contadorC<< " Eventos C."<<endl;
   }
   else
   {
       cout<<"Lo siento, la lista de eventos está vacía"<<endl;
   }


}

//Mostrar
void Lista_DL:: mostrar()
{
    int contador=0;
    if (head)
    {
        contador=1;
        Nodo* actual = head;
        do
        {
            cout<< "["<<actual->getcientifico()<< "|"<<actual->getnum()<< "]->";
            if (contador%10==0)
            {
                cout <<' '<<endl;
            }
            actual= actual->getpfuturo();
            contador++;

        }while(actual->getpfuturo());
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