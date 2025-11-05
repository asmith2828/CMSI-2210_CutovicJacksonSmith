/*
 * Homework 5
 * CMSI 2210
 * 
 * Group Members:
 * - Stefan Cutovic
 * - Aidan Smith
 * - Caroline Jackson
 * 
 * This program outputs the times tables from 2 to N, where N is a 
 * user-defined number taken from the command line.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int maximum_table_number;
    
    // Check for command line argument
    if (argc != 2) {
        printf("\nError: Please provide a number for the times tables.\n\n");
        printf("Intended call structure: %s (number)\n\n", argv[0]);
        printf("Example: %s 5\n\n", argv[0]);
        return 1;
    }
    
    // Converts inputted argument to integer
    maximum_table_number = atoi(argv[1]);
    
    if (maximum_table_number < 2) {
        printf("Error: Number must be at least 2.\n");
        return 1;
    }
    
    // Prints times tables from 2 to N
    for (int table_number = 2; table_number <= maximum_table_number; table_number++) {
        printf("\nTimes Table for %d:\n", table_number);
        printf("-----------------\n");
        
        // Prints each multiplication from 1 to 10
        for (int multiplier = 1; multiplier <= 10; multiplier++) {
            printf("%2d x %2d = %5d\n", table_number, multiplier, table_number * multiplier);
        }
    }

    printf("\n");
    return 0;
}
