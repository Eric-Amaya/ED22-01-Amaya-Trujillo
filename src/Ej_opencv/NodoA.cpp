#include "NodoA.hpp"
#include "Persona.hpp"
using namespace cv;
using namespace std;

NodoA::NodoA(Persona *p) 
{
    this->p = p;
    this->izq = NULL;
    this->der = NULL;
    
}

NodoA* NodoA::getIzq() 
{
    return this->izq;
}

NodoA* NodoA::getDer() 
{
    return this->der;
}

Persona* NodoA::getPersona() 
{
    return this->p;
}

int NodoA:: getID() 
{
    return this->id;
}

void NodoA:: setID(int id) 
{
    this->id = id;
}
void NodoA::setTipo(String tipo) 
{
    this->tipo = tipo;
}
String NodoA::getTipo()
{
    return this->tipo;
}
NodoA::~NodoA(){}