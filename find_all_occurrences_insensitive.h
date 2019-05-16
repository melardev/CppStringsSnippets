
#ifndef FIND_ALL_OCCURRENCES_INSENSITIVE_H
#define FIND_ALL_OCCURRENCES_INSENSITIVE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

namespace FindAllOccurrencesCaseInsensitive {

    // Receive copies, not references, because we are gonna mutatet them
    size_t findCaseInsensitive(std::string wholeText, std::string searchedStr, size_t pos = 0) {
        // Convert to lower both strings
        std::transform(wholeText.begin(), wholeText.end(), wholeText.begin(), ::tolower);
        std::transform(searchedStr.begin(), searchedStr.end(), searchedStr.begin(), ::tolower);
        return wholeText.find(searchedStr, pos);
    }


    void findAllOccurrencesCaseInsensitive(std::vector<size_t> &foundPositions,
                                           std::string &text,
                                           std::string &searchedStr) {
        // Find first occurrence
        size_t pos = findCaseInsensitive(text, searchedStr);

        // While we find positions, we add them to the vector
        while (pos != std::string::npos) {
            foundPositions.push_back(pos);
            // search for the next occurrence
            pos = findCaseInsensitive(text, searchedStr, pos + searchedStr.size());
        }
    }

    int main() {
        std::string text = "This is a dummy string, we all love strings, Green Cpp, Red C.";
        std::vector<size_t> foundPositions;

        std::string searchedStr = "string";
        findAllOccurrencesCaseInsensitive(foundPositions, text, searchedStr);
        std::cout << "Occurrences of string:" << std::endl;

        size_t searchedStrLen = strlen(searchedStr.c_str());
        for (size_t pos : foundPositions) {
            assert(text.substr(pos, searchedStrLen) == "string");
            std::cout << "[" << pos << ", " << pos + searchedStrLen << "]" << std::endl;
        }
        return 0;
    }
}
#endif //FIND_ALL_OCCURRENCES_INSENSITIVE_H
