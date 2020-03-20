//
// Created by sachin on 14/01/20.
//

#ifndef COMGEO_CIRCLE_H
#define COMGEO_CIRCLE_H
#include "point.h"

namespace cg {

template<typename T>
class circle : public point<T> {
private:
    point<T> p;
    double r;
public:
    circle(point<T> _p, double rad);

    circle(T x, T y, double rad);

    circle();

    bool inside_circle(point<T> &pt) const;

    bool on_circle(point<T> &pt) const;

    bool out_circle(point<T> &pt) const;

    double area() const;

    double peri() const;

    point<T> centre() const;

    point<T> center() const;

    double radius() const;

};

} // namespace cg

//#include"circle.cpp"

#endif //COMGEO_CIRCLE_H
