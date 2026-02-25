// Population project for 5 years
// @author Michael

#include<stdio.h>

int main() {
    long population = 312032486;  // Current population
    int years = 5;                 // Number of years
    
    // Seconds in a year (365 days)
    long seconds_per_year = 365 * 24 * 3600;
    
    // Calculate annual changes (using floating-point for accuracy)
    double births_per_year = seconds_per_year / 7.0;
    double deaths_per_year = seconds_per_year / 13.0;
    double immigrants_per_year = seconds_per_year / 45.0;
    
    // Total population change per year
    double total_change_per_year = births_per_year - deaths_per_year + immigrants_per_year;
    
    printf("US Census Bureau Population Projection\n");
    printf("Current population: %ld\n\n", population);
    printf("Projected population for the next 5 years:\n");
    printf("Year 1: ");
    
    // Display population for each of the next 5 years
    for (int year = 1; year <= years; year++) {
        population = population + (long)total_change_per_year;
        printf("%ld", population);
        if (year < years) {
            printf("\nYear %d: ", year + 1);
        }
    }
    printf("\n");
    
    return 0;
}