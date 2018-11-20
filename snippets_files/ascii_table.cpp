#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool printChar(unsigned char start, unsigned char end) {
    if (start > end)
        return false;

    for (unsigned char i = start; i <= end; ++i) {
        cout << i << " ";
    }

    return true;
}

int main() {
    unsigned char firstChar = '\x00',
                  lastChar  = '\x7F';

    cout << "[" << firstChar << " - " << lastChar << "]: ";

    if (!printChar(firstChar, lastChar))
        cout << "failure";

    return EXIT_SUCCESS;
}