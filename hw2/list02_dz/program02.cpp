/*
    Digit decomposition of a number
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, opt, cur_dig, num_dig, min_dig, max_dig, sum_dig, product_odd_dig;
    char cont;
    do {
        // print the menu of options
        cout << "Select an option from 1 to 7 according to the menu:" << endl;
        cout << "[1]. Enter a number in the range between 1000 and 999999999" << endl;
        cout << "[2]. Print the digits of the number" << endl;
        cout << "[3]. Count how many digits the number has" << endl;
        cout << "[4]. Return the lowest and highest digits of the number" << endl;
        cout << "[5]. Return the sum of the digits of the number" << endl;
        cout << "[6]. Return the product of the odd digits" << endl;
        cout << "[7]. Calculate the inverted version of the number" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "Enter option: ";
        cin >> opt;

        switch (opt) {
            case 1: // OPTION 01: Enter the number
                do {
                    cout << "Enter a number: ";
                    cin >> n;
                } while (n < 1000 || n > 999999999);
                break;

            case 2: // OPTION 02: Print the digits of the number
                cout << "Enter a number: ";
                cin >> n;
                
                cout << "The digits of the number: ";
                do {
                    cout << n % 10 << " ";
                    n /= 10;
                } while (n != 0);
                cout << endl;
                break;

            case 3: // OPTION 03: Count how many digits the number has
                cout << "Enter a number: ";
                cin >> n;

                do {
                    num_dig += 1;
                    n /= 10;
                } while (n != 0);

                cout << "The number has " << num_dig << " digit(s)" << endl;
                break;

            case 4: // OPTION 04: Return the lowest and highest digits of the number
                cout << "Enter a number: ";
                cin >> n;

                min_dig = 9;
                max_dig = 0;

                do {
                    cur_dig = n % 10;
                    
                    if (cur_dig < min_dig) {
                        min_dig = cur_dig;
                    }
                    
                    if (cur_dig > max_dig) {
                        max_dig = cur_dig;
                    }

                    n /= 10;
                } while (n != 0);

                cout << "The lowest digit of the number: " << min_dig << endl;
                cout << "The highest digit of the number: " << max_dig << endl;
                break;

            case 5: // OPTION 05: Return the sum of the digits of the number
                cout << "Enter a number: ";
                cin >> n;

                sum_dig = 0;

                do {
                    sum_dig += n % 10;
                    n /= 10;
                } while (n != 0);

                cout << "The sum of the digits of the number: " << sum_dig << endl;
                break;

            case 6: // OPTION 06: Return the product of the odd digits
                cout << "Enter a number: ";
                cin >> n;

                product_odd_dig = 1;

                do {
                    cur_dig = n % 10;
                    if (cur_dig % 2 != 0) {
                        product_odd_dig *= cur_dig;
                    }
                    n /= 10;
                } while (n != 0);

                cout << "the product of the odd digits: " << product_odd_dig << endl;
                break;

            case 7: // OPTION 07: Calculate the inverted version of the number
                cout << "Enter a number: ";
                cin >> n;
                
                cout << "The inverted version of the number: ";
                do {
                    cout << n % 10;
                    n /= 10;
                } while (n != 0);
                break;
        }

        // Request to user continue or not
        cout << "\nDo you want continue [Y|N]? "<< endl;
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');
    
    cout << "The program is over!"<< endl;

    return 0;
}