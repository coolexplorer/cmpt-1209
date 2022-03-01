#include <iostream>
#include "Integer.h"

int main() {
    Integer x(16), y;
    Integer z = -x;
    y = +x;

    std::cout << "Prefix: " << (++x).getValue() << " Postfix: " << (x++).getValue() << std::endl;
    std::cout << x.getValue() << std::endl;
    std::cout << z.getValue() << std::endl;
    std::cout << x.getValue() << '\t' << y.getValue() << '\t' << z.getValue() << std::endl;

    std::cout << (x < y) << std::endl;
    std::cout << (x + y).getValue() << std::endl;

    int w = 8;
    z = static_cast<Integer>(w);
    w = static_cast<int>(z);

    std::cout << z.getValue() << std::endl;
    std::cout << w << std::endl;

    // memberwize assignment
    x = y;

    x = x + 1.0;
    std::cout << "x + 1 :" << x.getValue() << std::endl;

    // operator (op)
    // 1. unary : !
    // 2. binary : +, - ...
    // 3. trinary : ? :

    return 0;
}