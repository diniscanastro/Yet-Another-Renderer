//
// Created by dinis on 27.06.2025.
//

#ifndef AUXILIARY_H
#define AUXILIARY_H
#include <tuple>
#include <vector>

#include "sphere.h"


inline std::tuple<const Sphere *, double> closestIntersection(std::vector<Sphere>& spheres, const Point3D &camera, const Point3D &direction,
                                                              double t_min, double t_max) {
    double closest_t = std::numeric_limits<double>::infinity();
    const Sphere* closest_sphere = nullptr;

    for (int i = 0; i < spheres.size(); i++) {
        double t1, t2;
        std::tie(t1, t2) = spheres[i].intersectRaySphere(camera, direction);
        if (t1 > t_min && t1 < t_max) {
            if (t1 < closest_t) {
                closest_t = t1;
                closest_sphere = &spheres[i];
            }
        }
        if (t2 > t_min && t2 < t_max) {
            if (t2 < closest_t) {
                closest_t = t2;
                closest_sphere = &spheres[i];
            }
        }
    }
    return std::make_tuple(closest_sphere, closest_t);
}

inline Point3D reflectRay(const Point3D &ray_direction, const Point3D &normal) {
    return ((normal * 2) * (normal * ray_direction)) - ray_direction;
}

#endif //AUXILIARY_H
