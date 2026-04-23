#include "Triangle.h"
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

// constructor, base, height > 0
Triangle::Triangle(double b, double h) {
    if (b > 0) {
        base = b;
    } else {
        base = 1;
    }

    if (h > 0) {
        height = h;
    } else {
        height = 1;
    }
}

// area = 0.5*base*height
double Triangle::area() const {
    return 0.5 * base * height;
}

// perimeter base + height + sqrt(base^2 + height^2)
double Triangle::perimeter() const {
    return base + height + std::sqrt(base * base + height * height);
}

// scales base and height
void Triangle::scale(double factor) {
    base *= factor;
    height *= factor;
}

// returns formatted description string
string Triangle::describe() const {
    ostringstream out;
    out << fixed << setprecision(2);
    out << "Triangle: base=" << base
        << " height=" << height
        << " area=" << area()
        << " perimeter=" << perimeter();
    return out.str();
}
