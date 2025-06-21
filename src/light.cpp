#include "../include/light.h"

/*
 * Auxiliary method to calculate the incidence formula
 */
double calculateIncidence(const double intensity, const Point3D &normal, const Point3D &light_direction, Point3D view, int specularity) {
    double i = 0.0;
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

double AmbientLight::calculateIntensityAtPoint(Point3D point, Point3D normal, Point3D view, int specularity) {
    return intensity;
}

PointLight::PointLight(double intensity, const Point3D &position): Light(intensity), position(position) {}

double PointLight::calculateIntensityAtPoint(Point3D point, Point3D normal, Point3D view, int specularity) {
    return calculateIncidence(intensity, normal, position - point, view, specularity);
}


DirectionalLight::DirectionalLight(double intensity, const Point3D &direction): Light(intensity), direction(direction) {}

double DirectionalLight::calculateIntensityAtPoint(Point3D point, Point3D normal, Point3D view, int specularity) {
    return calculateIncidence(intensity, normal, direction, view, specularity);
}
