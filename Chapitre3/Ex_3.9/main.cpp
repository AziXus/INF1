#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int a, b, c, max, min, mid, tmp;

    cout << "Please enter 3 numbers on the same line: ";
    cin  >> a >> b >> c;

    max = std::max(a, std::max(b, c));
    min = std::min(a, std::min(b, c));
    mid = std::max(std::min(a, b), std::min(b, c));
    
    cout << "max = " << max << endl;

    cout << "Sorted: " << min << " " << mid << " " << max;

    cout << "\nPress ENTER to quit\n";
    cin.ignore();
    cin.get();

    return EXIT_SUCCESS;
}
