#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp[100];
    char sub[50];
    
    printf("Enter the main string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove trailing newline

    // 1. Length of String
    printf("\n1. Length: %zu characters", strlen(str1));

    // 2. String Reversal
    strcpy(temp, str1); // Copy to temp so we don't ruin the original
    int len = strlen(temp);
    for (int i = 0; i < len / 2; i++) {
        char t = temp[i];
        temp[i] = temp[len - 1 - i];
        temp[len - 1 - i] = t;
    }
    printf("\n2. Reversed: %s", temp);

    // 3. Palindrome Check
    if (strcmp(str1, temp) == 0)
        printf("\n3. Palindrome: Yes");
    else
        printf("\n3. Palindrome: No");

    // 4. Equality Check
    printf("\n\nEnter another string to compare: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;

    if (strcmp(str1, str2) == 0)
        printf("4. Equality: Strings are identical.");
    else
        printf("4. Equality: Strings are different.");

    // 5. Check Substring
    printf("\n\nEnter a substring to search for: ");
    fgets(sub, sizeof(sub), stdin);
    sub[strcspn(sub, "\n")] = 0;

    if (strstr(str1, sub) != NULL)
        printf("5. Substring: '%s' found in '%s'\n", sub, str1);
    else
        printf("5. Substring: Not found.\n");

    return 0;
}
