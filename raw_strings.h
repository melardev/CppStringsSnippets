
#ifndef RAW_STRINGS_H
#define RAW_STRINGS_H

#include <string>
#include <iostream>

namespace RawStrings {
    void main() {
        std::string calcPath = R"(C:\Windows\System32\calc.exe)";
        std::cout << calcPath << std::endl;
    }
}
#endif //RAW_STRINGS_H
