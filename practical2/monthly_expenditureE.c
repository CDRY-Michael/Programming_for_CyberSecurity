// Prints Mothly Expenditure
// Practical 2, Part 2 (d)
// @author Michael

#include <stdio.h>

int main()
{
    float foodExpense, leisureExpense, clothesExpense, travel;
    float totalSpent;

    const int accomodation = 20000;
    printf("Your accomodation: %d\n",accomodation);
//Takes input    
    printf("Enter Food Expenses: ");
    scanf("%f", &foodExpense);

    printf("Enter Leisure Expense: ");
    scanf("%f", &leisureExpense);

    printf("Enter Clothes Expense: ");
    scanf("%f", &clothesExpense);

    printf("Enter travel: ");
    scanf("%f", &travel);
// Calcultes total expense
    totalSpent = foodExpense + leisureExpense + clothesExpense + accomodation + travel;
// Prints the Total Expense
    printf("The total expenditure this month was Rs.%.2f\n\n",totalSpent);

}