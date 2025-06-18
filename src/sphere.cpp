#include "../include/sphere.h"
#include "../include/point.h"
#include "../include/color.h"

class Sphere {
public:
    Point3D center;
    double radius;
    Color color;

    Sphere(Point3D center, double radius, Color color) : center(center), radius(radius), color(color) {}
};
