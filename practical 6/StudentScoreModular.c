/* StudentScoresModular.c
   Practical 6, Part 2 (a)
   Modular array operations with functions
   @author Michael */

#include <stdio.h>

#define NUM_STUDENTS 5

// Function declarations
void readScores(int scores[], int size);
int calculateSum(int scores[], int size);
double calculateAverage(int scores[], int size);
int findMaximum(int scores[], int size);
int findMinimum(int scores[], int size);
void displayScores(int scores[], int size);
void displayStatistics(int scores[], int size);

int main() {
    int scores[NUM_STUDENTS];
    
    // Read scores
    readScores(scores, NUM_STUDENTS);
    
    // Display scores
    displayScores(scores, NUM_STUDENTS);
    
    // Display statistics
    displayStatistics(scores, NUM_STUDENTS);
    
    return 0;
}

// Function to read scores from user
void readScores(int scores[], int size) {
    printf("Enter %d student scores:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Score %d: ", i + 1);
        scanf("%d", &scores[i]);
    }
}

// Function to calculate sum
int calculateSum(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum;
}

// Function to calculate average
double calculateAverage(int scores[], int size) {
    int sum = calculateSum(scores, size);
    return (double)sum / size;
}

// Function to find maximum score
int findMaximum(int scores[], int size) {
    int max = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}

// Function to find minimum score
int findMinimum(int scores[], int size) {
    int min = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] < min) {
            min = scores[i];
        }
    }
    return min;
}

// Function to display all scores
void displayScores(int scores[], int size) {
    printf("\nIndividual Scores:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d: %d\n", i + 1, scores[i]);
    }
}


// Function to display statistics
void displayStatistics(int scores[], int size) {
    printf("\nStatistics:\n");
    printf("Sum: %d\n", calculateSum(scores, size));
    printf("Average: %.2lf\n", calculateAverage(scores, size));
    printf("Highest score: %d\n", findMaximum(scores, size));
    printf("Lowest score: %d\n", findMinimum(scores, size));
}
