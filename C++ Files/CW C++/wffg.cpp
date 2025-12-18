#include <iostream>
#include <iomanip>

using namespace std;

class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual void displayArea() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
    static constexpr double PI = 3.14159265358979323846;
public:
    explicit Circle(double r) : radius(r) {}
    double calculateArea() const override { return PI * radius * radius; }
    void displayArea() const override {
        cout << fixed << setprecision(6)
             << "Circle: radius = " << radius
             << ", area = " << calculateArea() << '\n';
    }
};

class Rectangle : public Shape {
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() const override { return width * height; }
    void displayArea() const override {
        cout << fixed << setprecision(6)
             << "Rectangle: width = " << width
             << ", height = " << height
             << ", area = " << calculateArea() << '\n';
    }
};

int main() {
    double r, w, h;
    cout << "Enter circle radius: ";
    if (!(cin >> r) || r < 0) {
        cerr << "Invalid radius.\n";
        return 1;
    }

    cout << "Enter rectangle width and height: ";
    if (!(cin >> w >> h) || w < 0 || h < 0) {
        cerr << "Invalid rectangle dimensions.\n";
        return 1;
    }

    Circle c(r);
    Rectangle rect(w, h);

    c.displayArea();
    rect.displayArea();

    return 0;
}