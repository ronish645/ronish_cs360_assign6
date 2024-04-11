#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
public:
    explicit Complex(double real = 0.0, double imaginary = 0.0); // constructor
    Complex operator+(const Complex& other) const; // addition
    Complex operator-(const Complex& other) const; // subtraction
    Complex operator*(const Complex& other) const; // multiplication
    bool operator==(const Complex& other) const; // equality
    bool operator!=(const Complex& other) const; // inequality

    // Overloaded stream insertion and extraction operators
  friend std::ostream& operator<<(std::ostream& out, const Complex& c);
  friend std::istream& operator>>(std::istream& in, Complex& c);

private:
    double real; // real part
    double imaginary; // imaginary part
};

#endif