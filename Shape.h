#ifndef SHAPE_H
#define SHAPE_H

#include <string>

// base class for all shapes
class Shape {
public:
    // destructor for base pointer
    virtual ~Shape() {}

    // pure virtual functions
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    // scales the dimensions by factor
    virtual void scale(double factor) = 0;

    // returns formatted description string
    virtual std::string describe() const = 0;
};

#endif
