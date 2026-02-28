#include<stdio.h>

int main() { 
    // declare three variables for holding the three values of input     
    char firstWord[20]; // a word or string up to 20 characters meaning Buffer size is 20     
    char secondWord[20]; // a word or string up to 20 characters meaning Buffer size is 20
     int num; 
 
    //prompt user to enter three input values 
    printf("Enter two words and an integer from keyboard: \n");  
    // read two words and an integer. For the words, read only 19 chars (leave room for \0 which represents the end of the string) 
    scanf("%19s %19s %d", firstWord, secondWord, &num);  
 
    // display two words and an integer 
    printf("%s %s \n%d \n", firstWord, secondWord, num);  
 
    return 0; 
} 

