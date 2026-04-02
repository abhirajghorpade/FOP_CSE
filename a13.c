#include <stdio.h>

int main() {
    int num, remainder;

    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input! Please enter an integer.\n");
        return 1;
    }

    // Handle negative numbers by making them positive for the loop
    if (num < 0) {
        printf("-");
        num = -num;
    }

    // If the user enters 0, just print 0
    if (num == 0) {
        printf("0");
    }

    printf("Reversed digits: ");

    while (num > 0) {
        remainder = num % 10;      // Get the last digit
        printf("%d", remainder);   // Print it immediately
        num = num / 10;            // Remove the last digit from the number
    }

    printf("\n");

    return 0;
}
