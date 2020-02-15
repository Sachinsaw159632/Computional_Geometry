//
// Created by sachin on 16/01/20.
//
#include <zconf.h>
#include <cmath>
#include "polygon.h"
#include "vec.h"
#define PI acos(-1)
#define EPS 1e-9

polygon::polygon(std::vector<point> pnts) {
    if(pnts[0]!=pnts[pnts.size()-1])
        pnts.push_back(pnts[0]);
    pts=pnts;
}

double polygon::peri() {
    double d=0;
    for(int i=0;i<pts.size()-1;i++){
        d+=pts[i].dist(pts[i+1]);
    }
    return(d);
}

double polygon::area(){
    double a=0,b=0;
    for(int i=0;i<pts.size()-1;i++){
        a+=pts[i].getx()*pts[i+1].gety();
        b+=pts[i+1].getx()*pts[i].gety();
    }
    return(a-b);
}

bool polygon::is_convex() {
    uint s=pts.size();
    if(s<=3) return(false);
    bool isLeft= ccw(pts[0],pts[1],pts[2]);
    for(uint i=1;i<s-1;i++){
        if(ccw(pts[i],pts[i+1],pts[i+2==s ? 1 : i+2]) !=isLeft){
            return(false);
        }
    }
    return true;
}
bool polygon::is_inside(point p) {
    if(pts.size()==0) return(false);
    double sum=0;
    for(int i=0;i<(int)pts.size()-1;i++){
        if(ccw(p,pts[i],pts[i+1]))
            sum+=angle(pts[i],p,pts[i+1]);
        else{
            sum-=angle(pts[i],p,pts[i+1]);
        }
    }
    return(fabs(fabs(sum)-2*PI)<EPS);
}

void polygon::line_cut(line ln) {

}

//// line segment p-q intersect with line A-B.
//point lineIntersectSeg(point p, point q, point A, point B) {
//    double a = B.y - A.y;
//    double b = A.x - B.x;
//    double c = B.x * A.y - A.x * B.y;
//    double u = fabs(a * p.x + b * p.y + c);
//    double v = fabs(a * q.x + b * q.y + c);
//    return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); }
//// cuts polygon Q along the line formed by point a -> point b
//// (note: the last point must be the same as the first point)
//vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
//    vector<point> P;
//    for (int i = 0; i < (int)Q.size(); i++) {
//        double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
//        if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
//        if (left1 > -EPS) P.push_back(Q[i]);
//// Q[i] is on the left of ab
//        if (left1 * left2 < -EPS)
//// edge (Q[i], Q[i+1]) crosses line ab
//            P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
//    }
//    if (!P.empty() && !(P.back() == P.front()))
//        P.push_back(P.front());
//// make P’s first point = P’s last point
//    return P; }
