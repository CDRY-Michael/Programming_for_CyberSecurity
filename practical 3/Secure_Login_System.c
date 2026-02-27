#include <stdio.h>
#include <string.h>

#define MAX_ATTEMPTS 3
#define CORRECT_PIN "1234"

int isNumeric(const char *str) {
    int i = 0;

    if (str[0] == '\0')
        return 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int main(void) {
    char input[100];
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {

        printf("Enter PIN: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Input error.\n");
            return 1;
        }

        // Remove newline 
        input[strcspn(input, "\n")] = '\0'; // Replaces the newline with null terminator

        if (!isNumeric(input)) {
            printf("Error: Invalid input, numbers only.\n");
            continue;   // does NOT count as attempt
        }

        if (strcmp(input, CORRECT_PIN) == 0) {
            printf("Access Granted!\n");
            return 0;
        }

        attempts++;

        if (attempts < MAX_ATTEMPTS) {
            printf("Wrong PIN. %d attempt(s) left.\n",
                   MAX_ATTEMPTS - attempts);
        }
    }

    printf("Access Denied. Account Locked.\n");
    return 0;
}