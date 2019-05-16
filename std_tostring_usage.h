
#ifndef STD_TOSTRING_USAGE_H
#define STD_TOSTRING_USAGE_H

#include <iostream>
#include<string>

namespace StdToStringUsage {
    int main() {
        // to_string is a really useful function, I know this snippet is dummy
        // But to_string has many cool uses
        // I use it in many algorithm snippets

        std::cout << std::to_string(20.0f) << std::endl; // float
        std::cout << std::to_string(10.0) << std::endl; // double
        std::cout << std::to_string(50) << std::endl; // int
        std::cout << std::to_string(true) << std::endl; // gets converted to int first, be aware!!!
        std::cout << std::to_string((int16_t) 23) << std::endl; // gets converted to int first, be aware!!!
    }
}

#endif //STD_TOSTRING_USAGE_H
