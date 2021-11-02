#include "search.h"
#include <stdbool.h>

bool search (int a[], int n, int x) {

    // Simple cases
    if (n == 0) return false;
    if (a [n-1] == x) return true;
    
    // Recursive case
    else return search (a, n-1, x); 
    
}