#ifndef EJ_OPENCV_NODOA_H
#define EJ_OPENCV_NODOA_H
#include "Persona.hpp"
using namespace cv;
using namespace std;


class NodoA 
{
    private:
    Persona *p;
    NodoA* izq;
    NodoA * der;
    int id;
    String tipo;

    public:
    NodoA(Persona* p);
    NodoA* getIzq();
    NodoA* getDer();
    Persona* getPersona();
    int getID();
    void setID(int id);
    void setTipo(String tipo);
    String getTipo();
    ~NodoA();

};
#endif ///EJ_OPENCV_NODOA_H