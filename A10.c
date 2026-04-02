#include <stdio.h>
#include <math.h>

// Function to calculate factorial
long long factorial(int n) {
    if (n < 0) return -1; // Error case
    long long fact = 1;
    for (int i = 1; i <= n; i++) fact *= i;
    return fact;
}

int main() {
    char operator;
    double num1, num2, result;

    printf("--- Simple C Calculator ---\n");
    printf("Choose operation: +, -, *, /, ^ (power), ! (factorial): ");
    scanf(" %c", &operator);

    // Factorial only needs one input
    if (operator == '!') {
        printf("Enter an integer: ");
        int n;
        scanf("%d", &n);
        long long f = factorial(n);
        if (f == -1) printf("Error: Negative number!\n");
        else printf("%d! = %lld\n", n, f);
    } 
    else {
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);

        switch (operator) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/': 
                if (num2 != 0) result = num1 / num2;
                else { printf("Error: Division by zero!\n"); return 1; }
                break;
            case '^': result = pow(num1, num2); break;
            default: printf("Invalid operator!\n"); return 1;
        }
        printf("Result: %.2lf\n", result);
    }

    return 0;
}
