#ifndef STR_ENDSWITH_COMPARE_H
#define STR_ENDSWITH_COMPARE_H

#include <string>
#include <iostream>

namespace StrEndsWithCompare {

    bool endsWith(const std::string &text, const std::string &suffix) {
        // The size check is great for performance, we don't have to go through
        // the whole strings char by char if we know the lengths
        // are different

        return text.size() >= suffix.size()
               &&
               // Compare from the end(the last suffix.size() characters)
               // compare returns 0 if the strings match
               text.compare(text.size() - suffix.size(),
                            suffix.size(),
                            suffix)
               == 0;
    }

    // Receive a copy, not a reference, because we are gonna change them
    bool endsWithInsensitive(std::string text, std::string suffix) {
        // Convert both to lower case, you could do it to uppercase as well with ::toupper
        std::transform(text.begin(), text.end(), text.begin(), ::tolower);
        std::transform(suffix.begin(), suffix.end(), suffix.begin(), ::tolower);

        return text.size() >= suffix.size()
               &&
               // Compare from the end(the last suffix.size() characters)
               // compare returns 0 if the strings match
               text.compare(text.size() - suffix.size(),
                            suffix.size(),
                            suffix)
               == 0;
    }

    int main() {
        std::string text = "Cpp C++ Cxx I see plus plus everywhere, again C++";
        std::string suffix = "c++";
        bool result = endsWith(text, suffix);

        std::cout << std::boolalpha; // Enable print true and false

        std::cout << "Results for text:" << std::endl;
        std::cout << text << std::endl;
        std::cout << "Suffix " << suffix << std::endl;
        std::cout << "Ends with result " << result << std::endl << std::endl;

        result = endsWithInsensitive(text, suffix);
        std::cout << "Results for text:" << std::endl;
        std::cout << text << std::endl;
        std::cout << "Suffix " << suffix << std::endl;
        std::cout << "Ends with(Insensitive) result " << result << std::endl;


        return 0;
    }
}
#endif //STR_ENDSWITH_COMPARE_H
