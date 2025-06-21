#include "../include/light.h"

/*
 * Auxiliary method to calculate the incidence formula
 */
double calculateIncidence(const double intensity, const Point3D &normal, const Point3D &light_direction) {
    const double n_dot_l = normal * light_direction;
    if (n_dot_l > 0.0) {
        return intensity * n_dot_l / (normal.magnitude() * light_direction.magnitude());
    }
    return 0.0;
}


AmbientLight::AmbientLight(double intensity): Light(intensity) {}

double AmbientLight::calculateIntensityAtPoint(Point3D point, Point3D normal) {
    return intensity;
}

PointLight::PointLight(double intensity, const Point3D &position): Light(intensity), position(position) {}

double PointLight::calculateIntensityAtPoint(Point3D point, Point3D normal) {
    return calculateIncidence(intensity, normal, position - point);
}


DirectionalLight::DirectionalLight(double intensity, const Point3D &direction): Light(intensity), direction(direction) {}

double DirectionalLight::calculateIntensityAtPoint(Point3D point, Point3D normal) {
    return calculateIncidence(intensity, normal, direction);
}
