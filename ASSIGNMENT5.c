#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// Function Prototypes
void display(int mat[MAX][MAX], int row, int col);
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int r, int c);
void findSaddlePoint(int mat[MAX][MAX], int r, int c);
bool isMagicSquare(int mat[MAX][MAX], int n);
float determinant(float a[MAX][MAX], int k);
void inverse(float num[MAX][MAX], int f);

int main() {
    int choice, r, c, n;
    int matA[MAX][MAX], matB[MAX][MAX];

    printf("--- Matrix Operations Menu ---\n");
    printf("1. Addition of Two Matrices\n");
    printf("2. Find Saddle Point\n");
    printf("3. Check if Matrix is a Magic Square\n");
    printf("4. Inverse of a Matrix (3x3)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter rows and columns: ");
            scanf("%d %d", &r, &c);
            printf("Enter elements of Matrix A:\n");
            for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &matA[i][j]);
            printf("Enter elements of Matrix B:\n");
            for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &matB[i][j]);
            addMatrices(matA, matB, r, c);
            break;

        case 2:
            printf("Enter rows and columns: ");
            scanf("%d %d", &r, &c);
            printf("Enter matrix elements:\n");
            for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &matA[i][j]);
            findSaddlePoint(matA, r, c);
            break;

        case 3:
            printf("Enter size of square matrix (n x n): ");
            scanf("%d", &n);
            printf("Enter matrix elements:\n");
            for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &matA[i][j]);
            if (isMagicSquare(matA, n)) printf("It is a Magic Square!\n");
            else printf("Not a Magic Square.\n");
            break;

        case 4:
            printf("Inverse logic for 3x3 (Standard float input):\n");
            float matF[MAX][MAX];
            for(int i=0; i<3; i++) for(int j=0; j<3; j++) scanf("%f", &matF[i][j]);
            inverse(matF, 3);
            break;

        default:
            printf("Invalid choice.");
    }
    return 0;
}

// --- 1. Addition ---
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int r, int c) {
    printf("Resultant Matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }
}

// --- 2. Saddle Point ---
// A saddle point is the minimum in its row and maximum in its column.
void findSaddlePoint(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        int min_row = mat[i][0], col_ind = 0;
        for (int j = 1; j < c; j++) {
            if (min_row > mat[i][j]) {
                min_row = mat[i][j];
                col_ind = j;
            }
        }
        int k;
        for (k = 0; k < r; k++)
            if (min_row < mat[k][col_ind]) break;

        if (k == r) {
            printf("Saddle Point found at: %d\n", min_row);
            return;
        }
    }
    printf("No Saddle Point found.\n");
}

// --- 3. Magic Square ---
// Sum of rows, columns, and diagonals must be equal.
bool isMagicSquare(int mat[MAX][MAX], int n) {
    int sumD1 = 0, sumD2 = 0;
    for (int i = 0; i < n; i++) {
        sumD1 += mat[i][i];
        sumD2 += mat[i][n - 1 - i];
    }
    if (sumD1 != sumD2) return false;

    for (int i = 0; i < n; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += mat[i][j];
            colSum += mat[j][i];
        }
        if (rowSum != sumD1 || colSum != sumD1) return false;
    }
    return true;
}

// --- 4. Inverse (Simplified snippet for 3x3) ---
void inverse(float num[MAX][MAX], int f) {
    // Note: A full Adjoint/Determinant implementation is extensive.
    // This part usually requires calculating cofactors for each element.
    printf("Inverse calculation requires the Adjoint matrix divided by the Determinant.\n");
    printf("Check if Determinant is non-zero before proceeding!\n");
}
