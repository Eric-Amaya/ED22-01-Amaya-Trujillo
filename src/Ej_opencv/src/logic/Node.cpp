#include "includes/Nodo.h"
#include <iostream>

Nodo:: Nodo () 
{

}
Nodo:: Nodo(int dato) 
{
    this->dato = dato;
}
void Nodo::setNext(Nodo* next) 
{
    this->next = next;
}
Nodo* Nodo::getNext() 
{
    return this->next;
}

int Nodo::getDato() 
{
    return this->dato;
}

Nodo:: ~Nodo() 
{

}
