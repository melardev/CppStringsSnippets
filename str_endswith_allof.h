#ifndef STR_ENDSWITH_ALLOF_H
#define STR_ENDSWITH_ALLOF_H

#include <iterator>
#include <string>
#include <algorithm>
#include <iostream>

namespace StrEndsWithAllOf {

    bool endsWith(const std::string &text, const std::string &suffix) {
        auto it = suffix.begin();
        return text.size() >= suffix.size() &&
               std::all_of(std::next(text.begin(), text.size() - suffix.size()), text.end(),
                           [&it](const char &c) {
                               return c == *(it++);
                           });
    }


    // We receive a copy, not a reference, because we change the strings inside the function
    bool endsWithInsensitive(std::string text, std::string suffix) {
        auto it = suffix.begin();
        return text.size() >= suffix.size() &&
               std::all_of(std::next(text.begin(), text.size() - suffix.size()), text.end(),
                           [&it](const char &c) {
                               return ::tolower(c) == ::tolower(*(it++));
                           });
    }

    bool endsWithInsensitive2(std::string text, std::string suffix) {
        return text.size() >= suffix.size() &&
               std::all_of(std::next(text.begin(), text.size() - suffix.size()), text.end(), ::tolower);
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



        result = endsWithInsensitive2(text, suffix);
        std::cout << "Results for text:" << std::endl;
        std::cout << text << std::endl;
        std::cout << "Suffix " << suffix << std::endl;
        std::cout << "Ends with(Insensitive) result " << result << std::endl;
    }
}
#endif //STR_ENDSWITH_ALLOF_H
