//
// Created by sachin on 14/01/20.
//
#include <cmath>
#include "triangle.h"

triangle::triangle(double _a, double _b, double _c){
    a=_a;
    b=_b;
    c=_c;
}

triangle::triangle(){
    a=0;
    b=0;
    c=0;
}

triangle::triangle(point a,point b,point c){
    triangle(a.dist(b),b.dist(c),c.dist(a));
}

double triangle::area(){
    double s;
    s=this->peri()/2;
    return(std::sqrt(s*(s-a)*(s-b)*(s-c)));
}

double triangle::peri(){
    return(a+b+c);
}

double triangle::rInCircle(){
    double s=this->peri()*0.5;
    return(this->area()/s);
}

double triangle::rCircumCircle(){
    double R=a*b*c;
    R=R/4;
    R=R/this->area();
    return(R);
}
