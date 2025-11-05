/*
 * Homework 5
 * CMSI 2210
 * 
 * Group Members:
 * - Stefan Cutovic
 * - Aidan Smith
 * - Caroline Jackson
 * 
 * This program converts a base-10 number (decimal) to its 32-bit or 64-bit
 * hexadecimal value equivalent.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    unsigned long long decimal_number;
    int number_of_digits = 8;  // Defaults to 32-bit per spec
    
    if (argc < 2) {
        printf("\nError: Please provide a decimal number to convert to hexadecimal.\n\n");
        printf("Intended call structure: %s <decimal_number> [8|16]\n\n", argv[0]);
        printf("Example: %s 65535 8\n\n", argv[0]);
        return 1;
    }
    
    // Converts inputted argument to unsigned long long
    decimal_number = atoll(argv[1]);
    
    // Checks if digits argument was provided
    if (argc >= 3) {
        number_of_digits = atoi(argv[2]);
        if (number_of_digits != 8 && number_of_digits != 16) {
            printf("Error: Number of digits must be either 8 or 16.\n");
            return 1;
        }
    }
    
    // Prints hexadecimal based on # of digits
    if (number_of_digits == 8) {
        printf("0x%08X\n", (unsigned int)decimal_number);
    } else {
        printf("0x%016llX\n", decimal_number);
    }
    
    return 0;
}
