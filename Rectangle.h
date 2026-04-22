#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>

// rectangle derived class
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // constructor, dimensions > 0
    Rectangle(double w, double h);

    // overrides of shape interface
    double area() const override;
    double perimeter() const override;
    void scale(double factor) override;
    std::string describe() const override;
};

#endif
