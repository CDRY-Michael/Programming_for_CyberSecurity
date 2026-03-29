/* SecureScoreAnalyser.c
   Practical 7, Part 3
   Student Score Analysis with Secure Pointer Operations
   @author Michael */

#include <stdio.h>
#include <stdbool.h>

#define MAX_STUDENTS 100
#define MIN_SCORE 0
#define MAX_SCORE 100
#define BUFFER_SIZE 256

// Clear input buffer after invalid input
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // Consume all characters until newline
}

// Validate array parameters
bool validateArrayParams(int *arr, int size)
{
    if (arr == NULL)
    {
        printf("ERROR: Array pointer is NULL\n");
        return false;
    }

    if (size <= 0 || size > MAX_STUDENTS)
    {
        printf("ERROR: Invalid array size (%d). Must be 1-%d\n",
               size, MAX_STUDENTS);
        return false;
    }

    return true;
}

// Validate score range (0-100)
bool isValidScore(int score)
{
    return score >= MIN_SCORE && score <= MAX_SCORE;
}

// Read single score with validation and buffer clearing
bool readScoreWithValidation(int *score, int studentNumber)
{
    printf("Enter score for Student %d (0-100): ", studentNumber);

    // Check scanf return value
    int result = scanf("%d", score);

    // If scanf failed, handle invalid input
    if (result != 1)
    {
        printf("ERROR: Invalid input. Please enter a numeric value.\n");
        clearInputBuffer(); // Clear buffer to prevent infinite loops
        return false;
    }

    // Validate score range
    if (!isValidScore(*score))
    {
        printf("ERROR: Score out of range. Must be between %d and %d\n",
               MIN_SCORE, MAX_SCORE);
        return false;
    }

    return true;
}

// Statistics Functions (Using Pointer Arithmetic)

// Calculate average using pointer arithmetic
bool calculateAverage(int *scores, int size, double *average)
{
    // Validate result pointer
    if (average == NULL)
    {
        printf("ERROR: Average pointer is NULL\n");
        return false;
    }

    // Validate array parameters
    if (!validateArrayParams(scores, size))
    {
        return false;
    }

    // Calculate sum using pointer arithmetic
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(scores + i); // Pointer arithmetic: scores[i]
    }

    *average = (double)sum / size;
    return true;
}

// Find minimum score using pointer arithmetic
bool findMinimumScore(int *scores, int size, int *minScore)
{
    // Validate result pointer
    if (minScore == NULL)
    {
        printf("ERROR: Minimum score pointer is NULL\n");
        return false;
    }

    // Validate array parameters
    if (!validateArrayParams(scores, size))
    {
        return false;
    }

    // Initialize with first element using dereference
    int min = *scores;

    // Find minimum using pointer arithmetic
    for (int i = 1; i < size; i++)
    {
        if (*(scores + i) < min)
        {
            min = *(scores + i);
        }
    }

    *minScore = min;
    return true;
}

// Find maximum score using pointer arithmetic
bool findMaximumScore(int *scores, int size, int *maxScore)
{
    // Validate result pointer
    if (maxScore == NULL)
    {
        printf("ERROR: Maximum score pointer is NULL\n");
        return false;
    }

    // Validate array parameters
    if (!validateArrayParams(scores, size))
    {
        return false;
    }

    // Initialize with first element using dereference
    int max = *scores;

    // Find maximum using pointer arithmetic
    for (int i = 1; i < size; i++)
    {
        if (*(scores + i) > max)
        {
            max = *(scores + i);
        }
    }

    *maxScore = max;
    return true;
}

// Display all scores using pointer arithmetic
bool displayScores(int *scores, int size)
{
    // Validate array parameters
    if (!validateArrayParams(scores, size))
    {
        return false;
    }

    printf("\n Student Scores \n");
    for (int i = 0; i < size; i++)
    {
        printf("Student %d: %d\n", i + 1, *(scores + i));
    }

    return true;
}

// MAain Program

int main()
{
    int scores[MAX_STUDENTS];
    int *ptr = scores; // Pointer to first element
    int numStudents = 0;

    printf(" Secure Student Score Analyzer \n");
    printf("Maximum students: %d\n\n", MAX_STUDENTS);

    // Step 1: Read number of students
    printf("Enter number of students: ");
    if (scanf("%d", &numStudents) != 1)
    {
        printf("ERROR: Invalid input\n");
        return 1;
    }

    if (numStudents <= 0 || numStudents > MAX_STUDENTS)
    {
        printf("ERROR: Number of students must be 1-%d\n", MAX_STUDENTS);
        return 1;
    }

    clearInputBuffer(); // Clear newline from input buffer

    // Step 2: Read scores with validation and buffer clearing
    printf("\nEntering scores with validation:\n");
    for (int i = 0; i < numStudents; i++)
    {
        int score;
        bool validInput = false;

        // Keep asking until valid input received
        while (!validInput)
        {
            validInput = readScoreWithValidation(&score, i + 1);
            if (validInput)
            {
                *(ptr + i) = score; // Store using pointer arithmetic
            }
        }
    }

    // Step 3: Display entered scores
    if (!displayScores(ptr, numStudents))
    {
        printf("ERROR: Failed to display scores\n");
        return 1;
    }

    // Step 4: Calculate and display statistics
    printf("\n Statistics\n");

    // Calculate average
    double average = 0.0;
    if (calculateAverage(ptr, numStudents, &average))
    {
        printf("Average Score: %.2f\n", average);
    }
    else
    {
        printf("ERROR: Failed to calculate average\n");
        return 1;
    }

    // Find minimum
    int minScore = 0;
    if (findMinimumScore(ptr, numStudents, &minScore))
    {
        printf("Minimum Score: %d\n", minScore);
    }
    else
    {
        printf("ERROR: Failed to find minimum\n");
        return 1;
    }

    // Find maximum
    int maxScore = 0;
    if (findMaximumScore(ptr, numStudents, &maxScore))
    {
        printf("Maximum Score: %d\n", maxScore);
    }
    else
    {
        printf("ERROR: Failed to find maximum\n");
        return 1;
    }

    printf("\n Analysis Complete! \n");
    return 0;
}
