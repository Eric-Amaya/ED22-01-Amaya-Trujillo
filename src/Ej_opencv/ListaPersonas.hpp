#ifndef EJ_OPENCV_LISTAPERSONAS_H
#define EJ_OPENCV_LISTAPERSONAS_H
#include "Nodo.hpp"

class ListaPersonas 
{
    private:
    Nodo* first;
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
