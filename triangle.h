//
// Created by sachin on 14/01/20.
//

#ifndef COMGEO_TRIANGLE_H
#define COMGEO_TRIANGLE_H

#include "point.h"

class triangle{
private:
    double a,b,c;
public:
    triangle(double _a, double _b, double _c);
    triangle();
    triangle(point a,point b,point c);
    double area();
    double peri();
    double rInCircle();
    double rCircumCircle();




};
#endif //COMGEO_TRIANGLE_H
