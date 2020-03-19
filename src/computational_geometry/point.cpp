//
// Created by sachin on 13/01/20.
//
#include<iostream>
#include<cmath>

namespace {
#define EPS 1e-9
#define PI std::acos(-1)
}

namespace cg{

// #include"point.h"
template<typename T>
point<T>::point(T a, T b) {
    x = a;
    y = b;

}

template<typename T>
point<T>::point() {
    x = (double)0;
    y = (double)0;
}

template<typename T>
void point<T>::show() const {
    std::cout << "(" << x << "," << y << ")" << std::endl;
}

template<typename T>
bool point<T>::operator==(point &other) const {
    return (x - other.x) < EPS && (y - other.y) < EPS;
}

template<typename T>
double point<T>::dist(point &other) const {
    double d = (x - other.x) * (x - other.x);
    d += (y - other.y) * (y - other.y);
    return (sqrt(d));
}


// template<typename T>
// bool point<T>::operator!=(point &other) {
//     return(!(other == *this));
// }

template<typename T>
void point<T>::rotate(const double &theta_degree) {

// rotate the point by an angle theta 
// keeping center at origin
    double nx, ny, theta_radian;
    theta_radian = (PI / 180) * theta_degree;
    nx = x * cos(theta_radian) - y * sin(theta_radian);
    ny = x * sin(theta_radian) + y * cos(theta_radian);
    x = nx;
    y = ny;
}

template<typename T>
T point<T>::get_x() const {
    return (x);
}

template<typename T>
T point<T>::get_y() const {
    return (y);
}

} //namespace cg