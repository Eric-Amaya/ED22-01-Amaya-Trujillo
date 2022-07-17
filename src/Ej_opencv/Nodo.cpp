#include "Nodo.hpp"
#include <iostream>
using namespace cv;
using namespace std;

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

Persona* Nodo::getPersona() 
{
    return this->persona;
}

int Nodo:: getID() 
{
    return this->id;
}

void Nodo:: setID(int id) 
{
    this->id = id;
}
void Nodo::setTipo(String tipo) 
{
    this->tipo = tipo;
}
String Nodo::getTipo()
{
    return this->tipo;
}

Nodo:: ~Nodo() 
{

}
