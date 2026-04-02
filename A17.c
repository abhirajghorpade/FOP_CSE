#include <stdio.h>

int main() {
    int n, i;
    double x, x_degrees, sum, term;

    // 1. Accept inputs
    printf("Enter the angle in degrees: ");
    scanf("%lf", &x_degrees);
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // 2. Convert degrees to radians
    // Formula: radians = degrees * (PI / 180)
    x = x_degrees * (3.14159265358979323846 / 180.0);

    // 3. Initialize variables
    term = x;  // First term is always x
    sum = x;   // Start the sum with the first term

    // 4. Loop to calculate terms
    // We start from 1 because the first term (index 0) is already in 'sum'
    for (i = 1; i < n; i++) {
        /* The relationship between term (i) and term (i-1) is:
           Next Term = Previous Term * (-x^2) / ((2*i) * (2*i + 1))
        */
        term = -term * x * x / ((2 * i) * (2 * i + 1));
        sum += term;
    }

    // 5. Output results
    printf("\nSum of the sine series: %.6lf\n", sum);

    return 0;
}
