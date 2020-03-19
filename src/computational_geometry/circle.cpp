//
// Created by sachin on 14/01/20.
//

#include <cmath>
#include "circle.h"
#include "point.h"

namespace {
#define EPS 1e-9
#define PI std::acos(-1)
}

namespace cg {

template<typename T>
circle<T>::circle(point<T> _p, double rad) {
    p = _p;
    r = rad;
}

template<typename T>
circle<T>::circle(T x, T y, double rad) {
    point<T> pt(x, y);
    circle(pt, rad);
}

template<typename T>
circle<T>::circle() {
    p = point<T>();
    r = 1;
}

template<typename T>
bool circle<T>::inside_circle(point<T> &pt) const {
    double d = this->p.dist(pt);
    return (d < this->r);
}

template<typename T>
bool circle<T>::on_circle(point<T> &pt) const{
    double d = this->p.dist(pt);
    return (d - this->r) < EPS;
}

template<typename T>
bool circle<T>::out_circle(point<T> &pt) const{
    double d = this->p.dist(pt);
    return (d > this->r);
}

template<typename T>
double circle<T>::area() const{
    return (PI * this->r * this->r);
}

template<typename T>
double circle<T>::peri() const{
    return (PI * this->r * 2);
}

template<typename T>
point<T> circle<T>::centre() const {
    return (this->p);
}

template<typename T>
point<T> circle<T>::center() const {
    return (this->p);
}

template<typename T>
double circle<T>::radius() const {
    return (this->r);
}

} //namespace