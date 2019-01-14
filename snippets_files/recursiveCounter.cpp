#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <limits>

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int recursiveCounter(unsigned int start);

int main() {
    recursiveCounter(15);
    cout << "\nPress ENTER to quit\n";
    EMPTY_BUFFER;
}

void recursiveCounter(unsigned int start) {
    cout << start;

    if (start == 0)
        cout << endl;
    else {
        cout << "...";
        recursiveCounter(start - 1);
    }
}
