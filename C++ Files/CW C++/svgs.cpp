#include <iostream>
// Use cerr for error messages
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // FIX 1: Add a default constructor.
    // This is needed for the error case in the divide() method (return Complex();).
    Complex() : real(0), imag(0) {}

    // STYLE: Use a member initializer list. This is the preferred way to initialize members in C++.
    Complex(double r, double i) : real(r), imag(i) {}

    // Method to display the complex number
    void display() {
        if (imag >= 0) {
            cout << real << " + " << imag << "i" << endl;
        } else {
            // If imag is negative, -imag makes it positive for clean output
            cout << real << " - " << -imag << "i" << endl;
        }
    }

    // Addition
    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Subtraction
    Complex subtract(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Multiplication
    Complex multiply(const Complex& other) const {
        double new_real = (real * other.real) - (imag * other.imag);
        double new_imag = (real * other.imag) + (imag * other.real);
        return Complex(new_real, new_imag);
    }

    // Division
    Complex divide(const Complex& other) const {
        double denominator = (other.real * other.real) + (other.imag * other.imag);

        if (denominator == 0) {
            cerr << "Error: Division by zero." << endl;
            // Now this call is valid because we defined Complex()
            return Complex(); 
        }

        double new_real = ((real * other.real) + (imag * other.imag)) / denominator;
        double new_imag = ((imag * other.real) - (real * other.imag)) / denominator;
        return Complex(new_real, new_imag);
    }
};

int main() {
    Complex c1(3, 2);
    Complex c2(1, -4);

    cout << "Complex Number 1: ";
    c1.display();
    cout << "Complex Number 2: ";
    c2.display();
    cout << "----------------------" << endl;

    Complex sum = c1.add(c2);
    cout << "Sum: ";
    sum.display();

    Complex diff = c1.subtract(c2);
    cout << "Difference: ";
    diff.display();

    Complex product = c1.multiply(c2);
    cout << "Product: ";
    product.display();

    Complex quotient = c1.divide(c2);
    cout << "Quotient: ";
    quotient.display();
    cout << "----------------------" << endl;

    return 0;
}