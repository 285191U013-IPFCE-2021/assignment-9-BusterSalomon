#include "sum.h"

int sum (int a[], int n) {
    int result;
    
    // Recursive step
    if (n > 0) {
        result = a [n-1] + sum (a, n-1);
    }

    // Simple case
    else {
        return 0;
    }

    return result;
}