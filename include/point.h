//
// Created by dinis on 14.06.2025.
//

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
#include <iostream>

class Point2D{
public:
    double x, y;

    Point2D();
    Point2D(double x, double y);

    /*
    * Compares 2 points/vectors for equality
    */
    bool operator==(Point2D obj) const;

    /*
    * Adds 2 points/vectors
    */
    Point2D operator+(Point2D obj) const;

    /*
    * Subtracts 2 points/vectors
    */
    Point2D operator-(Point2D obj) const;

    /*
    * Divides a point/vector with a scalar
    */
    Point2D operator/(const double k) const;

    /*
    * Multiplies a point/vector with a scalar
    */
    Point2D operator*(const double k) const;

    /*
    * Dot product between 2 points/vectors
    */
    double operator*(const Point2D obj) const;

    /*
    * Magnitude of a vector (length)
    */
    double magnitude() const;

    /*
    * Angle between 2 vectors
    */
    double angle(const Point2D obj) const;

    /*
    * Retrieve a point/vector normalized to magnitude 1
    */
    Point2D normalize() const;
};

std::ostream& operator<<(std::ostream& os, Point2D const& point);

class Point3D {
public:
    double x, y, z;

    Point3D();
    Point3D(double x, double y, double z);

    /*
    * Compares 2 points/vectors for equality
    */
    bool operator==(const Point3D obj) const;

    /*
    * Adds 2 points/vectors
    */
    Point3D operator+(const Point3D obj) const;

    /*
    * Subtracts 2 points/vectors
    */
    Point3D operator-(const Point3D obj) const;

    /*
    * Multiplies a point/vector with a scalar
    */
    Point3D operator*(const double k) const;

    /*
    * Divides a point/vector with a scalar
    */
    Point3D operator/(const double k) const;

    /*
    * Dot product between 2 points/vectors
    */
    double operator*(const Point3D obj) const;

    /*
    * Angle between 2 vectors
    */
    double angle(const Point3D obj) const;

    /*
    * Magnitude of a vector (length)
    */
    double magnitude() const;

    /*
    * Retrieve a point/vector normalized to magnitude 1
    */
    Point3D normalize() const;
};

std::ostream& operator<<(std::ostream& os, Point3D const& point);

#endif //POINT_H
