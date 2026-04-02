#include <stdio.h>

int main() {
    float marks[5], total = 0, aggregate;
    int i, isPass = 1; // isPass acts as a boolean flag

    // 1. Input Marks
    printf("Enter marks for 5 courses (out of 100):\n");
    for (i = 0; i < 5; i++) {
        printf("Course %d: ", i + 1);
        scanf("%f", &marks[i]);

        // 2. Check if the student failed any single subject
        if (marks[i] < 40) {
            isPass = 0;
        }
        total += marks[i];
    }

    // 3. Comparison and Result Calculation
    if (isPass == 0) {
        printf("\nResult: FAIL (Scored less than 40 in one or more subjects).\n");
    } else {
        aggregate = total / 5.0;
        printf("\nResult: PASS\n");
        printf("Total Marks: %.2f\n", total);
        printf("Aggregate: %.2f%%\n", aggregate);

        // 4. Assign Grade
        printf("Grade: ");
        if (aggregate >= 75) {
            printf("Distinction\n");
        } else if (aggregate >= 60) {
            printf("First Division\n");
        } else if (aggregate >= 50) {
            printf("Second Division\n");
        } else {
            printf("Third Division\n");
        }
    }

    return 0;
}
