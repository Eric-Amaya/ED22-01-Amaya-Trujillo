#include <opencv2/opencv.hpp>

#include <iostream>
#include <iomanip>

using namespace cv;
using namespace std;


#include "Detector.hpp"

void Detector::toggleMode() { m = (m == Daimler ? Daimler : Daimler); }
    
string Detector::modeName() const { return (m == Daimler ? "Default" : "Daimler"); }
/**
 * @brief Este metodo se le pasa una imagen y a partir de la libreria detecta a las personas en la imagen, las cuales se almacenan en un vector
 *        de tipo persona y se retornan 
 * 
 * @param img 
 * @return vector<Persona> 
 */
vector<Persona> Detector::detect(InputArray img){
        // Run the detector with default parameters. to get a higher hit-rate
        // (and more false alarms, respectively), decrease the hitThreshold and
        // groupThreshold (set groupThreshold to 0 to turn off the grouping completely).
        vector<Rect> found;

        hog_d.detectMultiScale(img, found, 1, Size(2,2), Size(4,4), 1.05, 3, true);

        // Convertir un objeto Rect a un objeto persona
        vector<Persona> personas;

        for (vector<Rect>::iterator i = found.begin(); i != found.end(); ++i){
            Rect &r = *i;
            Persona p(r);
            personas.push_back(p);
        }

        return personas;
}

void Detector::adjustRect(Rect & r) const{
        // The HOG detector returns slightly larger rectangles than the real objects,
        // so we slightly shrink the rectangles to get a nicer output.
        r.x += cvRound(r.width*0.1);
        r.width = cvRound(r.width*0.8);
        r.y += cvRound(r.height*0.07);
        r.height = cvRound(r.height*0.8);
}
