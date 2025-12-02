// ————————————————————————————————————————————————————————————————————————————————
// filename: gcdFinder.c
// A 64-bit program for x86 MacOS that tests the findGCD assembly function
//
// Group Members:
// Stefan Cutovic
// Caroline Jackson
// Aidan Smith
//
// to compile:    nasm -f macho64 findGCDfunc.nasm
//                gcc gcdFinder.c findGCDfunc.o -o gcdFinder
// to run:        ./gcdFinder
// ————————————————————————————————————————————————————————————————————————————————
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

extern long long findGCD(long long a, long long b);

int main() {
    // TEST CASE 1 --> provided test case
    long long result1 = findGCD(3113041662LL, 11570925LL);
    printf("GCD(3113041662, 11570925) = %lld\n", result1);
    assert(result1 == 462837);
    
    // TEST CASE 2 --> one of the inputted numbers is 1
    long long result2 = findGCD(25, 1);
    printf("GCD(25, 1) = %lld\n", result2);
    assert(result2 == 1);
    
    // TEST CASE 3 --> both inputted numbers are the same
    long long result3 = findGCD(77, 77);
    printf("GCD(77, 77) = %lld\n", result3);
    assert(result3 == 77);
    
    // TEST CASE 4 --> small numbers
    long long result4 = findGCD(56, 98);
    printf("GCD(56, 98) = %lld\n", result4);
    assert(result4 == 14);
    
    // TEST CASE 5 --> larger numbers
    long long result5 = findGCD(1530, 765);
    printf("GCD(1530, 765) = %lld\n", result5);
    assert(result5 == 765);
    
    // TEST CASE 6 --> prime numbers
    long long result6 = findGCD(29, 31);
    printf("GCD(29, 31) = %lld\n", result6);
    assert(result6 == 1);
    
    printf("\nAll tests passed. (6/6)\n");
    exit(0);
}