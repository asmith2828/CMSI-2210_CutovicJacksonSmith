#include <stdio.h>
#include <stdint.h>
#include <assert.h>

extern uint32_t gcd(uint32_t a, uint32_t b);

int main() {
    uint32_t a = 3113041662U;
    uint32_t b = 11570925U;

    uint32_t g = gcd(a, b);

    printf("GCD(%u, %u) = %u\n", a, b, g);

    // Assertions (use values you know are correct)
    assert(gcd(10, 5) == 5);
    assert(gcd(27, 18) == 9);
    assert(gcd(3113041662U, 11570925U) == g); // self-consistency

    printf("All asserts passed.\n");

    return 0;
}
