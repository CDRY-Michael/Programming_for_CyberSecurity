// Prints Mothly Expenditure
// Practical 2, Part 2 (d)
// @author Michael

#include <stdio.h>

int main()
{
    float foodExpense, leisureExpense, clothesExpense, accomodation, travel;
    float totalSpent;
//Takes input    
    printf("Enter Food Expenses: ");
    scanf("%f", &foodExpense);

    printf("Enter Leisure Expense: ");
    scanf("%f", &leisureExpense);

    printf("Enter Clothes Expense: ");
    scanf("%f", &clothesExpense);

    printf("Enter Accomodation: ");
    scanf("%f", &accomodation);

    printf("Enter travel: ");
    scanf("%f", &travel);
// Calcultes total expense
    totalSpent = foodExpense + leisureExpense + clothesExpense + accomodation + travel;
// Prints the Total Expemse
    printf("The total expenditure this month was Rs.%.2f\n\n",totalSpent);

}