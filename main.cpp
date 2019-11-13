#include <iostream>
#include "variadic_templates.h"
#include "explicit.h"
#include "lambdas.h"

int main() {
    print(7.5, "dd", std::bitset<2>(3), 42);
//    print(7.5);
    Complex c1(12,5);
    Complex c2 = c1 + 5;
    l();
    test_lambda();
    std::cout << maximum(20,30,50,100,33,55) << std::endl;
    std::cout << std::make_tuple(7.5, "dd", std::bitset<8>(109), 42) << std::endl;
    return 0;
}

