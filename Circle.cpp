#include "Circle.h"
#include <sstream>
#include <iomanip>
#include <cmath>

// constructor, r>0
Circle::Circle(double r) {
    if (r > 0) {
        radius = r;
    } else {
        radius = 1; //doesnt matter because validate in main
    }
}

// area = pi*r*r
double Circle::area() const {
#ifndef M_PI
    const double M_PI = 3.14159265358979323846;
#endif
    return M_PI * radius * radius;
}

// perimeter = 2*pi*r
double Circle::perimeter() const {
#ifndef M_PI
    const double M_PI = 3.14159265358979323846;
#endif
    return 2 * M_PI * radius;
}

// scales radius by positive factor
void Circle::scale(double factor) {
    radius *= factor;
}

// returns formatted description string
std::string Circle::describe() const {
    std::ostringstream out;
    out << std::fixed << std::setprecision(2);
    out << "Circle: radius=" << radius
        << " area=" << area()
        << " perimeter=" << perimeter();
    return out.str();
}
