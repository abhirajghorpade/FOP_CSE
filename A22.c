#include <stdio.h>
#include <string.h>

void reverse_string(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char str1[100], str2[100], str3[200];
    int result;

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    // 1. STRLEN - Find Length
    printf("\n1. Length of str1: %zu", strlen(str1));
    printf("\n   Length of str2: %zu", strlen(str2));

    // 2. STRCMP - Comparison
    result = strcmp(str1, str2);
    if (result == 0)
        printf("\n2. Strings are equal.");
    else
        printf("\n2. Strings are not equal.");

    // 3. STRCPY - Copying
    strcpy(str3, str1);
    printf("\n3. str3 (after copying str1): %s", str3);

    // 4. STRCAT - Concatenation
    strcat(str3, " "); // Add a space
    strcat(str3, str2);
    printf("\n4. Combined string: %s", str3);

    // 5. STRREV (Manual) - Reversal
    // Note: strrev() is not standard C; we use a custom function
    reverse_string(str1);
    printf("\n5. str1 reversed: %s\n", str1);

    return 0;
}
