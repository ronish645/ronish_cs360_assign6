// HugeInt member-function and friend-function definitions.
#include <cctype> // isdigit function prototype
#include "HugeInt.h" // HugeInt class definition
using namespace std;

// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
HugeInt::HugeInt(long value) {
    // initialize array to zero
    for (short& element : integer)
        element = 0;

    // place digits of argument into array
    for (size_t j = digits - 1; value != 0 && j >= 0; j--) {
        integer[j] = value % 10;
        value /= 10;
    }
} // end HugeInt default/conversion constructor

// conversion constructor that converts a character string
// representing a large integer into a HugeInt object
HugeInt::HugeInt(const string& number) {
    // initialize array to zero
    for (short& element : integer)
        element = 0;

    // place digits of argument into array
    size_t length = number.size();
    for (size_t j = digits - length, k = 0; j < digits; ++j, ++k)
        if (isdigit(number[k])) // ensure that character is a digit
            integer[j] = number[k] - '0';
} // end HugeInt conversion constructor

// addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+(const HugeInt& op2) const {
    HugeInt temp; // temporary result
    int carry = 0;
    for (int i = digits - 1; i >= 0; i--) {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;
        // determine whether to carry a 1
        if (temp.integer[i] > 9) {
            temp.integer[i] %= 10; // reduce to 0-9
            carry = 1;
        } else // no carry
            carry = 0;
    }
    return temp; // return copy of temporary object
} // end function operator+

// addition operator; HugeInt + int
HugeInt HugeInt::operator+(int op2) const {
    // convert op2 to a HugeInt, then invoke
    // operator+ for two HugeInt objects
    return *this + HugeInt(op2);
} // end function operator+

// addition operator;
// HugeInt + string that represents large integer value
HugeInt HugeInt::operator+(const string& op2) const {
    // convert op2 to a HugeInt, then invoke
    // operator+ for two HugeInt objects
    return *this + HugeInt(op2);
} // end operator+

// overloaded output operator
ostream& operator<<(ostream& output, const HugeInt& num) {
    int i;
    for (i = 0; (i < HugeInt::digits) && (0 == num.integer[i]); ++i)
        ; // skip leading zeros
    if (i == HugeInt::digits)
        output << 0;
    else
        for (; i < HugeInt::digits; ++i)
            output << num.integer[i];
    return output;
} // end function operator<<
