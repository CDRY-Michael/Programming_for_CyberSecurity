// Financial application: Compound value
// Calculates savings account value after 6 months with monthly deposits
// @author Michael

#include<stdio.h>

int main() {
    double monthly_saving, monthly_interest_rate, account_value = 0;
    
    // Annual interest rate is 5%, monthly rate is 0.05/12
    monthly_interest_rate = 0.05 / 12;
    
    // Prompt user to enter monthly saving amount
    printf("Enter the monthly saving amount: Rs.");
    scanf("%lf", &monthly_saving);
    
    // Calculate account value for 6 months
    for (int month = 1; month <= 6; month++) {
        // Add monthly saving and applies interest
        account_value = (account_value + monthly_saving) * (1 + monthly_interest_rate);
        printf("Month %d: $%.2f\n", month, account_value);
    }
    // Displays the Account value after 6 months
    printf("\nAccount value after 6 months: $%.2f\n", account_value);
    
    return 0;
}
