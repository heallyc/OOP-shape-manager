#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <string>

// triangle derived class
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    // constructor, dimensions > 0
    Triangle(double b, double h);

    // overrides of shape interface
    double area() const override;
    double perimeter() const override;
    void scale(double factor) override;
    std::string describe() const override;
};

#endif
