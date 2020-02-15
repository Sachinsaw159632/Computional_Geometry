//
// Created by sachin on 14/01/20.
//

#ifndef COMGEO_CIRCLE_H
#define COMGEO_CIRCLE_H

#include "point.h"

class circle: public point{
private:
    point p;
    double r;
public:
    circle(point _p,double rad);
    circle(double x, double y, double rad);
    circle();
    bool inside_circle(point &pt);
    bool on_circle(point &pt);
    bool out_circle(point &pt);
    double area();
    double peri();
    point centre();
    double radius();

};
#endif //COMGEO_CIRCLE_H
