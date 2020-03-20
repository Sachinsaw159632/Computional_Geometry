//
// Created by sachin on 13/01/20.
//

#include<iostream>
#include <cmath>
#include "vec.h"
#include "point.h"

namespace {
#define EPS 1e-9
}

namespace cg {

template<typename T>    
vec<T>::vec(T _x, T _y) {
    x = _x;
    y = _y;
}

template<typename T>
vec<T>::vec() {
    x = 0;
    y = 0;
}

template<typename T>
vec<T>::vec(point<T> p, point<T> q) {
    // this->vec<T>(q.get_x() - p.get_x(), q.get_y() - p.get_y());
    x=q.get_x() - p.get_x();
    y= q.get_y() - p.get_y();
}

template<typename T>
double vec<T>::mag() const {
    return (sqrt(x * x + y * y));
}

template<typename T>
void vec<T>::scale(double &times) {
    x = x * times;
    y = y * times;
}

template<typename T>
double vec<T>::dot(vec &other) const{
    return (x * other.x + y * other.y);
}

template<typename T>
double vec<T>::angle(vec &other) const {
    return (std::acos((this->dot(other) / (this->mag() * other.mag()))));
}

template<typename T>
vec<double> vec<T>::norm() const {
    double xc, yc, m;
    m = this->mag();
    xc = x / m;
    yc = y / m;
    return (vec<T>(xc, yc));
}

template<typename T>
double vec<T>::cross(vec &other) const {
    return (x * other.y - y * other.x);
}

template<typename T>
bool ccw(point<T> &p, point<T> &q, point<T> &r) {
    return (vec<T>(p, q).cross(vec<T>(p, r))) > 0;
}

template<class T>
bool collinear(point<T> &p, point<T> &q, point<T> &r) {
    vec<T> a(p, q);
    vec<T> b(p, r);
    // std::cout<<(fabs(a.cross(b)))<<std::endl;
    return (fabs(a.cross(b))) < EPS;
}

template<typename T>
double angle(point<T> &p, point<T> &q, point<T> &r) {
    vec<T> v1(q, p), v2(r, q);
    return (v1.angle(v2));
}

} // namespacw cg