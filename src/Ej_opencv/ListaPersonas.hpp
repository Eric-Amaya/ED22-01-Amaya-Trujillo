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
    void ingresarPersona(Persona* n);
    int getCantidad();
    Nodo* buscarNodo(int num);
    void datos();

    ~ListaPersonas();
    
};

#endif /// EJ_OPENCV_LISTAPERSONAS_H
