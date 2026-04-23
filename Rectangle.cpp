#include "Rectangle.h"
#include <sstream>
#include <iomanip>
using namespace std;

// constructor, width, height > 0
Rectangle::Rectangle(double w, double h) {
    if (w > 0) {
        width = w;
    } else {
        width = 1;
    }

    if (h > 0) {
        height = h;
    } else {
        height = 1;
    }
}

// area = width * height
double Rectangle::area() const {
    return width * height;
}

// perimeter = 2(width + height)
double Rectangle::perimeter() const {
    return 2 * (width + height);
}


// scales both dimensions by factor
void Rectangle::scale(double factor) {
    width *= factor;
    height *= factor;
}

// returns formatted description string
string Rectangle::describe() const {
    ostringstream out;
    out << fixed << setprecision(2);
    out << "Rectangle: width=" << width
        << " height=" << height
        << " area=" << area()
        << " perimeter=" << perimeter();
    return out.str();
}
