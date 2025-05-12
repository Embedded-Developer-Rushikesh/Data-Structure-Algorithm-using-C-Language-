#include <stdio.h>

double myPow(double x, int n);

int main() {
    double x = 2.00000;
    int n = -2;
    double result = myPow(x, n);
    printf("Result: %.5f\n", result);
    return 0;
}

double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) {
        n = -n;
        x = 1/x;
    }
    if( (n%2 == 0))
    {
        return myPow(x*x, n/2);
    }else{
        return x*myPow(x*x, n/2);
    }
}