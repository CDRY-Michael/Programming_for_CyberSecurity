// Celsius to fahrenheit
// @author Michael

#include<stdio.h>

int main() {
    double celsius, fahrenheit;
// Takes celcius as input
    printf("Enter temperature celcius(°C): ");
    scanf("%lf",&celsius);

// Converts celcius to fahrenheit
    fahrenheit = (9.0 / 5) * celsius + 32;

// Displays the converted value
    printf("Celsius:%.2f - Fahrenheit:%.2f",celsius,fahrenheit);
} 