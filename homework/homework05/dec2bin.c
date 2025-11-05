/*
 * Homework 5
 * CMSI 2210
 * 
 * Group Members:
 * - Stefan Cutovic
 * - Aidan Smith
 * - Caroline Jackson
 * 
 * This program converts a base-10 number (decimal) to its 32-bit
 * binary value equivalent.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    unsigned int decimal_number;
    int binary_digits[32];

    if (argc != 2) {
        printf("\nError: Please provide a decimal number to convert to binary.\n\n");
        printf("Intended call structure: %s (decimal_number)\n\n", argv[0]);
        printf("Example: %s 65535\n\n", argv[0]);
        return 1;
    }
    
    // Converts inputted argument to unsigned integer
    decimal_number = atoi(argv[1]);
    
    // Converts to binary by repeatedly dividing by 2
    for (int position = 0; position < 32; position++) {
        binary_digits[31 - position] = decimal_number % 2;
        decimal_number = decimal_number / 2;
    }
    
    // Prints binary digits
    for (int position = 0; position < 32; position++) {
        printf("%d", binary_digits[position]);
    }
    printf("\n");
    
    return 0;
}
