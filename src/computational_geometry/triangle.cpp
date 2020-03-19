//
// Created by sachin on 14/01/20.
//

#include <cmath>
#include "triangle.h"
// #include"point.h"

namespace cg {

template<typename T>
triangle<T>::triangle(T _a, T _b, T _c) {
    a = _a;
    b = _b;
    c = _c;
}

template<typename T>
triangle<T>::triangle() {
    a = 0;
    b = 0;
    c = 0;
}

template<typename T>
triangle<T>::triangle(point<T> &a, point<T> &b, point<T> &c) {
    triangle(a.dist(b), b.dist(c), c.dist(a));
}

template<typename T>
double triangle<T>::area() const {
    double s;
    s = this->peri() / 2;
    return (sqrt(s * (s - a) * (s - b) * (s - c)));
}

template<typename T>
double triangle<T>::peri() const {
    return (a + b + c);
}

template<typename T>
double triangle<T>::rInCircle() const {
    double s = this->peri() * 0.5;
    return (this->area() / s);
}

template<typename T>
double triangle<T>::rCircumCircle() const {
    double R = a * b * c;
    R = R / 4;
    R = R / this->area();
    return (R);
}

} //namespace