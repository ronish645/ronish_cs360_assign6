#include <iostream>
#include "complex.h"

int main() {
    Complex x;
    Complex y(4.3, 8.2);
    Complex z(3.3, 1.1);

    // Addition
    x = y + z;
    std::cout << "x = y + z: " << x << std::endl;
    std::cout << "= " << y << " + " << z << std::endl;

    // Subtraction
    x = y - z;
    std::cout << "\n";
    std::cout << "x = y - z: " << x << std::endl;
    std::cout << "= " << y << " - " << z << std::endl;

    // Multiplication
    Complex product = y * z;
    std::cout << "\n";
    std::cout << "Product of y and z: " << product << std::endl;

    // Comparison
    std::cout << "\n";
    if (y == z) {
        std::cout << "y is equal to z" << std::endl;
    } else {
        std::cout << "y is not equal to z" << std::endl;
    }

    return 0;
}