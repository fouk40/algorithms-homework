#include <iostream>
#include <cmath>
using namespace std;


int main() {
    double a, b, c, discount, cash, bank_check, credit, interest_rate;
    int product_choice, original_price, customer_category, installments, credit_type;
    bool bank_check_available, credit_available = false;

    cout << "Enter the price of the product A: ";
    cin >> a;
    cout << "Enter the price of the product B: ";
    cin >> b;
    cout << "Enter the price of the product C: ";
    cin >> c;

    cout << "What product would you like to buy?" << endl;
    cout << "\t0 - A;" << endl;
    cout << "\t1 - B;" << endl;
    cout << "\t2 - C." << endl;
    cin >> product_choice;

    switch (product_choice) {
        case 0:
            original_price = a;
            break;
        case 1:
            original_price = b;
            break;
        case 2:
            original_price = c;
            break;
    }

    cout << "What customer category are you in?" << endl;
    cout << "\t0 - excellent;" << endl;
    cout << "\t1 - good;" << endl;
    cout << "\t2 - average;" << endl;
    cout << "\t3 - bad." << endl;
    cin >> customer_category;

    switch (customer_category) {
        case 0:
            switch (product_choice) {
                case 0:
                    discount = 0.4;
                    break;
                case 1:
                    discount = 0.3;
                    break;
                case 2:
                    discount = 0.2;
                    break;
            }
            bank_check_available = true;
            credit_available = true;
            break;
        case 1:
            switch (product_choice) {
                case 0:
                    discount = 0.3;
                    break;
                case 1:
                    discount = 0.2;
                    break;
                case 2:
                    discount = 0.1;
                    break;
            }
            bank_check_available = true;
            credit_available = true;
            break;
        case 2:
            switch (product_choice) {
                case 0:
                    discount = 0.2;
                    break;
                case 1:
                    discount = 0.1;
                    break;
                case 2:
                    discount = 0;
                    break;
            }
            bank_check_available = true;
            break;
        case 3:
            switch (product_choice) {
                case 0:
                    discount = 0;
                    break;
                case 1:
                    discount = -0.05;
                    break;
                case 2:
                    discount = -0.1;
                    break;
            }
            break;
    }
    cout << "The original price is " << original_price << endl;

    cash = original_price * (1 - discount);
    cout << "You can pay buy cash. The price is " << cash << endl;
    
    if (bank_check_available) {
        cout << "You can also pay by bank check. Enter number of installments: ";
        cin >> installments;
        cout << "Enter interest rate as percentage (from 3 to 15): ";
        cin >> interest_rate;
        bank_check = original_price * (1 + interest_rate * installments / 100) * (1 - discount);
        cout << "The price is " << bank_check << endl;
    }

    if (credit_available) {
        cout << "You can also pay by credit. Enter number of installments (from 1 to 6): ";
        cin >> installments;
        cout << "Enter credit type:" << endl;
        cout << "\t0 - platinum;" << endl;
        cout << "\t1 - business." << endl;
        cin >> credit_type;
        switch (credit_type) {
            case 0:
                credit = original_price * (1 - discount) * pow((1 + 5 / 100), installments);
                break;
            case 1:
                credit = original_price * (1 - discount) * pow((1 + 2 / 100), installments);
                break;
        }
        cout << "The price is " << credit << endl;
    }

    return 0;
}