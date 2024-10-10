// Calculating the time when the pendulum deflection is maximum

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

    if (w == 0) {
        cout << "It's impossible to calculate the value of T" << endl;
        return 1;
    }

    p = asin(1 / k);
    cout << "The value of initial phase of oscillations is " << p << endl;
    t = (M_PI / 2 - p) / w;
    cout << "The value of T is " << t << endl;

    max_x = a * sin(w * t + p);
    cout << "Maximum x is " << max_x << endl;

    return 0;
}