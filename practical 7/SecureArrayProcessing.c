/* SecureArrayProcessing.c
   Practical 7, Part 2 (b)
   Secure array operations with comprehensive validation
   @author Michael */

#include <stdio.h>
#include <stdbool.h>

#define MAX_ARRAY_SIZE 1000
#define ARRAY_SIZE 5

// Validate array parameters
bool validateArrayParams(int *arr, int size)
{
    // Check for NULL pointer
    if (arr == NULL)
    {
        printf("Error: Array pointer is NULL\n");
        return false;
    }

    // Check for valid size
    if (size <= 0)
    {
        printf("Error: Invalid array size (%d)\n", size);
        return false;
    }

    // Check for reasonable size
    if (size > MAX_ARRAY_SIZE)
    {
        printf("Error: Array size too large (%d > %d)\n",
               size, MAX_ARRAY_SIZE);
        return false;
    }

    return true;
}

// Secure sum calculation
bool secureCalculateSum(int *arr, int size, int *result)
{
    // Validate result pointer
    if (result == NULL)
    {
        printf("Error: Result pointer is NULL\n");
        return false;
    }

    // Validate array parameters
    if (!validateArrayParams(arr, size))
    {
        return false;
    }

    // Safe to process
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(arr + i); // Pointer arithmetic
    }

    *result = sum;
    return true;
}

// Secure maximum finder
bool secureFindMax(int *arr, int size, int *maxValue)
{
    // Validate result pointer
    if (maxValue == NULL)
    {
        printf("Error: Max value pointer is NULL\n");
        return false;
    }

    // Validate array parameters
    if (!validateArrayParams(arr, size))
    {
        return false;
    }

    // Safe to process
    int max = *arr; // Initialize with first element
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
        }
    }

    *maxValue = max;
    return true;
}

// Secure element access with bounds checking
bool secureAccessElement(int *arr, int size, int index,
                         int *value)
{
    // Validate array and result pointer
    if (!validateArrayParams(arr, size) || value == NULL)
    {
        return false;
    }

    // CRITICAL: Bounds checking
    if (index < 0 || index >= size)
    {
        printf("Error: Index %d out of bounds [0, %d)\n",
               index, size);
        return false;
    }

    // Safe to access
    *value = *(arr + index);
    return true;
}

int main()
{
    int numbers[ARRAY_SIZE] = {10, 20, 30, 40, 50};
    int sum, max, value;

    // Test 1: Valid array operations
    printf("=== Test 1: Valid Operations ===\n");

    if (secureCalculateSum(numbers, ARRAY_SIZE, &sum))
    {
        printf("Sum: %d\n", sum);
    }

    if (secureFindMax(numbers, ARRAY_SIZE, &max))
    {
        printf("Maximum: %d\n", max);
    }

    // Test 2: NULL pointer
    printf("\n=== Test 2: NULL Pointer ===\n");
    if (!secureCalculateSum(NULL, ARRAY_SIZE, &sum))
    {
        printf("Handled NULL pointer safely\n");
    }

    // Test 3: Invalid size
    printf("\n=== Test 3: Invalid Size ===\n");
    if (!secureCalculateSum(numbers, -5, &sum))
    {
        printf("Rejected negative size\n");
    }

    // Test 4: Bounds checking
    printf("\n=== Test 4: Bounds Checking ===\n");

    // Valid index
    if (secureAccessElement(numbers, ARRAY_SIZE, 2, &value))
    {
        printf("Element at index 2: %d\n", value);
    }

    // Out of bounds - too large
    if (!secureAccessElement(numbers, ARRAY_SIZE, 10, &value))
    {
        printf("Prevented buffer overflow\n");
    }

    // Out of bounds - negative
    if (!secureAccessElement(numbers, ARRAY_SIZE, -1, &value))
    {
        printf("Prevented negative index access\n");
    }

    printf("\nAll tests completed successfully!\n");

    return 0;
}
