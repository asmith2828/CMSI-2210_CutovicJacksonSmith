// ————————————————————————————————————————————————————————————————————————————————
// filename: whichEndIsUp.c
// A 64-bit program for x86 MacOS that determines a computer architecure's endianness
//
// Group Members:
// Stefan Cutovic
// Caroline Jackson
// Aidan Smith
//
// to compile:    gcc whichEndIsUp.c -o whichEndIsUp
// to run:        ./whichEndIsUp
// ————————————————————————————————————————————————————————————————————————————————

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Value 1 but occupies 4 bytes of memory:
    // 00000000 00000000 00000000 00000001
    unsigned int endianTestValue = 1;
    
    // Points to first of those 4 bytes to check storage order
    unsigned char *firstBytePointer = (unsigned char *)&endianTestValue;
    
    if (*firstBytePointer == 1) {
        printf("This computer uses little-endian architecture.\n");

    } else {
        printf("This computer uses big-endian architecture.\n");
    }
    
    exit(0);
}