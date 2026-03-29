/* PointerArraysB.c
   Practical 7, Part 1 (b)
   Pointers and arrays - accessing array elements with pointers
   @author Michael */

#include <stdio.h>

#define ARRAY_SIZE 5

int main() {
    int numbers[ARRAY_SIZE] = {10, 20, 30, 40, 50};
    int *ptr = numbers;  // Point to first element

    // Method 1: Array indexing
    printf("Using array indexing:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    // Method 2: Pointer arithmetic
    printf("\nUsing pointer arithmetic:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));
    }

    // Method 3: Pointer indexing
    printf("\nUsing pointer indexing:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }

    return 0;
}
