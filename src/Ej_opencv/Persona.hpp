#ifndef PERSONA_H
#define PERSONA_H

#include <opencv2/opencv.hpp>

class Persona
{
private:
    int xComienzo;
    int yComienzo;
    int xFin;
    int yFin;
    int xCentro;
    int yCentro;
public:
    Persona(cv::Rect&);
    Persona();
    int getXComienzo();
    int getYComienzo();
    int getXFin();
    int getYFin();
    int getXCentro();
    void setXCentro(int x);
    int getYCentro();
    void setYCentro(int y);
};

#endif