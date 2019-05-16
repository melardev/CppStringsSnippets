
#ifndef SNPRINTF_USAGE_H
#define SNPRINTF_USAGE_H

#include <cstdio>
#include <string>
#include <iostream>

namespace SnprintfUsage {
    int main() {
        char buffer[100];
        snprintf(buffer, sizeof(buffer), "%s", "I want a string into a variable");

        // Then we can also convert it to std::string
        std::string bufferString = buffer;
        std::cout << bufferString << std::endl;
    }
}

#endif //SNPRINTF_USAGE_H
