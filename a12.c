#include <stdio.h>

// Function to find the Greatest Common Divisor using recursion
int findGCD(int a, int b) {
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

// Function to find the smallest divisor (greater than 1)
int findSmallestDivisor(int n) {
    if (n <= 1) return n; 
    if (n % 2 == 0) return 2; // Smallest even divisor is 2

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return i;
    }
    return n; // If no divisor found, the number itself is prime
}

int main() {
    int num1, num2;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    if (num1 <= 0 || num2 <= 0) {
        printf("Please enter positive integers greater than 0.\n");
        return 1;
    }

    // Calculating GCD
    int gcd = findGCD(num1, num2);

    // Calculating Smallest Divisors for both
    int sd1 = findSmallestDivisor(num1);
    int sd2 = findSmallestDivisor(num2);

    printf("\n--- Results ---\n");
    printf("GCD of %d and %d is: %d\n", num1, num2, gcd);
    printf("Smallest divisor of %d is: %d\n", num1, sd1);
    printf("Smallest divisor of %d is: %d\n", num2, sd2);

    return 0;
}
