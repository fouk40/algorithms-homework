#include <iostream>
#include <cmath>
using namespace std;


int main() {
    double x, g, f;

    cout << "Enter x: ";
    cin >> x;

    if (x > -4 && x < - 1) {
        g = abs(x + 6) / (abs(x + 3) - 3);
    } else if (x > -1 && x < 5) {
        g = sqrt(5 - x) - 2;
    } else if (x >= 5) {
        g = log(x + 10) - 2;
    } else {
        cout << "Impossible to calculate - the values are out of domain." << endl;
        return 1;
    }
    cout << "The value of g(x): " << g << endl;

    if (g < -2) {
        f = abs(x / (1 - x));
    } else if (x >= -2 && x <= 1) {
        f = pow(x + 2, 2);
    } else {
        cout << "Impossible to calculate - the values are out of domain." << endl;
        return 1;
    }
    cout << "The value of f(g(x)): " << f << endl;
    
    return 0;
}