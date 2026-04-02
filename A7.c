#include <stdio.h>
#include <string.h>

#define NUM_SUBJECTS 5

// Define the Structure
struct Student {
    char name[50];
    int rollNo;
    float marks[NUM_SUBJECTS];
    float total;
    float aggregate;
    char result[10]; // "Pass" or "Fail"
};

int main() {
    int n, i, j;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student s[n]; // Array of structures

    // 1. Input Section
    for (i = 0; i < n; i++) {
        printf("\n--- Entering Details for Student %d ---\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", s[i].name); // Reads string with spaces
        printf("Roll No: ");
        scanf("%d", &s[i].rollNo);

        s[i].total = 0;
        int failedSubject = 0;

        printf("Enter marks for %d subjects:\n", NUM_SUBJECTS);
        for (j = 0; j < NUM_SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);
            
            s[i].total += s[i].marks[j];
            
            // Check pass condition (40 per subject)
            if (s[i].marks[j] < 40) {
                failedSubject = 1;
            }
        }

        // 2. Logic Section
        s[i].aggregate = s[i].total / NUM_SUBJECTS;

        if (failedSubject) {
            strcpy(s[i].result, "Fail");
        } else {
            strcpy(s[i].result, "Pass");
        }
    }

    // 3. Display Section
    printf("\n\n%-15s %-10s %-10s %-10s %-15s\n", "Name", "Roll No", "Total", "Agg %", "Result");
    printf("--------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-15s %-10d %-10.2f %-10.2f %-15s\n", 
               s[i].name, s[i].rollNo, s[i].total, s[i].aggregate, s[i].result);
    }

    return 0;
}
