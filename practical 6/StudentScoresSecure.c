/* StudentScoresSecure.c
   Practical 6, Part 3 (a)
   Secure array operations with comprehensive validation
   @author Michael */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define NUM_STUDENTS 5
#define MAX_STUDENTS 100
#define MIN_SCORE 0
#define MAX_SCORE 100
#define MAX_ATTEMPTS 3

// Function declarations
bool validateScore(int score);
bool validateArrayParams(int scores[], int size);
bool readScores(int scores[], int size);
bool readSingleScore(int *score);
int calculateSum(int scores[], int size);
double calculateAverage(int scores[], int size);
int findMaximum(int scores[], int size);
int findMinimum(int scores[], int size);
void displayScores(int scores[], int size);
void displayStatistics(int scores[], int size);

int main() {
    int scores[NUM_STUDENTS];
    
    // Validate array size
    if (NUM_STUDENTS <= 0 || NUM_STUDENTS > MAX_STUDENTS) {
        printf("Error: Invalid number of students.\n");
        return 1;
    }
    
    // Read scores with validation
    if (!readScores(scores, NUM_STUDENTS)) {
        printf("Error: Failed to read scores. Program terminated.\n");
        return 1;
    }
    
    // Display scores
    displayScores(scores, NUM_STUDENTS);
    
    // Display statistics
    displayStatistics(scores, NUM_STUDENTS);
    
    return 0;
}

// Validate score is within accepted range
bool validateScore(int score) {
    return (score >= MIN_SCORE && score <= MAX_SCORE);
}

// Validate array parameters
bool validateArrayParams(int scores[], int size) {
    // Check for NULL pointer
    if (scores == NULL) {
        printf("Error: NULL array pointer.\n");
        return false;
    }
    
    // Check size is positive and within limits
    if (size <= 0 || size > MAX_STUDENTS) {
        printf("Error: Invalid array size.\n");
        return false;
    }
    
    return true;
}

// Secure function to read a single score with validation
bool readSingleScore(int *score) {
    // Check for NULL pointer
    if (score == NULL) {
        return false;
    }
    
    // Validate scanf return value
    if (scanf("%d", score) != 1) {
        // Clear input buffer on error
        while (getchar() != '\n');
        return false;
    }
    
    // Validate score range
    if (!validateScore(*score)) {
        return false;
    }
    
    return true;
}

// Secure function to read all scores with retry logic
bool readScores(int scores[], int size) {
    // parameter checking
    if (!validateArrayParams(scores, size)) {
        return false;
    }
    
    printf("Enter %d student scores (0-100):\n", size);
    
    // Read each score with validation and retry logic
    for (int i = 0; i < size; i++) {
        int attempts = 0;
        bool validInput = false;
        
        // Bounds check before accessing array
        if (i >= size) {
            printf("Error: Array index out of bounds.\n");
            return false;
        }
        
        while (attempts < MAX_ATTEMPTS && !validInput) {
            printf("Score %d: ", i + 1);
            
            if (!readSingleScore(&scores[i])) {
                attempts++;
                printf("Invalid input. ");
                
                if (attempts < MAX_ATTEMPTS) {
                    printf("Score must be between %d and %d. ", 
                           MIN_SCORE, MAX_SCORE);
                    printf("Attempts remaining: %d\n", 
                           MAX_ATTEMPTS - attempts);
                }
            } else {
                validInput = true;
            }
        }
        
        // Check if max attempts exceeded
        if (attempts >= MAX_ATTEMPTS) {
            printf("Maximum attempts exceeded for score %d.\n", i + 1);
            return false;
        }
    }
    
    return true;
}

// Secure sum calculation with overflow checking
int calculateSum(int scores[], int size) {
    // parameter checking
    if (!validateArrayParams(scores, size)) {
        return -1;
    }
    
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        // Bounds check
        if (i >= size) {
            printf("Error: Array index out of bounds in calculateSum.\n");
            return -1;
        }
        
        // Check for potential overflow before addition
        if (sum > INT_MAX - scores[i]) {
            printf("Error: Sum overflow detected.\n");
            return -1;
        }
        
        sum += scores[i];
    }
    
    return sum;
}

// Secure average calculation
double calculateAverage(int scores[], int size) {
    // parameter checking
    if (!validateArrayParams(scores, size)) {
        return -1.0;
    }
    
    int sum = calculateSum(scores, size);
    
    if (sum < 0) {
        return -1.0;  // Error from calculateSum
    }
    
    return (double)sum / size;
}

// Secure maximum finder
int findMaximum(int scores[], int size) {
    // parameter checking
    if (!validateArrayParams(scores, size)) {
        return -1;
    }
    
    int max = scores[0];
    
    for (int i = 1; i < size; i++) {
        // Bounds check
        if (i >= size) {
            printf("Error: Array index out of bounds in findMaximum.\n");
            return -1;
        }
        
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    
    return max;
}

// Secure minimum finder
int findMinimum(int scores[], int size) {
    // parameter checking
    if (!validateArrayParams(scores, size)) {
        return -1;
    }
    
    int min = scores[0];
    
    for (int i = 1; i < size; i++) {
        // Bounds check
        if (i >= size) {
            printf("Error: Array index out of bounds in findMinimum.\n");
            return -1;
        }
        
        if (scores[i] < min) {
            min = scores[i];
        }
    }
    
    return min;
}

// Secure display function
void displayScores(int scores[], int size) {
    // parameter checking
    if (!validateArrayParams(scores, size)) {
        return;
    }
    
    printf("\nIndividual Scores:\n");
    
    for (int i = 0; i < size; i++) {
        // Bounds check
        if (i >= size) {
            printf("Error: Array index out of bounds in displayScores.\n");
            return;
        }
        
        printf("Student %d: %d\n", i + 1, scores[i]);
    }
}

// Secure statistics display
void displayStatistics(int scores[], int size) {
    // parameter checking
    if (!validateArrayParams(scores, size)) {
        return;
    }
    
    printf("\nStatistics:\n");
    
    int sum = calculateSum(scores, size);
    if (sum >= 0) {
        printf("Sum: %d\n", sum);
    }
    
    double avg = calculateAverage(scores, size);
    if (avg >= 0) {
        printf("Average: %.2lf\n", avg);
    }
    
    int max = findMaximum(scores, size);
    if (max >= 0) {
        printf("Highest score: %d\n", max);
    }
    
    int min = findMinimum(scores, size);
    if (min >= 0) {
        printf("Lowest score: %d\n", min);
    }
}

