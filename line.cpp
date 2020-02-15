//
// Created by sachin on 13/01/20.
//

#include <cmath>
#include <iostream>
#include "line.h"
#define EPS 1e-9


line::line(double _a, double _b, double _c){
    a=_a;
    b=_b;
    c=_c;
}
line::line(){
    a=b=c=0;
}

line::line(point &p,point &q){
    if(fabs(p.getx()-q.getx())<EPS) {
        b=0.0;
        a=1.0;
        c=-p.getx();
    }
    else{
        a=-(double)(p.gety()-q.gety())/(p.getx()-q.getx());
        b=1.0;
        c=-(double)(a*p.getx())-p.gety();
    }
}

bool line::is_parallel(line &other) {
    return((a-other.a)<EPS && (b-other.b)<EPS);
}

bool line::is_same(line &other) {
    return((a-other.a)<EPS && (b-other.b)<EPS && (c-other.c)<EPS);
}

point line::intsec(line &other) {
    if(this->is_parallel(other)){
        std::cerr<<"lines are parallel\n";
    }
    double xc,yc;
    xc =(other.b * c - b * other.c ) / ( other.a * b - a * other.b);
    if(fabs(b)>EPS) yc=-( a-xc + c);
    else yc=-(other.a*xc+other.c);

    return(point(xc,yc));
}

bool line::operator==(line &other) {
    return(this->is_same(other));
}