#include <stdio.h>
#include <string.h>

// Define the Employee structure
struct Employee {
    char name[50];
    char designation[50];
    char gender; // 'M' or 'F'
    char doj[15]; // Date of Joining (e.g., "01-01-2024")
    float salary;
};

// Function prototypes
void displayStats(struct Employee emp[], int n);
void filterSalary(struct Employee emp[], int n);
void filterDesignation(struct Employee emp[], int n);

int main() {
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);
    getchar(); // Clear the newline character from buffer

    struct Employee emp[n];

    // Input loop
    for (int i = 0; i < n; i++) {
        printf("\n--- Details for Employee %d ---\n", i + 1);
        printf("Name: ");
        fgets(emp[i].name, 50, stdin);
        emp[i].name[strcspn(emp[i].name, "\n")] = 0;

        printf("Designation: ");
        fgets(emp[i].designation, 50, stdin);
        emp[i].designation[strcspn(emp[i].designation, "\n")] = 0;

        printf("Gender (M/F): ");
        scanf(" %c", &emp[i].gender);

        printf("Date of Joining (DD-MM-YYYY): ");
        scanf("%s", emp[i].doj);

        printf("Salary: ");
        scanf("%f", &emp[i].salary);
        getchar(); // Clear buffer for next name input
    }

    // Perform computations
    printf("\n==============================");
    printf("\n      ORGANIZATION REPORT     ");
    printf("\n==============================");
    
    displayStats(emp, n);
    filterSalary(emp, n);
    filterDesignation(emp, n);

    return 0;
}

// 1. Compute total count and gender distribution
void displayStats(struct Employee emp[], int n) {
    int male = 0, female = 0;
    for (int i = 0; i < n; i++) {
        if (emp[i].gender == 'M' || emp[i].gender == 'm') male++;
        else if (emp[i].gender == 'F' || emp[i].gender == 'f') female++;
    }
    printf("\nTotal Employees: %d", n);
    printf("\nMale Employees:  %d", male);
    printf("\nFemale Employees: %d", female);
}

// 2. Employee with salary > 10,000
void filterSalary(struct Employee emp[], int n) {
    printf("\n\nEmployees with Salary > 10,000:");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (emp[i].salary > 10000) {
            printf("\n - %s (Salary: %.2f)", emp[i].name, emp[i].salary);
            found = 1;
        }
    }
    if (!found) printf("\n None found.");
}

// 3. Employee with designation "asst manager"
void filterDesignation(struct Employee emp[], int n) {
    printf("\n\nEmployees with Designation 'asst manager':");
    int found = 0;
    for (int i = 0; i < n; i++) {
        // strcasecmp handles case-insensitive comparison (if available)
        if (strcasecmp(emp[i].designation, "asst manager") == 0) {
            printf("\n - %s", emp[i].name);
            found = 1;
        }
    }
