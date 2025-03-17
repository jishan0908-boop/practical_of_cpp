#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Triangle {
private:
    double a, b, c;

public:
    // Constructor with validation
    Triangle(double side1, double side2, double side3) {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0)
            throw invalid_argument("Sides must be greater than zero.");
        if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
            throw invalid_argument("Sum of any two sides must be greater than the third side.");

        a = side1;
        b = side2;
        c = side3;
    }

    // Function to calculate area using Heron's formula
    double calculateArea() {
        double s = (a + b + c) / 2; // Semi-perimeter
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    // Overloaded function to calculate area of a right-angled triangle
    static double calculateArea(double base, double height) {
        if (base <= 0 || height <= 0)
            throw invalid_argument("Base and height must be greater than zero.");
        return 0.5 * base * height;
    }

    // Display function
    void display() {
        cout << "Triangle sides: " << a << ", " << b << ", " << c << endl;
        cout << "Area using Heron's formula: " << calculateArea() << endl;
    }
};

int main() {
    try {
        // User input for any triangle
        double x, y, z;
        cout << "Enter three sides of the triangle: ";
        cin >> x >> y >> z;

        Triangle t(x, y, z);
        t.display();

        // User input for right-angled triangle
        double base, height;
        cout << "\nEnter base and height of right-angled triangle: ";
        cin >> base >> height;

        cout << "Area of right-angled triangle: " << Triangle::calculateArea(base, height) << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}