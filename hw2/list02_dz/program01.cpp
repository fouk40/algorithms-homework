/*
    Playing around with number divisors
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;

    // Entering numbers
    do {
        cout << "Enter number A: ";
        cin >> a;
        cout << "Enter number B: ";
        cin >> b;
    } while (a < 10 || a > 1000 || b < 10 || b > 1000);

    int sum_div = 0, count_div_a = 0, count_div_b = 0, product_count_div;
    int product_odd_div_a = 1, sum_even_div_b = 0;

    for (int i = 1; i <= a; i++) {
        if (a % i == 0) {
            sum_div += i;
            count_div_a += 1;
            if (i % 2 != 0) {
                product_odd_div_a *= i;
            }
        }
    }

    for (int i = 1; i <= b; i++) {
        if (b % i == 0) {
            sum_div += i;
            count_div_b += 1;
            if (i % 2 == 0) {
                sum_even_div_b += i;
            }
        }
    }

    product_count_div = count_div_a * count_div_b;

    cout << "Sum of divisors of A and B: " << sum_div << endl;
    cout << "Product of count of divisors of A and B: " << product_count_div << endl;
    cout << "Sum of the product of odd divisors of number A and the sum of even divisors of number B: " << \
    product_odd_div_a + sum_even_div_b << endl;

    int min_num;
    int max_cmd = 0;

    if (a < b) {
        min_num = a;
    } else {
        min_num = b;
    }

    for (int i = min_num; i > 1; i--) {
        if (a % i == 0 && b % i == 0) {
            max_cmd = i;
            break;
        }
    }

    if (max_cmd != 0) {
        cout << "The maximum common divisor of A and B: " << max_cmd << endl;
    } else {
        cout << "The numbers are both prime." << endl;
    }

    return 0;
}