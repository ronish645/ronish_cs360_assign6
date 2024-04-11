// complex.cpp
#include <iostream>
#include "complex.h"

Complex::Complex(double realPart, double imaginaryPart) :
    real(realPart), imaginary(imaginaryPart) {}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imaginary - other.imaginary);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imaginary * other.imaginary,
                   real * other.imaginary + imaginary * other.real);
}

bool Complex::operator==(const Complex& other) const {
    return (real == other.real) && (imaginary == other.imaginary);
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << '(' << c.real << ", " << c.imaginary << "i)";
    return out;
}

std::istream& operator>>(std::istream& in, Complex& c) {
    char comma;
    in >> c.real >> comma >> c.imaginary; // Read real and imaginary parts
    in.ignore(); // Clear buffer
    return in;
}