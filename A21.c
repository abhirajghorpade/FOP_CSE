#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourcePath[100], destPath[100];
    char ch;

    // Input file paths
    printf("Enter source file name: ");
    scanf("%s", sourcePath);
    printf("Enter destination file name: ");
    scanf("%s", destPath);

    // 1. Open source file in 'read' mode
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Error: Could not open source file %s\n", sourcePath);
        exit(EXIT_FAILURE);
    }

    // 2. Open destination file in 'write' mode
    destFile = fopen(destPath, "w");
    if (destFile == NULL) {
        fclose(sourceFile); // Close source before exiting
        printf("Error: Could not open destination file %s\n", destPath);
        exit(EXIT_FAILURE);
    }

    // 3. Copy contents character by character
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully!\n");

    // 4. Always close your files
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
