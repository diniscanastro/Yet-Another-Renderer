//
// Created by dinis on 14.06.2025.
//

#ifndef COLOR_H
#define COLOR_H

#include <algorithm>
#include <iostream>

class Color {
public:
    int r, g, b;
    Color();
    Color(int r, int g, int b);

    Color operator+(Color const & obj) const;
    Color operator-(Color const & obj) const;
    Color operator*(float k) const;
    Color operator/(float k) const;
};

std::ostream& operator<<(std::ostream& os, Color const& color);

#endif //COLOR_H
