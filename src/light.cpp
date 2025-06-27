#include "../include/light.h"
#include "../include/sphere.h"
#include "../include/world.h"

/*
 * Auxiliary method to calculate the incidence formula
 */
double calculateIncidence(std::vector<Sphere>& spheres, const double intensity, const Point3D &normal, const Point3D &point, const Point3D &light_direction, Point3D view, int specularity, double t_max) {
    double i = 0.0;

    const Sphere* shadow_sphere = nullptr;
    double shadow_t;

    std::tie(shadow_sphere, shadow_t) = closestIntersection(spheres, point, light_direction, 0.001, t_max);
    if (shadow_sphere != nullptr) {
        return i;
    }

    // Diffuse component
    const double n_dot_l = normal * light_direction;
    if (n_dot_l > 0.0) {
        i += intensity * n_dot_l / (normal.magnitude() * light_direction.magnitude());
    }

    // Specular component
    if(specularity != -1) {
        Point3D r = ((normal * 2) * (normal * light_direction)) - light_direction;
        double r_dot_v = r * view;
        if (r_dot_v > 0.0) {
            i += intensity * pow(r_dot_v / (r.magnitude() * view.magnitude()), specularity);
        }
    }

    return i;
}


AmbientLight::AmbientLight(double intensity): Light(intensity) {}

double AmbientLight::calculateIntensityAtPoint(std::vector<Sphere>& spheres, Point3D point, Point3D normal, Point3D view, int specularity) {
    return intensity;
}

PointLight::PointLight(double intensity, const Point3D &position): Light(intensity), position(position) {}

double PointLight::calculateIntensityAtPoint(std::vector<Sphere>& spheres, Point3D point, Point3D normal, Point3D view, int specularity) {
    return calculateIncidence(spheres, intensity, normal, point, position - point, view, specularity, 1.0);
}


DirectionalLight::DirectionalLight(double intensity, const Point3D &direction): Light(intensity), direction(direction) {}

double DirectionalLight::calculateIntensityAtPoint(std::vector<Sphere>& spheres, Point3D point, Point3D normal, Point3D view, int specularity) {
    return calculateIncidence(spheres, intensity, normal, point, direction, view, specularity, std::numeric_limits<double>::infinity());
}
