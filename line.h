//
// Created by sachin on 13/01/20.
//

#ifndef COMGEO_LINE_H
#define COMGEO_LINE_H

#include "point.h"

class line:public point{
private:
    double a,b,c;
    // line is of type "ax + by + c = 0"
public:
    line(double _a,double _b,double _c);
    line();
    line(point &p ,point &q);
    bool is_parallel(line &other);
    bool is_same(line &other);
    bool operator==(line &other);
    point intsec(line &other);       // returns intersection point
};

#endif //COMGEO_LINE_H
