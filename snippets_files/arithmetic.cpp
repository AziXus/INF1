#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <limits>

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define EMPTY_BUFFER_SPACE cin.ignore(numeric_limits<streamsize>::max(), ' ')

using namespace std;

double withdraw(double& balance, double amount) {
    double effectiveAmount = amount;
    if (effectiveAmount > balance) {
        effectiveAmount = balance;
    } else if (balance < 0) {
        effectiveAmount = 0;
    }

    balance -= effectiveAmount;

    return effectiveAmount;
}

bool arithmeticOperation(double x, double y, char customOperator, double& res) {
    switch (customOperator) {
        case '+': res = x + y; break;
        case '-': res = x - y; break;
        case '*': res = x * y; break;
        case '/': res = x / y; break;
        default : res = 0.;     return false;
    }

    return true;
}

int main() {
    double x, y, res;
    char   arithmeticOperator;

    cout << setprecision(2) << fixed;
    cout << "Please enter a calculation (x [+ - * /] y) on the same line and press enter: ";
    cin >> x;
    EMPTY_BUFFER_SPACE;
    cin >> arithmeticOperator;
    EMPTY_BUFFER_SPACE;
    cin >> y;
    EMPTY_BUFFER;

    if (arithmeticOperation(x, y, arithmeticOperator, res))
        cout << x << " " << arithmeticOperator << " " << y << " = " << res;
    else
        cout << "Invalid operator.";

    return EXIT_SUCCESS;
}