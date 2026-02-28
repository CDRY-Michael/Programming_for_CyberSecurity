/* Secure Electricity Bill with loops
Practical 3, Part 6

@author Michael
*/

#include <stdio.h>

int main() {

    int customers;
    int totalUnits = 0;

    printf("Enter number of customers (max 10): ");

    if (scanf("%d", &customers) != 1 || customers < 1 || customers > 10) {
        printf("Error: Invalid number of customers.\n");
        return 1;
    }

    for (int i = 1; i <= customers; i++) {

        int previousMetre, currentMetre, day, month;
        int valid = 1;
        int units = 0;

        printf("\nCustomer %d\n", i);
        printf("Enter previousMetre currentMetre day month: ");

        if (scanf("%d %d %d %d",
                  &previousMetre,
                  &currentMetre,
                  &day,
                  &month) != 4) {

            printf("Error: Invalid input format\n");

            while (getchar() != '\n');  // clear buffer
            continue;
        }

        printf("%d %d %d %d\n",
               previousMetre,
               currentMetre,
               day,
               month);

        /* Validation */

        if (previousMetre < 0 || previousMetre > 9999) {
            printf("Error: previous meter reading out of range\n");
            valid = 0;
        }

        if (currentMetre < 0 || currentMetre > 9999) {
            printf("Error: current meter reading out of range\n");
            valid = 0;
        }

        if (previousMetre > currentMetre) {
            printf("Error: previous reading greater than present reading\n");
            valid = 0;
        }

        if (valid) {
            units = currentMetre - previousMetre;

            if (units > 1000) {
                printf("Error: electricity usage exceeds 1000 units\n");
                valid = 0;
            }
        }

        if (month < 1 || month > 12) {
            printf("Error: month out of range\n");
            valid = 0;
        } else {

            int maxDays;

            if (month == 4 || month == 6 ||
                month == 9 || month == 11)
                maxDays = 30;
            else if (month == 2)
                maxDays = 29;  // assumed 29
            else
                maxDays = 31;

            if (day < 1 || day > maxDays) {
                printf("Error: invalid day for month\n");
                valid = 0;
            }
        }

        if (valid) {
            totalUnits += units;
            printf("Units used: %d\n", units);
        } else {
            printf("Customer %d record invalid.\n", i);
        }
    }

    printf("\n=== Summary ===\n");
    printf("Total electricity units used (valid customers only): %d\n",
           totalUnits);

    return 0;
}