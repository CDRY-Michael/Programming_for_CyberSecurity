// Prints Mothly Expenditure
// Practical 2, Part 2 (a)
// @author Michael

#include <stdio.h>

int main()
{
    float foodExpense = 300.0, leisureExpense = 100.0, clothesExpense = 50.0;
    float totalSpent;

    totalSpent = foodExpense + leisureExpense + clothesExpense;

    printf("The total expenditure this month was £%.2f\n\n",totalSpent);
}
