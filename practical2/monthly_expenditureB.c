// Prints Mothly Expenditure
// Practical 2, Part 2 (b)
// @author Michael

#include <stdio.h>

int main()
{
    float foodExpense = 6000.0, leisureExpense = 2000.0, clothesExpense = 500.0;
    float totalSpent;

    totalSpent = foodExpense + leisureExpense + clothesExpense;

    printf("The total expenditure this month was Rs.%.2f\n\n",totalSpent);
}