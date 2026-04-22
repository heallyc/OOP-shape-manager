#include <iostream>
#include <string>
#include <sstream>
#include <limits>

#include "ShapeManager.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;

// parse an integer from a line, returns true if integer 
static bool parseInt(const string& line, int& value) {
    istringstream iss(line);
    iss >> value;
    if (!iss.fail() && iss.eof()) return true;
    return false;
}

// parse a double from a line, returns true if double 
static bool parseDouble(const string& line, double& value) {
    istringstream iss(line);
    iss >> value;
    if (!iss.fail() && iss.eof()) return true;
    return false;
}

// print the menu 
static void printMenu() {
    cout << "Shape Catalog\n";
    cout << "1. Add Shape\n";
    cout << "2. List All Shapes\n";
    cout << "3. Scale All Shapes\n";
    cout << "4. Describe All\n";
    cout << "5. Exit\n";
}

// read menu choicem if invalid prints error message and returns false.
static bool readMenuChoice(int &choice) {
    string line;
    cout << "Enter choice: ";
    if (!getline(cin, line)) return false; //error handling
    if (!parseInt(line, choice)) {
        cout << "Invalid choice.\n";
        return false;
    }
    if (choice < 1 || choice > 5) {
        cout << "Invalid choice.\n";
        return false;
    }
    return true;
}

// read shape type when adding a new shape, makes sure input is valid, if not prints error
static int readShapeType() {
    while (true) {
        string line;
        cout << "Enter shape type (1=Circle, 2=Rectangle, 3=Triangle): ";
        if (!getline(cin, line)) return 0; 
        int t;
        if (!parseInt(line, t) || (t < 1 || t > 3)) {
            cout << "Invalid choice.\n";
            continue;
        }
        return t;
    }
}

// reads dimensions, if non-numeric or non-positive, prints error; if valid returns the double
static double readPositiveDimension(const string& prompt) {
    while (true) {
        string line;
        cout << prompt;
        if (!getline(cin, line)) return 1.0; 
        double val;
        if (!parseDouble(line, val)) {
            cout << "Invalid input.\n";
            continue;
        }
        if (!(val > 0.0)) {
            cout << "Error: Dimension must be greater than 0.\n";
            continue;
        }
        return val;
    }
}

// read scale factor, if non-numeric or non-positive prints error and reprompts
static double readScaleFactor() {
    while (true) {
        string line;
        cout << "Enter scale factor: ";
        if (!getline(cin, line)) return 1.0; // EOF fallback
        double val;
        if (!parseDouble(line, val)) {
            cout << "Invalid input.\n";
            continue;
        }
        if (!(val > 0.0)) {
            cout << "Error: Scale factor must be greater than 0.\n";
            continue;
        }
        return val;
    }
}

int main() {
    ShapeManager manager;

    while (true) {
        printMenu();

        int choice;
        // keep re-displaying menu until user gives valid choice
        if (!readMenuChoice(choice)) {
            continue;
        }

        if (choice == 1) { // add Shape
            int shapeType = readShapeType();
            if (shapeType == 1) { // run all circle functions
                double r = readPositiveDimension("Enter radius: ");
                manager.addShape(new Circle(r));
                cout << "Shape added.\n\n";
            } else if (shapeType == 2) { // run all rectangle functions
                double w = readPositiveDimension("Enter width: ");
                double h = readPositiveDimension("Enter height: ");
                manager.addShape(new Rectangle(w, h));
                cout << "Shape added.\n\n";
            } else if (shapeType == 3) { // run all triangle functions
                double b = readPositiveDimension("Enter base: ");
                double h = readPositiveDimension("Enter height: ");
                manager.addShape(new Triangle(b, h));
                cout << "Shape added.\n\n";
            }
        } else if (choice == 2) { // list all shapes
            manager.viewAll();
        } else if (choice == 3) { // scale all shapes
            double factor = readScaleFactor();
            manager.scaleAll(factor);
            cout << "All shapes scaled.\n\n";
        } else if (choice == 4) { // describe all
            manager.describeAll();
        } else if (choice == 5) { // exit
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}
