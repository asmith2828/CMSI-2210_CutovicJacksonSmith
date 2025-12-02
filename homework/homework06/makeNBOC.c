// ————————————————————————————————————————————————————————————————————————————————
// filename: makeNBOC.c
// A 64-bit function for x86 MacOS that converts to Network Byte Order (big-endian)
//
// Group Members:
// Stefan Cutovic
// Caroline Jackson
// Aidan Smith
//
// to compile with test:    gcc makeNBOC.c makeNBOtest.c -o makeNBOtest
// ————————————————————————————————————————————————————————————————————————————————

#include <stdio.h>
#include <arpa/inet.h>

// Determines if system uses little-endian byte order
int isLittleEndian() {
    // Value 1 but occupies 4 bytes of memory
    unsigned int endianTestValue = 1;
    
    // Point to the first of those 4 bytes to check storage order
    unsigned char *firstBytePointer = (unsigned char *)&endianTestValue;
    
    return (*firstBytePointer == 1);
}

// Converts to Network Byte Order (big-endian)
unsigned int makeNBO(unsigned int value) {
    // htonl function --> host to network long (32-bit)
    // performs the byte swapping (if necessary)
    return htonl(value);
}