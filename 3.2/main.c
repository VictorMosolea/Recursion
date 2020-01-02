#include <stdio.h>

double hermitePolynomialsRecursive(int n, double x) {
    if (n == 0) return 1;
    else if (n == 1) return 2 * x;
    else return 2 * n * hermitePolynomialsRecursive(n - 1, x) - 2 * (n - 1) * hermitePolynomialsRecursive(n - 2, x);
}

double hermitePolynomialsIterative(int n, double x) {
    double a = 1, b = 2 * x;
    if (n == 0) return a;
    if (n == 1) return b;
    else {
        int aux = 2;
        while (n - 1) {
            int c = 2 * aux * b - 2 * (aux - 1) * a;
            a = b;
            b = c;
            n--;
            aux++;
        }
        return b;
    }
}

int main() {

    return 0;
}