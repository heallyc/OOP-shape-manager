#include "ShapeManager.h"
#include <iostream>
using namespace std;

// adds a shape pointer to vector
void ShapeManager::addShape(Shape* s) {
    shapes.push_back(s);
}

// lists all shapes, if none prints no shapes
void ShapeManager::viewAll() const {
    if (shapes.empty()) {
        cout << "No shapes.\n\n";
        return;
    }

    for (const auto& shape : shapes) {
        cout << shape->describe() << "\n";
    }
    cout << "\n";
}

// scales every stored shape
void ShapeManager::scaleAll(double factor) {
    for (auto& shape : shapes) {
        shape->scale(factor);
    }
}

// prints descriptions of all shapes, if empty prints blank line
void ShapeManager::describeAll() const {
    if (shapes.empty()) {
        cout << "\n";
        return;
    }

    for (const auto& shape : shapes) {
        cout << shape->describe() << "\n";
    }
    cout << "\n";
}

// destructor deletes all shapes
ShapeManager::~ShapeManager() {
    for (auto& shape : shapes) {
        delete shape;
    }
}
