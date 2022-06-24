#ifndef EJ_OPENCV_REQUERIMIENTOS
#define EJ_OPENCV_REQUERIMIENTOS

#include "ListaPersonas.hpp"
#include "Persona.hpp"

class Requerimientos
{
    private:
    ListaPersonas* lp;
    public:
    Requerimientos(ListaPersonas* lp);
    int movimiento(Persona* n, ListaPersonas* entrada, ListaPersonas* salida);
    double promedioV(ListaPersonas* entrada, ListaPersonas* salida, int t);

};

#endif ///EJ_OPENCV_REQUERIMIENTOS