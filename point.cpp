//
// Created by sachin on 13/01/20.
//
#include <iostream>
#include "point.h"
#include <cmath>
#define EPS 1e-9
point::point(double a,double b){
    x=a;
    y=b;
}
point::point(){
    x=0;
    y=0;
}

void point::show(){
    std::cout<<"("<<x<<","<<y<<")";
}

bool point::operator==(point &other) {
    return (x - other.x)<EPS && (y - other.y)<EPS;
}

double point::dist(point &other) {
    double d=(x-other.x)*(x-other.x);
    d+=(y-other.y)*(y-other.y);
    return(std::sqrt(d));
}

void point::rotate(double theta) {
    double PI;
    PI = std::acos(-1);
    theta=(PI/180)*theta;
    double nx,ny;
    nx=x*cos(theta)-y*sin(theta);
    ny=x*sin(theta)+y*cos(theta);
    x=nx;
    y=ny;
}

double point::getx() {
    return(x);
}

double point::gety() {
    return(y);
}