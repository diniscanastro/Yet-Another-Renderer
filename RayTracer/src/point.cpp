//
// Created by dinis on 14.06.2025.
//

#include "../include/point.h"


Point2D::Point2D() : x(0.f), y(0.f) {}
Point2D::Point2D(double x, double y) : x(x), y(y) {}

bool Point2D::operator==(Point2D obj) const {
	return this->x == obj.x && this->y == obj.y;
}

Point2D Point2D::operator+(Point2D obj) const {
	Point2D res;
	res.x = x + obj.x;
	res.y = y + obj.y;

	return res;
}

Point2D Point2D::operator-(Point2D obj) const {
	Point2D res;
	res.x = x - obj.x;
	res.y = y - obj.y;

	return res;
}

Point2D Point2D::operator-() const {
	Point2D res;
	res.x = -x;
	res.y = -y;

	return res;
}

Point2D Point2D::operator/(const double k) const {
	return *this * (1/k);
}

Point2D Point2D::operator*(const double k) const {
	Point2D res;
	res.x = x * k;
	res.y = y * k;

	return res;
}

double Point2D::operator*(const Point2D obj) const {
	return x * obj.x + y * obj.y;
}

double Point2D::magnitude() const {
	return sqrt(pow(x, 2) + pow(y, 2));
}

double Point2D::angle(const Point2D obj) const {
	return acos((*this * obj) / (this->magnitude() * obj.magnitude()));
}

Point2D Point2D::normalize() const {
	return *this / this->magnitude();
}

std::ostream& operator<<(std::ostream& os, Point2D const& point){
	os << "{" << point.x << "," << point.y << "}";
	return os;
}


Point3D::Point3D() : x(0.f), y(0.f), z(0.f) {}
Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

bool Point3D::operator==(const Point3D obj) const {
	return this->x == obj.x && this->y == obj.y && this->z == obj.z;
}

Point3D Point3D::operator+(const Point3D obj) const {
	Point3D res;
	res.x = x + obj.x;
	res.y = y + obj.y;
	res.z = z + obj.z;

	return res;
}

Point3D Point3D::operator-(const Point3D obj) const {
	Point3D res;
	res.x = x - obj.x;
	res.y = y - obj.y;
	res.z = z - obj.z;

	return res;
}

Point3D Point3D::operator-() const {
	Point3D res;
	res.x = -x;
	res.y = -y;
	res.z = -z;

	return res;
}

Point3D Point3D::operator*(const double k) const {
	Point3D res;
	res.x = x * k;
	res.y = y * k;
	res.z = z * k;

	return res;
}

Point3D Point3D::operator/(const double k) const {
	return *this * (1 / k);
}

double Point3D::operator*(const Point3D obj) const {
	return x * obj.x + y * obj.y + z * obj.z;
}

double Point3D::angle(const Point3D obj) const {
	return acos((*this * obj) / (this->magnitude() * obj.magnitude()));
}

double Point3D::magnitude() const {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Point3D Point3D::normalize() const {
	return *this / this->magnitude();
}


std::ostream& operator<<(std::ostream& os, Point3D const& point){
	os << "{" << point.x << "," << point.y << "," << point.z << "}";
	return os;
}