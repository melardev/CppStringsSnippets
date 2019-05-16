#ifndef OSTRINGSTREAM_DEMO_H
#define OSTRINGSTREAM_DEMO_H

#include <sstream>
#include <iostream>

/// std::ostringstream is really useful, it is used widely in serialization frameworks
/// this script only illustrates the basics, for more demos and usages, you can look at my applications
/// on Github, I used it a lot, mainly with Boost serialization and
/// Cereal Cpp which is also a serialization framework, I have two Github repositories, I have a snippets Github
/// Repo for each of one of these two
namespace OStringStreamUsage {
    int main() {

        std::ostringstream stringStream;
        stringStream << "Hello ";
        stringStream << "OutputStringStream"
                     << " Demo.\nYou can save not only strings but also other data types such as\n"
                     << "Boolean: " << true << std::endl
                     << "Integers: " << 23 << std::endl
                     << "Floats : " << 20.f << std::endl
                     << "Unsigned long long:" << (uint64_t) 100 << std::endl
                     << L" wide strings are also supported how cool is that";

        // Let's retrieve everything as str
        std::string serializedStr = stringStream.str();

        // Notice the L" wide strings" which is unicode text has not been printed, can you gess why?
        // I explain that in sstream_to_wstring snippet :)
        std::cout << "Serialized content:" << std::endl
                  << serializedStr << std::endl;
    }
}
#endif //OSTRINGSTREAM_DEMO_H
