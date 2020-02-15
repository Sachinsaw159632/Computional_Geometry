//
// Created by sachin on 13/01/20.
//

#ifndef COMGEO_VEC_H
#define COMGEO_VEC_H

#include "point.h"

class vec: public point{
private:
    double x;
    double y;
public:
    vec(double _x,double _y);
    vec();
    vec(point p,point q);
    double mag();
    void scale(double t);
    double dot(vec other);
    double angle(vec other);
    vec norm();
    double cross(vec other);
    friend bool ccw(point p,point q,point r);
        // returns true if point r is on the left side of line pq
    friend bool collinear(point &p,point &q,point &r);
    friend double angle(point p,point q,point r);



};

#endif //COMGEO_VEC_H
