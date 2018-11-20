#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n;

    cout << "Please enter a number >= 0: ";
    cin  >> n;

    if (n % 3 == 0 and n % 5 == 0)
        cout << n << " is a multiple of 3 and of 5";
    else if (n % 3 == 0)
        cout << n << " is a multiple of 3";
    else if (n % 5 == 0)
        cout << n << " is a multiple of 5";
    else
        cout << n << " is not a multiple of 3 or 5";

    cout << "\nPress ENTER to quit\n";
    cin.ignore();
    cin.get();

    return EXIT_SUCCESS;
}