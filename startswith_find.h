
#ifndef STARTSWITH_FIND_H
#define STARTSWITH_FIND_H

#include <string>
#include <algorithm>

#include <iostream>
#include <string>
#include <algorithm>

namespace StringStartsWith {


    bool startsWith(const std::string &text, const std::string &prefix) {
        // std::string::find returns index of first occurrence, the beginning would be 0
        return text.find(prefix) == 0;
    }

    // Receive a copy, not a reference, because we are gonna change them
    bool startsWithCaseInsensitive(std::string text, std::string prefix) {
        // Convert both to lower case, you could do it to uppercase as well with ::toupper
        std::transform(text.begin(), text.end(), text.begin(), ::tolower);
        std::transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower);
        return text.find(prefix) == 0;
    }

    int main() {
        std::string text = "C++ is a very powerful programming language";
        std::string prefix = "c++";

        // Enable printing true or false instead of 1 or 0
        std::cout << std::boolalpha;

        bool result = startsWith(text, prefix);
        std::cout << "Results for\n" << text << "\nDoes it start with '" << prefix << "' ?" << std::endl;
        std::cout << "Starts with " << prefix << " ?\t\t" << result << std::endl;

        result = startsWithCaseInsensitive(prefix, prefix);
        std::cout << "Starts(Insensitive) with " << prefix << " ? " << result << std::endl;
    }
}
#endif //STARTSWITH_FIND_H
