//
// Created by sachin on 13/01/20.
//

#include <iostream>
#include <cmath>
#include "line.h"

namespace {
#define EPS 1e-9
}

namespace cg{

template<typename T>
line<T>::line(T _a, T _b, T _c) {
    a = _a;
    b = _b;
    c = _c;
}

template<typename T>
line<T>::line() {
    a = b = c = 0;
}

template<typename T>
line<T>::line(point<T> &p, point<T> &q) {
    if (fabs(p.get_x() - q.get_x()) < EPS) {
        b = 0.0;
        a = 1.0;
        c = -p.get_x();
    } else {
        a = -(double) (p.get_y() - q.get_y()) / (p.get_x() - q.get_x());
        b = 1.0;
        c = -(double) (a * p.get_x()) - p.get_y();
    }
}

template<typename T>
bool line<T>::is_parallel(line &other) const {
    return ((a - other.a) < EPS && (b - other.b) < EPS);
}

template<typename T>
bool line<T>::is_same(line &other) const {
    return ((a - other.a) < EPS && (b - other.b) < EPS && (c - other.c) < EPS);
}

template<typename T>
point<double> line<T>::intsec(line &other) const {

    //returns point of intersection

    if (this->is_parallel(other)) {
        std::cerr << "lines are parallel\n";
    }
    double xc, yc;
    xc = (other.b * c - b * other.c) / (other.a * b - a * other.b);
    if (fabs(b) > EPS) yc = -(a - xc + c);
    else yc = -(other.a * xc + other.c);

    return (point<double>(xc, yc));
}

template<typename T>
bool line<T>::operator==(line &other) const {
    return (this->is_same(other));
}

} //namespace cg