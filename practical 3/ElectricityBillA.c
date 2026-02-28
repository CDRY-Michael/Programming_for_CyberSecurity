/* Electricity bill
Practical 3, Part 1

@author Michael
*/

#include <stdio.h>

int main()
{

    int previousMetre, currentMetre, day, month;

    printf(" Enter  (PreviousMeter/CurrentMetre/Day/Month: ");

    // Read input safely
    if (scanf("%d %d %d %d", &previousMetre, &currentMetre, &day, &month) != 4)
    {
        printf("Error: Invalid input format\n");
        return 1;
    }

    // Display input data
    printf("%d %d %d %d\nData Registered", previousMetre, currentMetre, day, month);

    // Validation

    // Meter readings within range 0–9999
    if (currentMetre < 0 || currentMetre > 9999)
        printf("Error: current meter reading out of range\n");

    if (previousMetre < 0 || previousMetre > 9999)
        printf("Error: previous meter reading out of range\n");

    // Previous not greater than present
    if (previousMetre > currentMetre)
        printf("Error: previous reading is more than present reading\n");

    // Electricity used not more than 1000
    if (previousMetre <= currentMetre)
    {
        if ((currentMetre - previousMetre) > 1000)
            printf("Error: electricity usage exceeds 1000 units\n");
    }

    // Month in range 1–12
    if (month < 1 || month > 12)
        printf("Error: month out of range\n");

    // Days in month validation 
    if (month >= 1 && month <= 12)
    {

        // Months with 31 days
        if (month == 1 || month == 3 || month == 5 || 
            month == 7 || month == 8 || month == 10 || month == 12)
        {

            if (day < 1 || day > 31)
                printf("Error: invalid day for month\n");
        }

        // Months with 30 days 
        else if (month == 4 || month == 6 ||month == 9 || month == 11)
        {

            if (day < 1 || day > 30)
                printf("Error: invalid day for month\n");
        }

        // February (assume 29 days) 
        else if (month == 2)
        {

            if (day < 1 || day > 29)
                printf("Error: invalid day for February\n");
        }
    }

    return 0;
}