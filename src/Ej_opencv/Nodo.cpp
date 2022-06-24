#include "Nodo.hpp"
#include <iostream>

Nodo:: Nodo () 
{

}
Nodo:: Nodo(Persona* persona) 
{
    this->persona = persona;
}
void Nodo::setNext(Nodo* next) 
{
    this->next = next;
}
Nodo* Nodo::getNext() 
{
    return this->next;
}

Persona* Nodo::getDato() 
{
    return this->persona;
}

Nodo:: ~Nodo() 
{

}
