//
// Created by dinis on 14.06.2025.
//

#include "../include/point.h"

#include <cmath>
#include <iostream>
using namespace std;

class Point2D {
public:
	float x, y;

	Point2D() : x(0.f), y(0.f) {}
	Point2D(float x, float y) : x(x), y(y) {}

	/*
	* Compares 2 points/vectors for equality
	*/
	bool operator==(Point2D obj) const {
		return this->x == obj.x && this->y == obj.y;
	}

	/*
	* Adds 2 points/vectors
	*/
	Point2D operator+(Point2D obj) const {
		Point2D res;
		res.x = x + obj.x;
		res.y = y + obj.y;

		return res;
	}

	/*
	* Subtracts 2 points/vectors
	*/
	Point2D operator-(Point2D obj) const {
		Point2D res;
		res.x = x - obj.x;
		res.y = y - obj.y;

		return res;
	}

	/*
	* Multiplies a point/vector with a scalar
	*/
	Point2D operator*(const float k) const {
		Point2D res;
		res.x = x * k;
		res.y = y * k;

		return res;
	}

	/*
	* Divides a point/vector with a scalar
	*/
	Point2D operator/(const float k) const {
		return *this * (1/k);
	}

	/*
	* Dot product between 2 points/vectors
	*/
	float operator*(const Point2D obj) const {
		return x * obj.x + y * obj.y;
	}

	/*
	* Angle between 2 vectors
	*/
	float angle(const Point2D obj) const {
		return acos((*this * obj) / (this->magnitude() * obj.magnitude()));
	}

	/*
	* Magnitude of a vector (length)
	*/
	float magnitude() const {
		return float(sqrt(pow(x, 2) + pow(y, 2)));
	}

	/*
	* Retrieve a point/vector normalized to magnitude 1
	*/
	Point2D normalize() const {
		return *this / this->magnitude();
	}

	ostream& operator<< (ostream& os) const {
		return (os << "{" << x << "," << y << "}");
	}
};


class Point3D {
public:
	float x, y, z;

	Point3D() : x(0.f), y(0.f), z(0.f) {}
	Point3D(float x, float y, float z) : x(x), y(y), z(z) {}

	/*
	* Adds 2 points/vectors
	*/
	Point3D operator+(const Point3D obj) const {
		Point3D res;
		res.x = x + obj.x;
		res.y = y + obj.y;
		res.z = z + obj.z;

		return res;
	}

	/*
	* Subtracts 2 points/vectors
	*/
	Point3D operator-(const Point3D obj) const {
		Point3D res;
		res.x = x - obj.x;
		res.y = y - obj.y;
		res.z = z - obj.z;

		return res;
	}

	/*
	* Multiplies a point/vector with a scalar
	*/
	Point3D operator*(const float k) const {
		Point3D res;
		res.x = x * k;
		res.y = y * k;
		res.z = z * k;

		return res;
	}

	/*
	* Divides a point/vector with a scalar
	*/
	Point3D operator/(const float k) const {
		return *this * (1 / k);
	}

	/*
	* Dot product between 2 points/vectors
	*/
	float operator*(const Point3D obj) const {
		return x * obj.x + y * obj.y + z * obj.z;
	}

	/*
	* Angle between 2 vectors
	*/
	float angle(const Point3D obj) const {
		return acos((*this * obj) / (this->magnitude() * obj.magnitude()));
	}

	/*
	* Magnitude of a vector (length)
	*/
	float magnitude() const {
		return float(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
	}

	/*
	* Retrieve a point/vector normalized to magnitude 1
	*/
	Point3D normalize() const {
		return *this / this->magnitude();
	}

	ostream& operator<< (ostream& os) const {
		return (os << "{" << x << "," << y << "," << z << "}");
	}
};