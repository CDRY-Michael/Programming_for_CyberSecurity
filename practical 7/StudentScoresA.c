/* PointerBasicsA.c
   Practical 7, Part 1 (a)
   Basic pointer operations - declaration and dereferencing
   @author Michael */

#include <stdio.h>

int main() {
    // Declare variables
    int num = 42;
    int *ptr;  // Declare a pointer to int

    // Point to the address of num
    ptr = &num;

    // Display information
    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", (void*)&num);
    printf("Value of ptr: %p\n", (void*)ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);

    // Modify value through pointer
    *ptr = 100;

    printf("\nAfter modification through pointer:\n");
    printf("Value of num: %d\n", num);
    printf("Value pointed to by ptr: %d\n", *ptr);

    return 0;
}
