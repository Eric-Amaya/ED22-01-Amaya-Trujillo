#ifndef EJ_OPENCV_NODO_H
#define EJ_OPENCV_NODO_H   
#include "Persona.hpp" 

class Nodo 
{
    private:
    Nodo* next;
    Persona* persona;

    public:
    Nodo();
    Nodo(Persona* persona);
    void setNext(Nodo* next);
    Nodo* getNext();
    Persona* getDato();
    ~Nodo();
};



#endif /// EJ_OPENCV_NODO_H