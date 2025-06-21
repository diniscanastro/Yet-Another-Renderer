#ifndef SPHERE_H
#define SPHERE_H

#include "point.h"
#include "color.h"


class Sphere {
public:
    Point3D center;
    double radius;
    Color color;

    Sphere(const Point3D &center, double radius, Color color);
};

#endif //SPHERE_H
