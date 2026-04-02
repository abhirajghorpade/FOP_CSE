#include <stdio.h>

int main() {
    int num, i, range;

    printf("Enter an integer to generate its table: ");
    scanf("%d", &num);

    printf("Enter the range (e.g., up to 10 or 12): ");
    scanf("%d", &range);

    printf("\n--- Multiplication Table for %d ---\n", num);

    // Using a for loop to iterate from 1 to the specified range
    for (i = 1; i <= range; ++i) {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}
