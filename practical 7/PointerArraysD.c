/* PointerFunctionsD.c
Practical 7, Part 1 (d)
Array Processing with pointers
@author Michael */

#include <stdio.h>

#define ARRAY_SIZE 5

// Function to calculate sum of array
int calculateSum(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(arr + i);
    }
    return sum;
}

// Function to find maximum value
int findMax(int *arr, int size)
{
    int max = *arr;
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
        }
    }
    return max;
}

int main()
{
    int numbers[ARRAY_SIZE] = {10, 20, 30, 40, 50};
    int *ptr = numbers;

    printf("Array elements: ");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    int sum = calculateSum(ptr, ARRAY_SIZE);
    int max = findMax(ptr, ARRAY_SIZE);

    printf("Sum: %d\n", sum);
    printf("Maximum: %d\n", max);

    return 0;
}
