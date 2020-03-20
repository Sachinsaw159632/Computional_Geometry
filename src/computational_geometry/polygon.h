//
// Created by sachin on 14/01/20.
//

#ifndef COMGEO_POLYGON_H
#define COMGEO_POLYGON_H

#include<vector>
#include "point.h"
#include "line.h"


namespace cg {

template<typename T>
class polygon {
private:
    std::vector<point<T>> pts;
public:
    polygon(std::vector<point<T>> pnts);

    friend polygon convex_hull(std::vector<point<T>> v); // returns convex hull of scatter points(given)

    double peri() const;

    double area() const;

    bool is_convex() const;

    bool is_inside(point<T> &p) const;

    // void line_cut(line &ln) const;


};


} //namespace cg

//#include"polygon.h"

#endif //COMGEO_POLYGON_H
