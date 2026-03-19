/* StudentScoresA.c
   Practical 6, Part 1 (a)
   Basic array operations - calculating average score
   @author Michael */

#include <stdio.h>

int main() {
    // Declare array for 5 student scores
    int scores[5];
    int sum = 0;
    double average;
    
    // Read in 5 scores
    printf("Enter 5 student scores:\n");
    for (int i = 0; i < 5; i++) {
        printf("Score %d: ", i + 1);
        scanf("%d", &scores[i]);
    }
    
    // Calculate sum
    for (int i = 0; i < 5; i++) {
        sum += scores[i];
    }
    
    // Calculate average
    average = (double)sum / 5;
    
    // Display results
    printf("\nResults:\n");
    printf("Sum: %d\n", sum);
    printf("Average: %.2lf\n", average);
    
    return 0;
}
