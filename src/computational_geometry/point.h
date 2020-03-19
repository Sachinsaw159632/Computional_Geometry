//
// Created by sachin on 13/01/20.
//

#ifndef COMGEO_POINT_H
#define COMGEO_POINT_H

namespace cg {

template <typename T>
class point {
private:
    T x;
    T y;
public:

    point(T a, T b);

    point();

    void show() const;

    bool operator==(point &other) const;

    double dist(point &other) const;

    // bool operator!=(point other);

    void rotate(const double &theta_radian);

    T get_x() const;

    T get_y() const;
};
} //namespace cg
#include"point.cpp"

#endif //COMGEO_POINT_H

