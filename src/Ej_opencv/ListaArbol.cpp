#include "ListaArbol.hpp"
#include <iostream>
using namespace cv;
using namespace std;

ListaArbol:: ListaArbol() 
{
    this->raiz = NULL;
    this->cant = 0;
}
int ListaArbol::getCant() 
{
    return this->cant;
}

void ListaArbol:: sumarCant() 
{
    this->cant++;
}

NodoA* ListaArbol:: getRaiz() 
{
    return this->raiz;
}  


ListaArbol::~ListaArbol(){}