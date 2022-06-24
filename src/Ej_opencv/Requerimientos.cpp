#include "Requerimientos.hpp"
#include "ListaPersonas.hpp"
#include "Persona.hpp"
#include "Nodo.hpp"

using namespace std;
Requerimientos::Requerimientos(ListaPersonas* lp) 
{
    this->lp = lp;
}
/**
 * @brief Este metodo clasifica segun el movimiento tomado para cada frame comparandolo con las 
 * personas identificadas anteriormente, clasificando asi segun el centro de la deteccion si el
 * movimiento es de entrada, de salida o es una persona nueva
 * @param n 
 * @param entrada 
 * @param salida 
 * @return int 
 */
int Requerimientos::movimiento(Persona* n, ListaPersonas* entrada, ListaPersonas* salida) 
{
    int a =this->lp->getCantidad();
    if(a>0) 
    {
        for(int i=0;i<a;i++) 
        {
            Persona* p = lp->buscarNodo(i)->getPersona();
            if(p->getXCentro()>= n->getXCentro())
            {
                if( (p->getXCentro()- n->getXCentro()) <=10 && (p->getYCentro()- n->getYCentro()) <=10) 
                {
                    salida->ingresarPersona(n);
                    return -1;
                }
                else 
                {
                    lp->ingresarPersona(n);
                    return 0;
                }
            }
            else 
            {
                if( (n->getXCentro()- p->getXCentro()) <=10 && (n->getYCentro()- p->getYCentro()) <=10) 
                {
                    entrada->ingresarPersona(n);
                    return 1;
                }
                else 
                {
                    lp->ingresarPersona(n);
                    return 0;
                }
            }    
        
        }
    }
    else
    {
        lp->ingresarPersona(n);
        return 0;
    }    
}
/**
 * @brief En este metodo se calcula las velocidad para las personas que entran y salen respecto a un tiempo,
 * estableciendo asi un flujo promedio de personas
 * @param entrada 
 * @param salida 
 * @param t 
 * @return double 
 */
double Requerimientos::promedioV(ListaPersonas* entrada, ListaPersonas* salida, int t) 
{
    int cantE = entrada->getCantidad();
    int cantS = salida->getCantidad();
    return ((cantE/t) + (cantS/t)) /2;
}
