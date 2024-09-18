#include <iostream>
#include <cmath>
using namespace std;


int main() {
    double a, k, w, p, t, max_x;

    cout << "Enter amplitude of oscillations: ";
    cin >> a;
    
    cout << "Enter k: ";
    cin >> k;

    cout << "Enter cyclic frequency: ";
    cin >> w;

    p = asin(1 / k);
    cout << "The value of initial phase of oscillations is " << p << ".\n";
    t = (M_PI / 2 - p) / w;
    cout << "The value of T is " << t << ".\n";

    max_x = a * sin(w * t + p);
    cout << "Maximum x is " << max_x << ".\n";

    return 0;
}