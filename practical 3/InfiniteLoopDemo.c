/* Loop with max limit
Practical 3, Part 2 

@author Michael
*/

#include <stdio.h>
#define MAX_ITERATIONS 100
int main() {
    int userInput;
    int iterations = 0;
    
    printf("Guess the number (between 1 and 10): ");
   // ✓ SAFE: Loop has maximum iteration limit
    while (iterations < MAX_ITERATIONS) {
        if (scanf("%d", &userInput) != 1) {
            printf("Invalid input! Try again: ");
            while (getchar() != '\n');
            iterations++;
            continue;
        }
        
        if (userInput == 7) {
            printf("Correct! You guessed it in %d attempts.\n", iterations + 1);
            break;
        }
        
        printf("Wrong! Try again: ");
        iterations++;
    }
    
    if (iterations >= MAX_ITERATIONS) {
        printf("Maximum attempts reached. Game over!\n");
    }
    return 0;
}
