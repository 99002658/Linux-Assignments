#include <stdio.h>
int main() {
    int n=10;
    int i;
    unsigned long long fact = 1;
    printf("Enter an integer: ");
    
    // shows error if the user enters a negative integer
    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.");
    else {
        for (int i = 1; i <= n; ++i) {
            fact *= i;
        }
        printf("Factorial of %d = %llu", n, fact);
    }

    return 0;
}
