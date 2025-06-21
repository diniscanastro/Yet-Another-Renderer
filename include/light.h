//
// Created by dinis on 19.06.2025.
//

#ifndef LIGHT_H
#define LIGHT_H

#include "point.h"


class Light {
public:
    double intensity;

    Light(double intensity): intensity(intensity) {};
    virtual ~Light() = default;

    virtual double calculateIntensityAtPoint(Point3D point, Point3D normal) = 0;
};

class AmbientLight : public Light {
public:
    AmbientLight(double intensity);

    double calculateIntensityAtPoint(Point3D point, Point3D normal) override;
};

class PointLight : public Light {
public:
    Point3D position;

    PointLight(double intensity, const Point3D &position);

    double calculateIntensityAtPoint(Point3D point, Point3D normal) override;

};

class DirectionalLight : public Light {
public:
    Point3D direction;

    DirectionalLight(double intensity, const Point3D &direction);

    double calculateIntensityAtPoint(Point3D point, Point3D normal) override;

};



#endif //LIGHT_H
