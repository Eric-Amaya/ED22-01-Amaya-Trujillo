#include "ListaPersonas.hpp"
#include <iostream>

ListaPersonas:: ListaPersonas()
{
    this->first = nullptr;
    this->cant = 0;
}
void ListaPersonas:: ingresarPersona(Persona* n) 
{
    Nodo* p = new Nodo(n);
    p->setID(this->cant);
    if(first== NULL)
    {
        this->first = p;;
        this->cant++;
    }
    else 
    {
        Nodo* aux = this->first;
        while(aux->getNext() != NULL)
        {
            aux = aux->getNext();
        }
        aux->setNext(p);
        this->cant++;
    }    
}

int ListaPersonas:: getCantidad() 
{

    return this->cant;
}

Nodo* ListaPersonas::buscarNodo(int num) 
{
    Nodo* aux = this->first;
    while(aux != nullptr)
    {
        if(aux->getID() == num) 
        {
            return aux;
        }
        aux = aux->getNext();
    }
    return nullptr;
}

void ListaPersonas:: datos() 
{
    Nodo* aux = this->first;
    while(aux != nullptr)
    {
        std:: cout << "Nodo numero: " << aux->getPersona() << std::endl;
        aux = aux->getNext();
    }
}

ListaPersonas::~ListaPersonas() {}

