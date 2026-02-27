// Takes today's day of the week and display the future day of the week
// @author Michael

#include <stdio.h>

int main(void)
{
    int today, offset;

    printf("Enter today's day (0=Sun ..., 6=Sat): ");
    if (scanf("%d", &today) != 1 || today < 0 || today > 6)
    { // input validation
        printf("Invalid input for today's day.\n");
        return 1;
    }

    printf("Enter number of days after today: ");
    if (scanf("%d", &offset) != 1)
    {
        printf("Invalid input for offset.\n");
        return 1;
    }
    // handle negative offsets safely
    int futureDay = (today + offset) % 7;
    if (futureDay < 0)
        futureDay += 7;
    // Displays the Future days
    const char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    printf("Future day is: %s (%d)\n", days[futureDay], futureDay);
    return 0;
}