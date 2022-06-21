#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "src/logic/includes/Nodo.h"
#include "src/logic/includes/ListaPersonas.h"
using namespace cv;
using namespace std;


int main(int argc, char** argv) {
    ListaPersonas* lp = new ListaPersonas();
    Nodo* n = new Nodo();

    Mat image;
    image = imread("C:/Users/USUARIO/Downloads/ejemplito.jpg");
    if (!image.data)    
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display image" , WINDOW_AUTOSIZE);
    imshow("Display image", image);
    waitKey(0);
}
