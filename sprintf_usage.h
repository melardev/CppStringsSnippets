
#ifndef SPRINTF_USAGE_H
#define SPRINTF_USAGE_H

#include <cstdio>

namespace SprintfUsage {
    int main() {
        char buffer[100];
        int bytesWritten;
        bool boolValue = false;
        int intValue = 30;
        bytesWritten = sprintf(buffer, "Random string with intValue=%d and boolValue=%d", intValue, boolValue);

        printf("buffer is a string %d bytes long\n", bytesWritten);
        printf("Contents of the buffer:\n%s\n", buffer);
        return 0;
    }
}

#endif //SPRINTF_USAGE_H
