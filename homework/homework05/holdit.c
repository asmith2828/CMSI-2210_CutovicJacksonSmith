/*
 * Homework 5
 * CMSI 2210
 * 
 * Group Members:
 * - Stefan Cutovic
 * - Aidan Smith
 * - Caroline Jackson
 * 
 * This program times how long you can hold your breath.
 */

#include <stdio.h>
#include <time.h>

int main() {
    time_t start_time, end_time;
    double elapsed_seconds;
    int minutes, seconds;
    
    printf("\nThis program will time how long you can hold your breath.\n");
    printf("Take a deep breath, then press the 'Enter' key.\n");
    printf("When you have to exhale, press the enter key again and your duration will be displayed.\n\n");
    
    printf("Press the 'Enter' key to start.");

    // Waits for first Enter press
    getchar();
    
    // Records start time
    start_time = time(NULL);
    printf("\nThe timer has started. Press the 'Enter' key when you've taken a breath.\n");
    
    // Waits for second Enter press
    getchar();
    
    // Records end time
    end_time = time(NULL);
    
    elapsed_seconds = difftime(end_time, start_time);
    
    minutes = (int)elapsed_seconds / 60;
    seconds = (int)elapsed_seconds % 60;
    
    printf("You held your breath for %d minute(s) and %d second(s).\n\n", minutes, seconds);
    
    return 0;
}
