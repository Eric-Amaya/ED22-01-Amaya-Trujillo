#include "includes/ListaPersonas.h"
#include <iostream>

ListaPersonas:: ListaPersonas()
{
    this->first = nullptr;
    this->cant = 0;
}
void ListaPersonas:: ingresarPersona(Nodo* p) 
{
    if(first== nullptr)
    {
        this->first = p;
        cant++;
    }
    else 
    {
        Nodo* aux = this->first;
        while(aux->getNext() != nullptr)
        {
            aux = aux->getNext();
        }
        aux->setNext(p);
        cant++;
    }    
}

int ListaPersonas:: cantidad() 
{

    return this->cant;
}

void ListaPersonas:: datos() 
{
    Nodo* aux = this->first;
    while(aux != nullptr)
    {
        std:: cout << "Nodo numero: " << aux->getDato() << std::endl;
        aux = aux->getNext();
    }
}

ListaPersonas::~ListaPersonas() {}

