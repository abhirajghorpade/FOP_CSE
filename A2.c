#include <stdio.h>

int main() {
    float num1, num2;
    float sum, diff, product;

    // Taking input from the user
    printf("Enter two numbers (separated by a space): ");
    scanf("%f %f", &num1, &num2);

    // Performing calculations
    sum = num1 + num2;
    diff = num1 - num2;
    
    product = num1 * num2;

    // Displaying the results
    printf("\n--- Results ---\n");
    printf("Addition:       %.2f + %.2f = %.2f\n", num1, num2, sum);
    printf("Subtraction:    %.2f - %.2f = %.2f\n", num1, num2, diff);
    printf("Multiplication: %.2f * %.2f = %.2f\n", num1, num2, product);

    return 0;
}
