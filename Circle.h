#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <string>

// circle derived class
class Circle : public Shape {
private:
    double radius;

public:
    // constructor, radius > 0
    Circle(double r);

    // overrides of shape interface
    double area() const override;
    double perimeter() const override;
    void scale(double factor) override;
    std::string describe() const override;
};

#endif
