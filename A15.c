#include <stdio.h>
#include <stdlib.h> // Required for rand() and srand()
#include <time.h>   // Required for time()

int main() {
    int count, lower, upper;

    // 1. Seed the random number generator with current time
    srand(time(0));

    printf("How many random numbers do you want to generate? ");
    scanf("%d", &count);

    printf("Enter the range (lower and upper bound): ");
    scanf("%d %d", &lower, &upper);

    printf("\nGenerated Random Numbers:\n");
    for (int i = 0; i < count; i++) {
        // Formula to generate number within range [lower, upper]
        int num = (rand() % (upper - lower + 1)) + lower;
        printf("%d ", num);
    }

    printf("\n");
    return 0;
}
