#ifndef SPHERE_H
#define SPHERE_H

#include <tuple>

#include "point.h"
#include "color.h"


class Sphere {
public:
    Point3D center;
    double radius;
    Color color;
    int specular;
    double reflectivity;

    Sphere(const Point3D &center, double radius, Color color, int specular, double reflectivity);

    std::tuple<double, double> intersectRaySphere(const Point3D &camera, const Point3D &direction);
};

#endif //SPHERE_H
