#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <iomanip>

#include "Detector.hpp"
#include "Persona.hpp"
#include "ListaPersonas.hpp"
#include "Nodo.hpp"
#include "ListaArbol.hpp"
#include "NodoA.hpp"

using namespace cv;
using namespace std;
/**
 * @brief Metodo que recorre el arbol de forma inorden, devolviendo el nodo por el que pasa
 * 
 * @param raiz 
 * @return NodoA* 
 */
NodoA* recorrer (NodoA * raiz) 
{
    if(raiz != NULL) 
    {
        recorrer(raiz->getIzq());
        return raiz;
        recorrer(raiz->getDer());
    }
};
/**
 * @brief Metodo para ingresar en el arbol segun el requerimiento de entrada y salida
 * 
 * @param raiz 
 * @param p 
 */
void ingresar(NodoA * raiz, Persona * p) 
{
    if(raiz == NULL) 
    {
        NodoA * nodo = new NodoA(p);
        raiz = nodo;
    }
    else 
    {
        if(recorrer(raiz)->getPersona()->getXCentro() <= p->getXCentro()) 
        {
            if((p->getXCentro()- recorrer(raiz)->getPersona()->getXCentro()<10) && ((p->getYCentro()- recorrer(raiz)->getPersona()->getYCentro()<10))) 
            {
                recorrer(raiz)->setTipo("entrada");
            }
        }
        else if (recorrer(raiz)->getPersona()->getXCentro() > p->getXCentro()) 
        {
            if(( recorrer(raiz)->getPersona()->getXCentro()-p->getXCentro()<10) && (( recorrer(raiz)->getPersona()->getYCentro()-p->getYCentro()<10))) 
            {
                recorrer(raiz)->setTipo("salida");
            }
        }
        else
        {
            int valor = raiz->getPersona()->getXCentro();
            if(p->getXCentro()< valor) 
            {
                ingresar(raiz->getIzq(),p);
            }
            else 
            {
                ingresar(raiz->getDer(),p);
            }  
        }                  
    }
};

/**
 * @brief Recorre el arbol y cuenta la cantidad de nodos que guardan el mismo parametro de String entregado, que en este caso
 *        seria de entrada o salida y devuelve el entero que se sumo recursivamente  
 * 
 * @param raiz 
 * @param b 
 * @return int 
 */
int conseguir (NodoA *raiz, String b) 
{
    if(raiz == NULL) 
    {
        return 0;
    }
    else 
    {
        if(raiz->getTipo()._Equal(b)) 
        {
            return 1 + conseguir(raiz->getIzq(),b) + conseguir(raiz->getDer(),b);
        }
        else 
        {
            return 0;
        }
    }    
};

