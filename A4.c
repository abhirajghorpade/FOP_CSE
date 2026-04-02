#include <stdio.h>

int main() {
    float basic_pay, hra, ta, gross_salary, professional_tax, net_salary;

    // Input basic salary from user
    printf("Enter the Basic Salary: ");
    scanf("%f", &basic_pay);

    // 1. Calculate Allowances
    hra = 0.10 * basic_pay;  // 10% of Basic Pay
    ta = 0.05 * basic_pay;   // 5% of Basic Pay

    // 2. Calculate Gross Salary
    gross_salary = basic_pay + hra + ta;

    // 3. Calculate Deductions (Professional Tax)
    // Professional Tax is 2% of the Gross (Total) Salary
    professional_tax = 0.02 * gross_salary;

    // 4. Calculate Net Salary
    net_salary = gross_salary - professional_tax;

    // Displaying the results
    printf("\n--- Salary Statement ---\n");
    printf("Basic Pay:         %.2f\n", basic_pay);
    printf("HRA (10%%):         %.2f\n", hra);
    printf("TA (5%%):           %.2f\n", ta);
    printf("--------------------------\n");
    printf("Gross Salary:      %.2f\n", gross_salary);
    printf("Prof. Tax (2%%):    %.2f\n", professional_tax);
    printf("--------------------------\n");
    printf("NET PAYABLE:       %.2f\n", net_salary);
    printf("--------------------------\n");

    return 0;
}
