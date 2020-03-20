//
// Created by sachin on 13/01/20.
//

#ifndef COMGEO_VEC_H
#define COMGEO_VEC_H

#include "point.h"

namespace cg {


template<typename T>
class vec : public point<T> {
private:
    T x;
    T y;
public:
    vec(T _x, T _y);

    vec();

    vec(point<T> p, point<T> q);

    double mag() const;

    void scale(double &times);

    double dot(vec &other) const;

    double angle(vec &other) const;

    vec<double> norm() const;

    double cross(vec &other) const;

    T get_x() const{
        return(x);
    }

    T get_y() const{
        return(y);
    }

    friend bool ccw(point<T> &p, point<T> &q, point<T> &r);

    // returns true if point r is on the left side of line pq
    friend bool collinear(point<T> &p, point<T> &q, point<T> &r);

    friend double angle(point<T> &p, point<T> &q, point<T> &r);


};

} // namespace cg

//#include"vec.cpp"

#endif //COMGEO_VEC_H
