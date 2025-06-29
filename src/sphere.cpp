#include "../include/sphere.h"


Sphere::Sphere(const Point3D &center, const double radius, const Color color, int specular, double reflectivity) :
    center(center),radius(radius), color(color), specular(specular), reflectivity(reflectivity) {
}


std::tuple<double, double> Sphere::intersectRaySphere(const Point3D &camera, const Point3D &direction) {
    double r = radius;
    Point3D c_o = camera - center;

    double a = direction * direction;
    double b = 2 * (c_o * direction);
    double c = c_o * c_o - pow(r,2);

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return std::make_tuple(std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());
    }

    double t1 = (-b + sqrt(discriminant)) / (2 * a);
    double t2 = (-b - sqrt(discriminant)) / (2 * a);
    return std::make_tuple(t1, t2);
}