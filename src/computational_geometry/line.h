//
// Created by sachin on 13/01/20.
//

#ifndef COMGEO_LINE_H
#define COMGEO_LINE_H
#include "point.h"

namespace cg {

template<typename T>
class line : public point<T> {
private:
    T a, b, c;
    // line is of type "ax + by + c = 0"
public:
    line(T _a, T _b, T _c);

    line();

    line(point<T> &p, point<T> &q);

    bool is_parallel(line &other) const;

    bool is_same(line &other) const;

    bool operator==(line &other) const;

    point<double> intsec(line &other) const;       // returns intersection point ### if they are not parallel
};

} //namspace cg

#include"line.cpp"

#endif //COMGEO_LINE_H
