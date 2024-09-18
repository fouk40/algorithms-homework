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

    t = v * sin(a) / g * (1 + sqrt(1 + 2 * g * h / (pow(v, 2) * pow(sin(a), 2))));
    cout << "Stone flight time: " << t << endl;

    x = v * t * cos(a);
    cout << "Height from cliff bottom: " << x << endl;

    y = h + v * t * sin(a) - 1/2 * g * pow(t, 2);
    cout << "Distance from cliff edge: " << y << endl;

    return 0;
}