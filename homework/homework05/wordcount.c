/*
 * Homework 5
 * CMSI 2210
 * 
 * Group Members:
 * - Stefan Cutovic
 * - Aidan Smith
 * - Caroline Jackson
 * 
 * This program counts the number of words in a text file.
 */

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *input_file;
    int current_character;
    int total_word_count = 0;
    int currently_in_word = 0; // Used as a flag --> 0: not in word, 1: in word
    
    if (argc != 2) {
        printf("\nError: Please provide a filename to count words.\n\n");
        printf("Intended call structure: %s (filename)\n\n", argv[0]);
        printf("Example: %s test.txt\n\n", argv[0]);
        return 1;
    }
    
    // Checks if input file exists
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }
    
    // Reads file character by character
    while ((current_character = fgetc(input_file)) != EOF) {
        // Checks if current character is whitespace
        if (isspace(current_character)) {
            // If currently in a word --> a word has been completed
            if (currently_in_word) {
                total_word_count = total_word_count + 1;
                currently_in_word = 0;
            }
        } else {
            // Non-whitespace character --> currently in a word
            currently_in_word = 1;
        }
    }
    
    // If file ends while in word --> counts last word
    if (currently_in_word) {
        total_word_count = total_word_count + 1;
    }
    
    // Checks for read errors
    if (ferror(input_file)) {
        printf("Error: An error occurred while reading the file.\n\n");
        fclose(input_file);
        return 1;
    }
    
    fclose(input_file);
    
    printf("Number of words in file: %d\n\n", total_word_count);
    
    return 0;
}
