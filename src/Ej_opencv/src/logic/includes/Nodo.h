#ifndef EJ_OPENCV_NODO_H
#define EJ_OPENCV_NODO_H    

class Nodo 
{
    private:
    Nodo* next;
    int dato;

    public:
    Nodo();
    Nodo(int dato);
    void setNext(Nodo* next);
    Nodo* getNext();
    int getDato();
    ~Nodo();
};



#endif /// EJ_OPENCV_NODO_H