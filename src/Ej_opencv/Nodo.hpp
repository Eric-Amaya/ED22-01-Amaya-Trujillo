#ifndef EJ_OPENCV_NODO_H
#define EJ_OPENCV_NODO_H   
#include "Persona.hpp" 
using namespace cv;
using namespace std;

class Nodo 
{
    private:
    Nodo* next;
    Persona* persona;
    int id;
    String tipo;

    public:
    Nodo();
    Nodo(Persona* persona);
    void setNext(Nodo* next);
    Nodo* getNext();
    Persona* getPersona();
    int getID();
    void setID(int id);
    void setTipo(String tipo);
    String getTipo();
    ~Nodo();
};



#endif /// EJ_OPENCV_NODO_H