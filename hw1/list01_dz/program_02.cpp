// Calculating the position of the stone

#include <iostream>
#include <cmath>
using namespace std;


int main() {
    double g, h, v, a, t, x, y;
    g = 9.8;

    cout << "Enter h: ";
    cin >> h;

    cout << "Enter v: ";
    cin >> v;

    cout << "Enter a (in radians): ";
    cin >> a;

    // There is no need to check the full radical expression, since the user will definitely not enter negative values.
    if (pow(v, 2) * pow(sin(a), 2) == 0) {
        cout << "It's impossible to calculate T" << endl;
        return 1;
    }

    t = v * sin(a) / g * (1 + sqrt(1 + 2 * g * h / (pow(v, 2) * pow(sin(a), 2))));
    cout << "Stone flight time: " << t << endl;

    x = v * t * cos(a);
    cout << "Distance from cliff edge:" << x << endl;

    y = h + v * t * sin(a) - 1/2 * g * pow(t, 2);
    cout << "Height from cliff bottom: " << y << endl;

    return 0;
}