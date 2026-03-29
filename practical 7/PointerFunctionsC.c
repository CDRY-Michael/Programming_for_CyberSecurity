/* PointerFunctionsC.c
Practical 7, Part 1 (c)
Pass by pointer - swapping two numbers
@author Michael */

#include <stdio.h>

// Function to swap two integers using pointers
void swap(int *a, int *b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}

int main() {
 int x = 5, y = 10;

 printf("Before swap: x = %d, y = %d\n", x, y);

 // Pass addresses of x and y
 swap(&x, &y);

 printf("After swap: x = %d, y = %d\n", x, y);

 return 0;
}
