#ifndef DETECTOR_H
#define DETECTOR_H

#include <opencv2/opencv.hpp>

#include <iostream>
#include <iomanip>

#include "Persona.hpp"


using namespace cv;
using namespace std;


class Detector
{
private:
    enum Mode {Daimler } m;
    HOGDescriptor hog, hog_d;
public:
    Detector() : m(Daimler), hog(), hog_d(Size(48, 96), Size(16, 16), Size(8, 8), Size(8, 8), 9){
        hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
        hog_d.setSVMDetector(HOGDescriptor::getDaimlerPeopleDetector());
    }    

    void toggleMode();

    string modeName() const;

    vector<Persona> detect(InputArray img);

    void adjustRect(Rect & r) const;
};

#endif