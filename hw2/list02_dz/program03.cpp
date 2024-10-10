/*
    Calculating the Maclaurin series
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int opt, n;
    long double x, last_term, result;
    char cont;
    do {
        // print the menu of options
        cout << "Select an option from 1 to 6 according to the menu:" << endl;
        cout << "[1]. Enter the value of x to be evaluated in the function and the number of terms for the MacLaurin series." << endl;
        cout << "[2]. Calculate the Maclaurin series for the exponential function (e^x)" << endl;
        cout << "[3]. Calculate the Maclaurin series for the natural logarithm function (ln(1 + x)):" << endl;
        cout << "[4]. Calculate the Maclaurin series for the sinusoidal function (sin(x)):" << endl;
        cout << "[5]. Calculate the Maclaurin series for the cosine function (cos(x))" << endl;
        cout << "[6]. Calculate the Maclaurin series for a rational function" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "Enter option: ";
        cin >> opt;

        switch (opt) {
            case 1: // OPTION 01: Enter the value of x and n
                cout << "Enter the value of x: ";
                cin >> x;
                do {
                    cout << "Enter the number of terms: ";
                    cin >> n;
                } while (n < 2 || n > 20);
                break;

            case 2: // OPTION 02: Maclaurin series for e^x
                // term and taylor result when i = 0
                last_term = 1;
                result = last_term;

                // cycle to find each term of taylor serie
                cout << "Serie terms:" << endl;
                for (int i = 1; i <= n; i++) {
                    last_term *= x / i;
                    cout << last_term << " ";
                    result += last_term;
                }
                cout << "\nFinal result: " << endl;
                cout << "e^" << x << " = " << result << endl;
                break;

            case 3: // OPTION 03: Maclaurin series for ln(1 + x)
                // term and taylor result when i = 0
                last_term = x;
                result = last_term;

                // cycle to find each term of taylor serie
                cout << "Serie terms:" << endl;
                for (int i = 2; i <= n; i++) {
                    last_term *= -1 * x / (i + 1);
                    cout << last_term << " ";
                    result += last_term;
                }
                cout << "\nFinal result: " << endl;
                cout << "ln(1 + " << x << ") = " << result << endl;
                break;

            case 4: // OPTION 04: Maclaurin series for sin(x)
                // term and taylor result when i = 0
                last_term = x;
                result = last_term;

                // cycle to find each term of taylor serie
                cout << "Serie terms:" << endl;
                for (int i = 1; i <= n; i++) {
                    last_term *= -1 * (x * x) / ((2 * i) * (2 * i + 1));
                    cout << last_term << " ";
                    result += last_term;
                }
                cout << "\nFinal result: " << endl;
                cout << "sin(" << x << ") = " << result << endl;
                break;

            case 5: // OPTION 05: Maclaurin series for cos(x)
                // term and taylor result when i = 0
                last_term = 1;
                result = last_term;

                // cycle to find each term of taylor serie
                cout << "Serie terms:" << endl;
                for (int i = 1; i <= n; i++) {
                    last_term *= -1 * (x * x) / ((2 * i - 1) * (2 * i));
                    cout << last_term << " ";
                    result += last_term;
                }
                cout << "\nFinal result: " << endl;
                cout << "cos(" << x << ") = " << result << endl;
                break;

            case 6: // OPTION 06: Maclaurin series for a rational function
                while (x <= -1 || x >= 1) {
                    cout << "Enter the value of x: ";
                    cin >> x;
                }
                
                // term and taylor result when i = 0
                last_term = 1;
                result = last_term;

                // cycle to find each term of taylor serie
                cout << "Serie terms:" << endl;
                for (int i = 1; i <= n; i++) {
                    last_term *= x;
                    cout << (i + 1) * last_term << " ";
                    result += (i + 1) * last_term;
                }
                cout << "\nFinal result: " << endl;
                cout << "1 / (1 - " << x << ")^2 = " << result << endl;
                break;
        }

        // Request to user continue or not
        cout << "\nDo you want continue [Y|N]? "<< endl;
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');
    
    cout << "The program is over!"<< endl;

    return 0;
}