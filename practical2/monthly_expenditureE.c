// Prints Mothly Expenditure
// Practical 2, Part 2 (E)
// @author Michael

/* Security issues:
 - Unsafe scanf(): scanf does not validate input
   If user enters non-numeric value like "abc", program behavior is undefined
 - No input validation: Program accepts negative expense values
   User cand enter -500 for food, causing incorrect error.
 */

#include <stdio.h>
#define ACCOMMODATION 20000 // Named constant for accommodation expense

int main()
{
    float foodExpense, leisureExpense, clothesExpense, travel;
    float totalSpent;
    int result; // To store scanf() return value

    printf("Your accomodation: %d\n", ACCOMMODATION);
    // Takes input
    // FIX: Validates scanf() return value and it check for non-negative input
    // result != 1 means when scanf() failed to read a float (e.g. user entered "abc")
    // foodExpense < 0 ensures no negative values which don't make sense for expenses
    printf("Enter Food Expenses: ");
    result = scanf("%f", &foodExpense);
    if (result != 1 || foodExpense < 0)
    {
        printf("Invalid input! Food expense must be non-negative.\n");
        return 1;
    }

    // leisureExpense < 0 ensures no negative values
    printf("Enter Leisure Expense: ");
    result = scanf("%f", &leisureExpense);
    if (result != 1 || leisureExpense < 0)
    {
        printf("Invalid input! Leisure expense must be non-negative.\n");
        return 1;
    }

    // clothesExpense < 0 ensures no negative values
    printf("Enter Clothes Expense: ");
    result = scanf("%f", &clothesExpense);
    if (result != 1 || clothesExpense < 0)
    {
        printf("Invalid input! Clothes expense must be non-negative.\n");
        return 1;
    }

    // travel < 0 ensures no negative values 
    printf("Enter travel: ");
    result = scanf("%f", &travel);
    if (result != 1 || travel < 0)
    {
        printf("Invalid input! Travel expense must be non-negative.\n");
        return 1;
    }
    // Calculates total expense
    totalSpent = foodExpense + leisureExpense + clothesExpense + ACCOMMODATION + travel;
    // Prints the Total Expense
    printf("The total expenditure this month was Rs.%.2f\n\n", totalSpent);
}