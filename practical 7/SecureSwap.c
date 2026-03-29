/* SecureSwap.c
   Practical 7, Part 2 (a)
   Secure swap with NULL pointer validation
   @author Michael */

#include <stdio.h>
#include <stdbool.h>

// Error codes
#define SUCCESS 0
#define ERROR_NULL_POINTER 1

// Secure swap function with validation
int secureSwap(int *a, int *b)
{
    // SECURITY: Validate pointers before dereferencing
    if (a == NULL)
    {
        printf("Error: First pointer is NULL\n");
        return ERROR_NULL_POINTER;
    }

    if (b == NULL)
    {
        printf("Error: Second pointer is NULL\n");
        return ERROR_NULL_POINTER;
    }

    // Safe to dereference now
    int temp = *a;
    *a = *b;
    *b = temp;

    return SUCCESS;
}

int main()
{
    int x = 5, y = 10;
    int *nullPtr = NULL;

    // Test 1: Valid pointers
    printf("Test 1: Valid pointers\n");
    printf("Before: x = %d, y = %d\n", x, y);

    if (secureSwap(&x, &y) == SUCCESS)
    {
        printf("After: x = %d, y = %d\n", x, y);
    }

    // Test 2: NULL pointer (should fail safely)
    printf("\nTest 2: NULL pointer\n");
    if (secureSwap(&x, nullPtr) != SUCCESS)
    {
        printf("Swap failed safely - no crash!\n");
    }

    return 0;
}