int main(int argc, char** argv)
{
    Detector detector;
    Mat image;
    ListaPersonas *lista = new ListaPersonas(); 
    int a;
    for(a=1;a<3;a++) // ciclo para la cantidad de imagenes disponibles
    {
        String num = to_string(a);
        image = imread("C:/Users/USUARIO/OneDrive/Escritorio/Videos taller/imagen" + num + ".png");
        detector.toggleMode();
        cout << detector.modeName() << endl;   
        vector<Persona> found = detector.detect(image);
        for (vector<Persona>::iterator i = found.begin(); i != found.end(); ++i)
        {
            Persona &p = *i; 
            lista->ingresarPersona(&p);
        }
        String ans = "SI";
        while(ans._Equal("SI")) 
        { 
            int op = 0;
            int entrada = 0;
            int salida = 0;
            String ingreso;
            cout<< "Indique el tipo de ingreso: " << ends; // GUARDIA o ADMIN
            std::cin>> ingreso;
            while(!ingreso._Equal("GUARDIA") && !ingreso._Equal("ADMIN")) 
            {
                cout << "\n El tipo de ingreso es incorrecto, ingrese nuevamente el tipo de ingreso: " << ends;
                std::cin>> ingreso;
            }
            if(ingreso._Equal("GUARDIA")) 
            {
                while(op!=6) 
                { 
                    cout << "   MENU GUARDIA \n 1) Deteccion de Personas\n 2) Trafico de entrada\n 3) Trafico"
                        << " de salida\n 4) Flujo de entrada\n 5) Flujo de salida \n 6) Salir del menu" << "\nIngrese una opcion: "<< ends;
                    std::cin >> op;
                    while(op!= 1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6 && op!=0)
                    {
                        cout << "\n La opcion ingresada es incorrecta, ingrese nuevamente una opcion: " << ends;
                        std::cin >> op;
                    }
                    if (op==1) 
                    {
                        cout << "\n Cargando deteccion de personas...\n" << endl;
                        for (vector<Persona>::iterator i = found.begin(); i != found.end(); ++i)
                        {
                            Persona &p = *i; 
                            rectangle(image, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
                            circle(image, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
                            circle(image, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);
                            circle(image, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
                            cout << "Centro: " << p.getXCentro() << " , " << p.getYCentro() << endl; 
                        }
                        imshow("People detector", image);
                        waitKey(0);
                    }
                    else if (op==2) 
                    {
                        for(int b=0;b<lista->getCantidad();b++) 
                        {
                            if(lista->buscarNodo(b)->getTipo()._Equal("entrada")) 
                            {
                                entrada++;
                            }
                        }
                        cout<< "\nEl trafico de entrada al momento es de " << entrada << " personas Y LISTA TIENE " << lista->getCantidad()<< endl;
                    }
                    else if (op==3) 
                    {
                        for(int b=0;b<lista->getCantidad();b++) 
                        {
                            if(lista->buscarNodo(b)->getTipo()._Equal("salida")) 
                            {
                                salida++;
                            }
                        }
                        cout<< "\nEl trafico de salida al momento es de " << salida << " personas" << endl;
                    }
                    else if (op==4) 
                    {
                        cout<< "\nEl flujo de entrada promedio es de " << (entrada/1) << " personas por una hora\n"<<endl; // El tiempo indicado es de 1, el cual corresponde a una hora determinado arbitrariamente
                                                                                                        // ,ya que no hay una cantidad mas extensa que esta de fotogramas 
                    }
                    else if (op==5) 
                    {
                        cout<< "\nEl flujo de salida promedio es de " << (salida/1) << " personas por una hora\n"<< endl; // El tiempo indicado es de 1, el cual corresponde a una hora determinado arbitrariamente
                                                                                                        // ,ya que no hay una cantidad mas extensa que esta de fotogramas
                    }
                    else 
                    {
                        break;
                    }
                }
            }
            else
            {
                while(op!=2) 
                { 
                    cout << "   MENU ADMIN \n 1) Configuracion de archivos\n 2)Salir del menu" << "\nIngrese una opcion: "<< ends;                 
                    std::cin >> op;
                    while(op!= 1 && op!=2)
                    {
                        cout << "\n La opcion ingresada es incorrecta, ingrese nuevamente una opcion: " << ends;
                        std::cin >> op;
                    }
                    if (op==1) 
                    {
                        imshow("ADMIN", image);
                        waitKey(0);
                    }
                    else 
                    {
                        break;
                    }
                }    
            } 
            cout << "HA SALIDO CORRECTAMENTE DEL MENU, DESEA VOLVER A INGRESAR? SI - NO : " << ends;   
            std::cin >> ans;

            while (!ans._Equal("NO") && !ans._Equal("SI")) 
            {
                cout<< "OPCION INCORRECTA, DESEA VOLVER A INGRESAR? SI - NO : " << ends;
                std::cin >> ans;
            }
        }    
        cout << "HA SALIDO CORRECTAMENTE DEL PROGRAMA" << endl;
    } // FIN DEL FOR   
    return 0;
}
