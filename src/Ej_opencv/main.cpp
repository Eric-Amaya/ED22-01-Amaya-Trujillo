#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <iomanip>

#include "Detector.hpp"
#include "Persona.hpp"
#include "ListaPersonas.hpp"
#include "Nodo.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

    ListaPersonas* entrada = new ListaPersonas();
    Detector detector;
    Mat image;
    image = imread("C:/Users/USUARIO/OneDrive/Escritorio/Videos taller/imagen4.jpeg");
    detector.toggleMode();
    cout << detector.modeName() << endl;

    vector<Persona> found = detector.detect(image);
    int a=1;
    for (vector<Persona>::iterator i = found.begin(); i != found.end(); ++i)
    {
        Persona &p = *i;
        cout<< "Persona " << a << endl;
        cout << "( Inicio: " << p.getXComienzo() << ", " << p.getYComienzo() << ")" << endl;
        cout << "( Centro: " << p.getXCentro() << ", " << p.getYCentro() << ")" << endl;
        cout << "( Fin: " << p.getXFin() << ", " << p.getYFin() << ")" << endl;
        //detector.adjustRect(p);
        rectangle(image, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
        circle(image, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
        circle(image, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);
        circle(image, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
        a++;
    }
    
    imshow("People detector", image);
    waitKey(0);

    return 0;
}
