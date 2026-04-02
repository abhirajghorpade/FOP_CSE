#include <stdio.h>

int main() {
    int n, i;
    int arr[100], even[100], odd[100];
    int evenCount = 0, oddCount = 0;

    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Partitioning Logic
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even[evenCount] = arr[i];
            evenCount++;
        } else {
            odd[oddCount] = arr[i];
            oddCount++;
        }
    }

    // Displaying the results
    printf("\nEven Sub-list: ");
    for (i = 0; i < evenCount; i++) {
        printf("%d ", even[i]);
    }

    printf("\nOdd Sub-list: ");
    for (i = 0; i < oddCount; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");

    return 0;
}
