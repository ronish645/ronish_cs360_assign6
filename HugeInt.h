// HugeInt class definition.
#ifndef HUGEINT_H
#define HUGEINT_H

#include <array>
#include <iostream>
#include <string>

class HugeInt {
    friend std::ostream& operator<<(std::ostream&, const HugeInt&);

public:
    static const int digits = 30; // maximum digits in a HugeInt
    HugeInt(long = 0); // conversion/default constructor
    HugeInt(const std::string&); // conversion constructor
    // addition operator; HugeInt + HugeInt
    HugeInt operator+(const HugeInt&) const;
    // addition operator; HugeInt + int
    HugeInt operator+(int) const;
    // addition operator;
    // HugeInt + string that represents large integer value
    HugeInt operator+(const std::string&) const;

private:
    std::array<short, digits> integer;
};

#endif
