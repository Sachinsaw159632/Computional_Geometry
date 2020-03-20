//
// Created by sachin on 14/01/20.
//

#ifndef COMGEO_TRIANGLE_H
#define COMGEO_TRIANGLE_H

#include<vector>
#include "point.h"

namespace cg {


template<typename T>
class triangle {
private:
    T a, b, c;
public:
    triangle(T _a, T _b, T _c);

    triangle();

    triangle(point<T> &a, point<T> &b, point<T> &c);

    double area() const;

    double peri() const;

    double rInCircle() const;

    double rCircumCircle() const;

    std::vector<T> sides() const{
        std::vector<T> arr(3);
        arr[0]=a;
        arr[1]=b;
        arr[2]=c;
        return(arr);
    }

};

} //namespace cg

//#include"triangle.cpp"

#endif //COMGEO_TRIANGLE_H
