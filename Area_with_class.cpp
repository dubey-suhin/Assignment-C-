#include <iostream>
#include <cmath>

using namespace std;

class AREA {
public:
    // Function to calculate the area of a rectangle
    double calculate(double length, double width) {
        return length * width;
    }

    // Function to calculate the area of a triangle
    double calculate(double base, double height, char type) {
        return 0.5 * base * height;
    }

    // Function to calculate the area of a circle
    double calculate(double radius) {
        return M_PI * radius * radius;
    }
};

int main() {
    AREA area;
    double length, width, base, height, radius;

    // Calculating the area of a rectangle
    cout << "Enter length and width of the rectangle: ";
    cin >> length >> width;
    cout << "Area of Rectangle: " << area.calculate(length, width) << endl;

    // Calculating the area of a triangle
    cout << "Enter base and height of the triangle: ";
    cin >> base >> height;
    cout << "Area of Triangle: " << area.calculate(base, height, 'T') << endl;

    // Calculating the area of a circle
    cout << "Enter radius of the circle: ";
    cin >> radius;
    cout << "Area of Circle: " << area.calculate(radius) << endl;

    return 0;
}
