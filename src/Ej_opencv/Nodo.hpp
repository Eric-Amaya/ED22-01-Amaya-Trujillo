#ifndef EJ_OPENCV_NODO_H
#define EJ_OPENCV_NODO_H   
#include "Persona.hpp" 

class Nodo 
{
    private:
    Nodo* next;
    Persona* persona;
    int id;

    public:
    Nodo();
    Nodo(Persona* persona);
    void setNext(Nodo* next);
    Nodo* getNext();
    Persona* getPersona();
    int getID();
    void setID(int id);
    ~Nodo();
};



#endif /// EJ_OPENCV_NODO_H