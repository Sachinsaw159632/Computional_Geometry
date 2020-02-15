//
// Created by sachin on 13/01/20.
//

#ifndef COMGEO_POINT_H
#define COMGEO_POINT_H
class point{
private:
    double y;
    double x;
public:
    point(double a,double b);
    point();
    void show();
    bool operator == (point &other);
    bool operator !=(point &other);
    double dist(point &other);
    void rotate(double theta);
    double getx();
    double gety();
};
#endif //COMGEO_POINT_H
