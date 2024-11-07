#include <iostream>
#include <cmath>
using namespace std;


int *allocate_memory(int n) {
    return (int*) malloc(n * sizeof(int));
}

int sum_products(int *a, int *b, int n) {
    int res = 0;

    for (int i = 0; i < n; i++) {
        res += a[i] * b[i];
    }

    return res;
}

int sum(int *a, int n, int power = 1) {
    int res = 0;

    for (int i = 0; i < n; i++) {
        res += pow(a[i], power);
    }

    return res;
}

int avg(int *a, int n) {
    return sum(a, n) / n;
}

int linear_regression(int b0, int b1, int x) {
    return b0 + b1 * x;
}

void copy_vector(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
}


int main() {
    int n, b1, b0, *x, *y, *w, *z, error;
    cout << "Enter n: ";
    cin >> n;

    x = allocate_memory(n);
    y = allocate_memory(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter x[" << i << "] & y[" << i << "]: ";
        cin >> x[i] >> y[i];
    }

    b1 = (sum_products(x, y, n) - n * avg(x, n) * avg(y, n)) / (sum(x, n, 2) - pow(sum(x, n), 2) / n);

    b0 = avg(y, n) - b1 * avg(x, n);

    cout << "Linear regression:\n";
    for (int i = 0; i < n; i++) {
        cout << "for x = " << x[i] << ": " << linear_regression(b0, b1, x[i]) << "\n";
    }

    n++;

    w = allocate_memory(n);
    copy_vector(x, w, n - 1);
    free(x);

    z = allocate_memory(n);
    copy_vector(y, z, n - 1);
    free(y);
    
    cout << "Enter x & y: ";
    cin >> w[n] >> z[n];

    b1 = (sum_products(w, z, n) - n * avg(w, n) * avg(z, n)) / (sum(w, n, 2) - pow(sum(w, n), 2) / n);

    b0 = avg(z, n) - b1 * avg(w, n);

    cout << "Linear regression for x = " << w[n] << ": " << linear_regression(b0, b1, w[n]) << "\n";

    error = abs(z[n] - linear_regression(b0, b1, w[n]));
    cout << "Error: " << error << "\n";
}