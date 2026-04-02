#include <stdio.h>

// Function for Iterative approach
int factorialIterative(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

// Function for Recursive approach
int factorialRecursive(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

int main() {
    int num;
    printf("Enter a number (0-12): ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Error: Negative number.\n");
    } else if (num > 12) {
        printf("Warning: %d! will overflow a standard 'int'.\n", num);
        printf("Result (Incorrect due to overflow): %d\n", factorialIterative(num));
    } else {
        printf("Iterative Result: %d\n", factorialIterative(num));
        printf("Recursive Result: %d\n", factorialRecursive(num));
    }

    return 0;
}
