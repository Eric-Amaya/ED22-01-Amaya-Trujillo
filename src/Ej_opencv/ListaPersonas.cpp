#include "ListaPersonas.hpp"
#include <iostream>

ListaPersonas:: ListaPersonas()
{
    this->first = nullptr;
    this->cant = 0;
}

/**
 * @brief Se entrega como parametro una persona para ingresarla en el nodo y luego en la lista enlazada.
 *        Lo siguiente es si no esta vacio, entra al algoritmo para buscar a partir de las personas ya ingresadas si son las mismas o no, y si es asi determinar si se mueven
 *        hacia la entrada o la salida
 * 
 * @param n 
 */
void ListaPersonas:: ingresarPersona(Persona* n) 
{
    Nodo* nodo = new Nodo(n);
    if(first== NULL)
    {
        this->first = nodo;
        this->first->setID(this->cant);
    }
    else 
    {
        nodo->setNext(first);
        this->first = nodo;
        nodo->setID(this->cant);
        for(int i=0;i<this->cant;i++) 
        {
            Nodo* no = buscarNodo(i);
            Persona *p = buscarNodo(i)->getPersona(); 
            if((p->getXCentro()<n->getXCentro()) && (p->getYCentro() < n->getYCentro())) 
            {
                if(((n->getXCentro()- p->getXCentro())<10) || ((n->getYCentro()- p->getYCentro())<10)) 
                {
                    nodo->setTipo("entrada");
                }

            }
            else 
            {
                if(((p->getXCentro()- n->getXCentro())<10) || ((p->getYCentro()- n->getYCentro())<10)) 
                {
                    nodo->setTipo("salida");
                }
            }
        }
    }
    this->cant++;   
}

int ListaPersonas:: getCantidad() 
{
    return this->cant;
}
/**
 * @brief Busca un nodo a partir de un numero i dado, para poder recorrer y recibir los nodos
 * 
 * @param num 
 * @return Nodo* 
 */
Nodo* ListaPersonas::buscarNodo(int num) 
{
    Nodo* aux = this->first;
    while(aux != nullptr)
    {
        if(aux->getID() == num) 
        {
            return aux;
        }
        aux = aux->getNext();
    }
    return NULL;
}


ListaPersonas::~ListaPersonas() {}

