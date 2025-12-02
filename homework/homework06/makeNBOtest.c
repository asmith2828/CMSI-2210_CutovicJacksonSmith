// ————————————————————————————————————————————————————————————————————————————————
// filename: makeNBOtest.c
// A 64-bit test program for x86 MacOS that tests the makeNBO function
//
// Group Members:
// Stefan Cutovic
// Caroline Jackson
// Aidan Smith
//
// to compile:    gcc makeNBOC.c makeNBOtest.c -o makeNBOtest
// to run:        ./makeNBOtest
// ————————————————————————————————————————————————————————————————————————————————

#include <stdio.h>
#include <stdlib.h>

extern int isLittleEndian();
extern unsigned int makeNBO(unsigned int value);

int main() {
    if (isLittleEndian()) {
        printf("System uses little-endian architecture; conversion required.\n\n");
    } else {
        printf("System uses big-endian architecture; conversion is not required.\n\n");
    }
    
    // TEST CASE 1
    unsigned int originalValue1 = 0x12345678;
    unsigned int convertedValue1 = makeNBO(originalValue1);
    printf("Original: 0x%08X -> Network Byte Order: 0x%08X\n", originalValue1, convertedValue1);
    
    // TEST CASE 2
    unsigned int originalValue2 = 0x87654321;
    unsigned int convertedValue2 = makeNBO(originalValue2);
    printf("Original: 0x%08X -> Network Byte Order: 0x%08X\n", originalValue2, convertedValue2);
    
    // TEST CASE 3
    unsigned int originalValue3 = 0xDEADBEEF;
    unsigned int convertedValue3 = makeNBO(originalValue3);
    printf("Original: 0x%08X -> Network Byte Order: 0x%08X\n", originalValue3, convertedValue3);
    
    // TEST CASE 4
    unsigned int originalValue4 = 0xBEEFCAFE;
    unsigned int convertedValue4 = makeNBO(originalValue4);
    printf("Original: 0x%08X -> Network Byte Order: 0x%08X\n", originalValue4, convertedValue4);
    
    // TEST CASE 5
    unsigned int originalValue5 = 0x00000001;
    unsigned int convertedValue5 = makeNBO(originalValue5);
    printf("Original: 0x%08X -> Network Byte Order: 0x%08X\n", originalValue5, convertedValue5);
    
    // TEST CASE 6
    unsigned int originalValue6 = 0x10000000;
    unsigned int convertedValue6 = makeNBO(originalValue6);
    printf("Original: 0x%08X -> Network Byte Order: 0x%08X\n", originalValue6, convertedValue6);
    
    // TEST CASE 7
    unsigned int originalValue7 = 0xFFFFFFFF;
    unsigned int convertedValue7 = makeNBO(originalValue7);
    printf("Original: 0x%08X -> Network Byte Order: 0x%08X\n", originalValue7, convertedValue7);
    
    // TEST CASE 8
    unsigned int originalValue8 = 0xABCD1234;
    unsigned int convertedValue8 = makeNBO(originalValue8);
    printf("Original: 0x%08X -> Network Byte Order: 0x%08X\n", originalValue8, convertedValue8);
    
    // TEST CASE 9
    unsigned int originalValue9 = 0x1234ABCD;
    unsigned int convertedValue9 = makeNBO(originalValue9);
    printf("Original: 0x%08X -> Network Byte Order: 0x%08X\n", originalValue9, convertedValue9);
    
    exit(0);
}