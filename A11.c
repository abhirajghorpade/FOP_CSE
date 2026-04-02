#include <stdio.h>
#include <math.h>

void findPrimeFactors(int n);
int isPrime(int n);
long long factorial(int n);

int main() {
    int num;
    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1 || num < 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    printf("\n--- Results for %d ---\n", num);

    // 1. Square Root and Cube Root
    printf("Square Root: %.2f\n", sqrt(num));
    printf("Cube Root:   %.2f\n", cbrt(num));

    // 2. Check for Prime
    if (isPrime(num)) printf("Prime Status: %d is a Prime number.\n", num);
    else printf("Prime Status: %d is not a Prime number.\n", num);

    // 3. Factorial (limited to small numbers due to size)
    if (num > 20) printf("Factorial:   Value too large to display.\n");
    else printf("Factorial:   %lld\n", factorial(num));

    // 4. Prime Factors
    printf("Prime Factors: ");
    findPrimeFactors(num);
    printf("\n----------------------\n");

    return 0;
}

// Logic to check if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Logic for Factorial
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) fact *= i;
    return fact;
}

// Logic to extract prime factors
void findPrimeFactors(int n) {
    if (n <= 1) { printf("None"); return; }
    
    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        printf("%d ", 2);
        n = n / 2;
    }
    // n must be odd at this point, so skip even numbers
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n = n / i;
        }
    }
    // If n is a prime number greater than 2
    if (n > 2) printf("%d", n);
}
