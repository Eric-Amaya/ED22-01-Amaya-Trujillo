#ifndef EJ_OPENCV_LISTAPERSONAS_H
#define EJ_OPENCV_LISTAPERSONAS_H
#include "Nodo.h"

class ListaPersonas 
{
    private:
    Nodo* first;
    Nodo* last;
    int cant;

    public: 
    ListaPersonas();
    void ingresarPersona(Nodo* p);
    int cantidad();
    Nodo* buscarNodo(int num);
    void datos();

    ~ListaPersonas();
    
};

#endif /// EJ_OPENCV_LISTAPERSONAS_H
