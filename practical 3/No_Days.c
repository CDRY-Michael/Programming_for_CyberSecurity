//Displays the number of days in the month.
// @author Michael

#include <stdio.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main(void) {
    int month, year, days;
   // Takes int  input as months 
    printf("Enter month (1-12): ");
    if (scanf("%d", &month) != 1 || month < 1 || month > 12) { // input validation
        printf("Invalid month input.\n");
        return 1;
    }
    // Takes years
    printf("Enter year: ");
    if (scanf("%d", &year) != 1 || year <= 0) {
        printf("Invalid year input.\n");
        return 1;
    }
    // Switch case for number of days based on the month and leapyear.
    switch (month) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            days = 31;
            break;

        case 4: case 6: case 9: case 11:
            days = 30;
            break;

        case 2:
            days = isLeapYear(year) ? 29 : 28;
            break;

        default:
            printf("Invalid month.\n");
            return 1;
    }

    const char *monthNames[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    printf("%s %d had %d days.\n", monthNames[month - 1], year, days);

    return 0;
}