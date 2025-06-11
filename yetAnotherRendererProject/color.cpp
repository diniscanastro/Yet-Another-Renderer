#include <iostream>
#include "helper.cpp"
using namespace std;

class Color {
public:
	int r;
	int g;
	int b;
	Color() : r(0), g(0), b(0) {}
	Color(int r, int g, int b): r(r), g(g), b(b) {}

	Color operator+(Color const* obj)
	{
		Color res;
		res.r = clamp(r + obj->r, 0, 255);
		res.g = clamp(g + obj->g, 0, 255);
		res.b = clamp(b + obj->b, 0, 255);

		return res;
	}

	Color operator*(float k)
	{
		Color res;
		res.r = clamp(int(k * r), 0, 255);
		res.g = clamp(int(k * g), 0, 255);
		res.b = clamp(int(k * b), 0, 255);

		return res;
	}

	ostream& operator<< (ostream& os) {
		return (os << "R: " << r << " G: " << g << " B: " << b);
	}
};