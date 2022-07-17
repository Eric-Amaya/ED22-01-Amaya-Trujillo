#ifndef EJ_OPENCV_LISTAARBOL_H
#define EJ_OPENCV_LISTAARBOL_H

#include "NodoA.hpp"

class ListaArbol 
{
    private:
    NodoA* raiz;
    int cant;

    public:
    ListaArbol(); 
    void ingresar(NodoA * nood);
    int getCant();
    void sumarCant();
    NodoA* getRaiz();
    ~ListaArbol();
};

#endif ///EJ_OPENCV_LISTAARBOL_H