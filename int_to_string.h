
#ifndef INT_TO_STRING_H
#define INT_TO_STRING_H

#include <string>
#include <sstream>
#include <iostream>

namespace IntToString {

    int main() {
        int i = 123456789;
        std::string intConverted;
        std::stringstream ss;
        ss << i;
        intConverted = ss.str();

        std::cout << intConverted << std::endl;
    }
}
#endif //INT_TO_STRING_H
