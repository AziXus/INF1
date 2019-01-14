#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <limits>

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

unsigned int recursiveSum(unsigned int n);

int main() {
    cout << recursiveSum(5);

    cout << "\nPress ENTER to quit\n";
    EMPTY_BUFFER;

    return EXIT_SUCCESS;
}

unsigned int recursiveSum(unsigned int n) {
    if (n == 0)
        return 0;
    else {
        return n + recursiveSum(n - 1);
    }
}