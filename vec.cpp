//
// Created by sachin on 13/01/20.
//

#include <cmath>
#include "vec.h"
#define EPS 1e-9

vec::vec(double _x, double _y) {
    x=_x;
    y=_y;
}

vec::vec(){
    x=0;
    y=0;
}
vec::vec(point p,point q){
    return(vec(q.getx()-p.getx(),q.gety()-p.gety()));
}

double vec::mag() {
    return(std::sqrt(x*x+y*y));
}

void vec::scale(double t){
    x=x*t;
    y=y*t;
}

double vec::dot(vec other) {
    return(x *other.x + y*other.y);
}

double vec::angle(vec other) {
    return(std::acos((this->dot(other)/(this->mag()*other.mag()))));
}

vec vec::norm() {
    double xc,yc,m;
    m=this->mag();
    xc=x/m;
    yc=y/m;
    return(vec(xc,yc));
}

double vec::cross(vec other) {
    return(x*other.y - y-other.x);
}

bool ccw(point p,point q,point r){
    return(vec(p,q).cross(vec(p,r)))>0;
}

bool collinear(point &p, point &q,point &r){
    return (fabs(vec(p,q).cross(vec(p,r))))<EPS;
}

double angle(point p,point q,point r){
    vec v1(q,p),v2(r,q);
    return(v1.angle(v2));
}