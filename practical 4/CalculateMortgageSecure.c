/* CalculateMortgageSecure.c
   Practical 4, Part 2 (a)
   Secure mortgage calculation with input validation
   @author Michael */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Function declarations
double largerSalary(double salary1, double salary2);
double smallerSalary(double salary1, double salary2);
bool validateSalary(double salary);
bool readSalaries(double *salary1, double *salary2);
double calculateMortgage(double salary1, double salary2);

int main()
{
    // Declared variables
    double salary1, salary2, mortgage;

    // Read and validate two salaries with error handling
    printf("Enter two salaries separated by a space:\n");

    if (!readSalaries(&salary1, &salary2))
    {
        printf("Error: Invalid input. Program terminated.\n");
        return 1;
    }

    // Validate salary ranges
    if (!validateSalary(salary1) || !validateSalary(salary2))
    {
        printf("Error: Salaries must be positive and within valid range.\n");
        return 1;
    }

    // Calculate mortgage with overflow protection
    mortgage = calculateMortgage(salary1, salary2);

    if (mortgage < 0)
    {
        printf("Error: Mortgage calculation failed.\n");
        return 1;
    }

    // Display the mortgage
    printf("The maximum size of mortgage is: £ %.2lf\n", mortgage);

    return 0;
}

// Secure function to read salaries with input validation
bool readSalaries(double *salary1, double *salary2)
{
    // Check for NULL pointers (defensive programming)
    if (salary1 == NULL || salary2 == NULL)
    {
        return false;
    }

    // Validate scanf return value
    if (scanf("%lf %lf", salary1, salary2) != 2)
    {
        // Clear input buffer on error
        while (getchar() != '\n')
            ;
        return false;
    }

    return true;
}

// Function to validate salary is within acceptable range
bool validateSalary(double salary)
{
    const double MIN_SALARY = 0.0;
    const double MAX_SALARY = 1000000.0; // £1 million max

    // Check for negative values and reasonable upper bound
    if (salary < MIN_SALARY || salary > MAX_SALARY)
    {
        return false;
    }

    return true;
}

// Secure mortgage calculation with overflow checking
double calculateMortgage(double salary1, double salary2)
{
    double larger = largerSalary(salary1, salary2);
    double smaller = smallerSalary(salary1, salary2);
    double mortgage;

    // Check for potential overflow before multiplication
    if (larger > (LLONG_MAX / 3))
    {
        return -1; // Error indicator
    }

    mortgage = larger * 3;

    // Check for potential overflow before addition
    if (mortgage > (LLONG_MAX - smaller))
    {
        return -1; // Error indicator
    }

    mortgage += smaller;

    return mortgage;
}

// Function for selecting larger salary
double largerSalary(double salary1, double salary2)
{
    if (salary1 > salary2)
        return salary1;
    else
        return salary2;
}

// Function for selecting smaller salary
double smallerSalary(double salary1, double salary2)
{
    if (salary1 > salary2)
        return salary2;
    else
        return salary1;
}
