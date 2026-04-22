#ifndef SHAPEMANAGER_H
#define SHAPEMANAGER_H

#include "Shape.h"
#include <vector>
#include <string>

class ShapeManager {
private:
    std::vector<Shape*> shapes;

public:
    // adds shape to storage
    void addShape(Shape* s);

    // Lists all shapes
    void viewAll() const;

    // scales all stored shapes by factor
    void scaleAll(double factor);

    // describes each shape
    void describeAll() const;

    // destructor deletes allocated shapes
    ~ShapeManager();
};

#endif
