//
// Created by sachin on 14/01/20.
//
#include <cmath>
#include "circle.h"
#define EPS 1e-9
circle::circle(point _p,double rad){
    p=_p;
    r=rad;
}
circle::circle(double x, double y, double rad){
    point pt(x,y);
    circle(pt,rad);
}

circle::circle(){
    p=point();
    r=1;
}

bool circle::inside_circle(point &pt){
    double d=this->p.dist(pt);
    return(d<this->r);
}
bool circle::on_circle(point &pt){
    double d=this->p.dist(pt);
    return(d-this->r)<EPS;
}
bool circle::out_circle(point &pt){
    double d=this->p.dist(pt);
    return(d>this->r);
}
double circle::area(){
    double PI=std::acos(-1);
    return(PI*this->r*this->r);
}
double circle::peri(){
    double PI=std::acos(-1);
    return(PI*this->r*2);
}
point circle::centre(){
    return(this->p);
}
double circle::radius(){
    return(this->r);
}
