// HugeInt test program.
#include <iostream>
#include "HugeInt.h"
using namespace std;

int main(void) {
    HugeInt n1(7654321);
    HugeInt n2(7891234);
    HugeInt n3("99999999999999999999999999999");
    HugeInt n4("1");
    HugeInt n5;
    cout << "n1 is " << n1 << "\nn2 is " << n2
         << "\nn3 is " << n3 << "\nn4 is " << n4
         << "\nn5 is " << n5 << "\n\n";
    n5 = n1 + n2;
    cout << n1 << " + " << n2 << " = " << n5 << "\n\n";
    cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";
    n5 = n1 + 9;
    cout << n1 << " + " << 9 << " = " << n5 << "\n\n";
    n5 = n2 + "10000";
    cout << n2 << " + " << "10000" << " = " << n5 << endl;
    return 0;
}
