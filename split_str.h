#ifndef SPLIT_STR_H
#define SPLIT_STR_H

#include <string>
#include <iostream>
#include <vector>
#include <cassert>

namespace SplitString {

    // We take the string as a value(a copy will be made)
    // because we don't wanna change the original text
    std::vector<std::string> splitString(std::string text, const std::string &delimiter = " ") {
        std::vector<std::string> parts;
        size_t pos = 0;
        std::string token;

        // std::string::npos means nothing was found, so: until we find nothing
        // we keep finding the next token through substr
        bool foundAtLeastOne = false;
        while ((pos = text.find(delimiter)) != std::string::npos) {
            foundAtLeastOne = true;
            token = text.substr(0, pos);
            parts.push_back(token);
            text.erase(0, pos + delimiter.length());
        }

        // If we found at least one, then add the last bit(remaining)
        if (foundAtLeastOne)
            parts.push_back(text);
        return parts;
    }

    int main() {
        std::string text = "Melardev seems a cool guy";
        const std::vector<std::string> &parts = splitString(text);

        // Prove original text is unchanged
        std::cout << "Original text" << std::endl
                  << text << std::endl;

        for (const auto &part : parts) {
            std::cout << part << std::endl;
        }
    }
}
#endif //SPLIT_STR_H
