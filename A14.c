#include <stdio.h>
#include <math.h>

int main() {
    long long binary;
    int decimal = 0, i = 0, remainder;

    printf("Enter a binary number (0s and 1s): ");
    scanf("%lld", &binary);

    long long temp = binary; // Keep a copy for the final print

    while (binary != 0) {
        // 1. Get the last digit
        remainder = binary % 10;
        
        // 2. Add it to decimal sum: digit * 2^position
        decimal += remainder * pow(2, i);
        
        // 3. Remove the last digit and move to next position
        binary /= 10;
        i++;
    }

    printf("Binary %lld in Decimal is: %d\n", temp, decimal);

    return 0;
}
