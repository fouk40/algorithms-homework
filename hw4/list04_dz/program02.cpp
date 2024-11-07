#include <iostream>
#include <cmath>
using namespace std;


int input_num_elements() {
    int n;
    do {
        cout << "Enter the number of elements: ";
        cin >> n; 
    } while (n <= 0);

    return n;
}

char *allocate_memory(int n) {
    return (char*) malloc(n * sizeof(char));
}

void input_word(char *a) {
    cout << "Enter word: ";
    cin >> a;
}

void unified_vector(char *a, char *b, int n, int m, char *c) {
    int min_length = min(n, m);

    for (int i = 0; i < 2 * min_length; i++) {
        if (i % 2 == 0) {
            c[i] = a[i / 2];
        } else {
            c[i] = b[i / 2];
        }
    }

    if (a[min_length]) {
        for (int i = 2 * min_length; i < n + m; i++) {
            c[i] = a[i - min_length];
        }
    } else if (b[min_length]) {
        for (int i = 2 * min_length; i < n + m; i++) {
            c[i] = b[i - min_length];
        }
    }
}    


int main() {
    int n1, n2, n;
    char *a, *b, *x;

    n1 = input_num_elements();
    a = allocate_memory(n1);
    input_word(a);

    n2 = input_num_elements();
    b = allocate_memory(n2);
    input_word(b);

    n = n1 + n2;

    x = allocate_memory(n);

    unified_vector(a, b, n1, n2, x);

    cout << "Vector X:" << "\n";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
}