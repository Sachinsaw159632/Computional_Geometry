//
// Created by sachin on 14/01/20.
//

#ifndef COMGEO_POLYGON_H
#define COMGEO_POLYGON_H
#include<vector>
#include "point.h"
#include "line.h"

class polygon{
private:
    std::vector<point> pts;
public:
    polygon(std::vector<point> pnts);
    friend polygon convex_hull(std::vector<point> v);
    double peri();
    double area();
    bool is_convex();
    bool is_inside(point p);
    void line_cut(line ln);


};
#endif //COMGEO_POLYGON_H
