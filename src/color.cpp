#include "../include/color.h"

Color::Color() : r(0), g(0), b(0) {}
Color::Color(int r, int g, int b): r(r), g(g), b(b) {}

Color Color::operator+(Color const & obj) const {
    Color res;
    res.r = std::clamp(r + obj.r, 0, 255);
    res.g = std::clamp(g + obj.g, 0, 255);
    res.b = std::clamp(b + obj.b, 0, 255);

    return res;
}

Color Color::operator-(Color const & obj) const {
    Color res;
    res.r = std::clamp(r - obj.r, 0, 255);
    res.g = std::clamp(g - obj.g, 0, 255);
    res.b = std::clamp(b - obj.b, 0, 255);

    return res;
}

Color Color::operator*(const float k) const {
    Color res;
    res.r = std::clamp(int(k * r), 0, 255);
    res.g = std::clamp(int(k * g), 0, 255);
    res.b = std::clamp(int(k * b), 0, 255);

    return res;
}

Color Color::operator/(const float k) const {
    Color res;
    res.r = std::clamp(int(r / k), 0, 255);
    res.g = std::clamp(int(g / k), 0, 255);
    res.b = std::clamp(int(b / k), 0, 255);

    return res;
}

std::ostream& operator<<(std::ostream& os, Color const& color){
    os << "R: " << color.r << " G: " << color.g << " B: " << color.b;
    return os;
}
