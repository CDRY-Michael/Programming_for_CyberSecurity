/* Calaculator with menu
Practical 3, Part 4 

@author Michael
*/

#include <stdio.h>
int main() {
    int choice;
    int num1, num2, result;
    do {
        // Display menu
        printf("\n=== Simple Calculator ===\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        // Validate menu choice input
        if (scanf("%d", &choice) != 1) {
            printf("Error: Invalid input!\n");
            while (getchar() != '\n');  // Clear buffer
            choice = 0;  // Force loop to continue
            continue;
        }
        
        // Validate choice is in range 1-4
        if (choice < 1 || choice > 4) {
            printf("Error: Choice must be between 1 and 4!\n");
            continue;
        }
        
        // If choice is 1, 2, or 3, get two numbers
        if (choice >= 1 && choice <= 3) {
            printf("Enter first number: ");
            if (scanf("%d", &num1) != 1) {
                printf("Error: Invalid number!\n");
                while (getchar() != '\n');
                continue;
            }
            
            printf("Enter second number: ");
            if (scanf("%d", &num2) != 1) {
                printf("Error: Invalid number!\n");
                while (getchar() != '\n');
                continue;
            }
            
            // Perform the calculation based on choice
            switch (choice) {
                case 1:
                    result = num1 + num2;
                    printf("Result: %d + %d = %d\n", num1, num2, result);
                    break;
                case 2:
                    result = num1 - num2;
                    printf("Result: %d - %d = %d\n", num1, num2, result);
                    break;
                case 3:
                    result = num1 * num2;
                    printf("Result: %d * %d = %d\n", num1, num2, result);
                    break;
                default:
                    printf("Error: Invalid operation\n");
            }
        }
        
    } while (choice != 4);
    
    printf("Thank you for using the calculator!\n");
    return 0;
}
