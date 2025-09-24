# Problems for Assignment #3 - Solutions
## Learning Objectives:
<blockquote>
  1. Understanding different number representations<br />
  2. Practice with the different common number bases used by computers<br />
  3. Practice translating values between different bases<br />
  4. Practice translating values between different representations<br />
  5. Practice/understanding of carry, overflow, saturated, and modular computer arithmetic
</blockquote>

Please do all these problems WITHOUT using a computer or calculator.

The purpose of these exercises is to help you develop your skill.

Taking the time to practice will give you a better ability and understanding of the material.

Remember that the prefix "0x" or "0X" indicates that a value is shown in hexadecimal [base 16].

## Problems

The problems in this section are very straightforward and should not be hard ~ you'll get good practice here!

**1. Hex FAC3 in binary is:**<br />
F = 1111 <br>
A = 1010 <br>
C = 1100 <br>
3 = 0011 <br>
FAC3₁₆ = 1111101011000011₂

<br>

**2. Hex FAC3 as an unsigned decimal is:**<br />
FAC3₁₆<br>
= (15×16³) + (10×16²) + (12×16¹) + (3×16⁰)<br />
= (15×4096) + (10×256) + (12×16) + (3×1)<br />
= 61,440 + 2,560 + 192 + 3<br />
= 64,195

<br>

**3. Hex FAC3 as a signed decimal is:**<br />
First bit is 1 (F = 1111) --> answer is negative in two's complement<br />
FAC3₁₆ = 1111101011000011₂<br />
To find negative value: invert bits and add 1<br />
Inverted: 0000010100111100₂<br />
W/ 1 added: 0000010100111101₂ = 053D₁₆<br />

Converting 053D₁₆ to decimal:<br />
053D₁₆<br /> 
= (0×16³) + (5×16²) + (3×16¹) + (13×16⁰)<br />
= (0×4096) + (5×256) + (3×16) + (13×1)<br />
= 0 + 1,280 + 48 + 13<br />
= 1,341₁₀<br />

Therefore: -1,341

<br>

**4. Hex 0064 in binary is:**<br />
0 = 0000<br />
0 = 0000<br />
6 = 0110<br />
4 = 0100<br />
0064₁₆ = 0000000001100100₂

<br>

**5. Hex 0064 as an unsigned decimal is:**<br />
0064₁₆<br />
= (0×16³) + (0×16²) + (6×16¹) + (4×16⁰)<br />
= 0 + 0 + 96 + 4<br />
= 100

<br>

**6. Hex 0064 as a signed decimal is:**<br />
First bit is 0 --> positive<br />

Converting 0064₁₆ to decimal:<br />
0064₁₆<br />
= (0×16³) + (0×16²) + (6×16¹) + (4×16⁰)<br />
= (0×4096) + (0×256) + (6×16) + (4×1)<br />
= 0 + 0 + 96 + 4<br />
= 100₁₀<br />

Therefore: 100

<br>

**7. Hex 8000 in binary is:**<br />
8 = 1000<br />
0 = 0000<br />
0 = 0000<br />
0 = 0000<br />
8000₁₆ = 1000000000000000₂

<br>

**8. Hex 8000 as an unsigned decimal is:**<br />
8000₁₆<br />
= (8×16³) + (0×16²) + (0×16¹) + (0×16⁰)<br />
= (8×4096) + 0 + 0 + 0<br />
= 32,768

<br>

**9. Hex 8000 as a signed decimal is:**<br />
First bit is 1 (8 = 1000) --> most negative 16-bit number<br />
Special case in two's complement:<br />
8000₁₆ = -32,768₁₀

<br>

**10. Decimal 8000 encoded in 16-bits (unsigned) is in hex:**<br />
8000₁₀ ÷ 16 = 500 remainder 0<br />
500 ÷ 16 = 31 remainder 4<br />
31 ÷ 16 = 1 remainder 15 (F)<br />
1 ÷ 16 = 0 remainder 1<br />

Reading remainders from bottom to top:<br />
Last remainder: 1<br />
Next remainder: 15 → F<br />
Next remainder: 4<br />
First remainder: 0<br />
= 0x1F40

<br>

**11. Decimal 8000 encoded in 16-bits (signed) is in hex:**<br />
16-bit signed range: -32,768 to 32,767<br />
8000 → positive number<br />
8000 < 32,767 → fits within range<br />
Since 8000 is positive and fits in 16 bits signed → same encoding as unsigned<br />

Converting 8000₁₀ to hex:<br />
8000₁₀ ÷ 16 = 500 remainder 0<br />
500 ÷ 16 = 31 remainder 4<br />
31 ÷ 16 = 1 remainder 15 (F)<br />
1 ÷ 16 = 0 remainder 1<br />

Reading remainders upward: 1F40₁₆<br />
= 0x1F40

<br>

**12. Decimal -11 encoded in 16-bits (signed) is in hex:**<br />
11₁₀ 
= 000B₁₆ 
= 0000000000001011₂<br />

Two's complement: inverting bits → 1111111111110100₂<br />
W/ 1 added: 1111111111110101₂ 
= FFF5₁₆<br />
= 0xFFF5

<br>

**13. Decimal -32717 encoded in 16-bits (signed) is in hex:**<br />
32717₁₀ to hex:<br />
32717₁₀ ÷ 16 = 2044 remainder 13 (D)<br />
2044 ÷ 16 = 127 remainder 12 (C)<br />
127 ÷ 16 = 7 remainder 15 (F)<br />
7 ÷ 16 = 0 remainder 7<br />

Reading remainders upward:<br />
32717₁₀ = 7FCD₁₆<br />

7FCD₁₆ to binary:<br />
7 = 0111<br />
F = 1111<br />
C = 1100<br />
D = 1101<br />
7FCD₁₆ = 0111111111001101₂<br />

Two's complement: inverting 0111111111001101₂ → 1000000000110010₂<br />
W/ 1 added: 1000000000110011₂<br />
= 8033₁₆<br />
= 0x8033

<br>

**14. Binary 10111101 in hex is:**<br />
1011₂ = B₁₆<br />
1101₂ = D₁₆<br />
= 0xBD

<br>

**15. Binary 1011110100000001 as an unsigned decimal is:**<br />
1011110100000001₂<br />
= (1×2¹⁵) + (0×2¹⁴) + (1×2¹³) + (1×2¹²) + (1×2¹¹) + (1×2¹⁰) + (0×2⁹) + (1×2⁸) + (0×2⁷) + (0×2⁶) + (0×2⁵) + (0×2⁴) + (0×2³) + (0×2²) + (0×2¹) + (1×2⁰)<br />
= 32,768 + 8,192 + 4,096 + 2,048 + 1,024 + 256 + 1<br />
= 48,385

<br>

**16. Binary 1011110100000001 as a signed decimal is:**<br />
First bit is 1 --> negative<br />
Inverted: 0100001011111110₂<br />
W/ 1 added: 0100001011111111₂<br />
= 17,151₁₀<br />
Therefore: -17,151

<br>

**17. If we had 20-bit registers, the smallest signed decimal integer value would be:**<br />
Range for n-bit signed: -2^(n-1) to 2^(n-1)-1<br />
For 20 bits: n = 20, so n-1 = 19<br />
Smallest value = -2¹⁹<br />
2¹⁹ = 524,288<br />

Therefore: -2¹⁹ = -524,288

<br>

**18. If we had 20-bit registers, the largest signed decimal integer value would be:**<br />
2¹⁹ - 1<br />
= 524,288 - 1<br />
= 524,287

<br>

**19. The modular sum of 16-bit hex values 3511 + 4FFC is:**<br />
3511₁₆<br />
4FFC₁₆<br />
-------<br />
850D₁₆<br />

Rightmost: 1 + C = 1 + 12 = 13 = D (no carry)<br />
Next: 1 + F = 1 + 15 = 16 = 10₁₆ → 0 with carry 1<br />
Next: 5 + F + 1(carry) = 5 + 15 + 1 = 21 = 15₁₆ → 5 with carry 1<br />
Leftmost: 3 + 4 + 1(carry) = 8 (no carry)<br />

= 0x850D

<br>

**20. The saturated sum of 16-bit hex values 3511 + 4FFC is:**<br />
3511₁₆ = 0011010100010001₂ (16 bits)<br />
4FFC₁₆ = 0100111111111100₂ (16 bits)<br />
Sum = 1000010100001101₂ = 850D₁₆ (16 bits)<br />
Result fits exactly in 16 bits --> no saturation needed<br />
= 0x850D

<br>

**21. The 16-bit operation 0x3511 + 0x4FFC has a carry (Y or N):**<br />
3511₁₆ = 0011010100010001₂ (16 bits)<br />
4FFC₁₆ = 0100111111111100₂ (16 bits)<br />
Sum = 1000010100001101₂ = 850D₁₆ (16 bits)<br />
Result fits in 16 bits → no carry beyond bit 15<br />
= N

<br>

**22. The 16-bit operation 0x3511 + 0x4FFC has overflow (Y or N):**<br />
3511₁₆ = 0011010100010001₂ (positive: MSB = 0)<br />
4FFC₁₆ = 0100111111111100₂ (positive: MSB = 0)<br />
Sum = 1000010100001101₂ = 850D₁₆ (negative: MSB = 1)<br />
Positive + Positive = Negative → overflow<br />
= Y

<br>

## More Complex Problems

**23. The modular sum of 16-bit hex values 6159 + F702 is:**<br />
6159₁₆<br />
F702₁₆<br />
-------<br />
1585B₁₆<br />

Rightmost: 9 + 2 = 11 = B (no carry)<br />
Next: 5 + 0 = 5 (no carry)<br />
Next: 1 + 7 = 8 (no carry)<br />
Leftmost: 6 + F = 6 + 15 = 21 = 15₁₆ → 5 with carry 1<br />
Final carry: 1<br />

Result: 1585B₁₆<br />
Truncated to 16 bits: 585B₁₆<br />
= 0x585B

<br>

**24. The saturated sum of 16-bit hex values 6159 + F702 is:**<br />
6159₁₆ = 0110000101011001₂ (positive: MSB = 0)<br />
F702₁₆ = 1111011100000010₂ (negative: MSB = 1)<br />
Sum = 0101100001011011₂ = 585B₁₆ (positive: MSB = 0)<br />
Result fits in 16-bit signed range --> no saturation<br />
= 0x585B

<br>

**25. The 16-bit operation 0x6159 + 0xF702 has a carry (Y or N):**<br />
6159₁₆ = 0110000101011001₂ (16 bits)<br />
F702₁₆ = 1111011100000010₂ (16 bits)<br />
Sum = 10101100001011011₂ = 1585B₁₆ (17 bits)<br />
Result requires 17 bits → carry beyond bit 15<br />
= Y

<br>

**26. The 16-bit operation 0x6159 + 0xF702 has overflow (Y or N):**<br />
6159₁₆ = 0110000101011001₂ (positive: MSB = 0)<br />
F702₁₆ = 1111011100000010₂ (negative: MSB = 1)<br />
Sum = 0101100001011011₂ = 585B₁₆ (positive: MSB = 0)<br />
Positive + Negative = Positive → No overflow possible<br />
= N

<br>

**27. The modular sum of 16-bit hex values EEEE + C00C is:**<br />
EEEE₁₆<br />
C00C₁₆<br />
-------<br />
1AEFA₁₆<br />

Rightmost: E + C = 14 + 12 = 26 = 1A₁₆ → A with carry 1<br />
Next: E + 0 + 1(carry) = 14 + 0 + 1 = 15 = F (no carry)<br />
Next: E + 0 = 14 + 0 = 14 = E (no carry)<br />
Leftmost: E + C = 14 + 12 = 26 = 1A₁₆ → A with carry 1<br />
Final carry: 1<br />

Result: 1AEFA₁₆ (17 bits)<br />
Truncated to 16 bits: 1AEFA₁₆ → AEFA₁₆<br />
= 0xAEFA

<br>

**28. The saturated sum of 16-bit hex values EEEE + C00C is:**<br />
EEEE₁₆ = 1110111011101110₂ (negative: MSB = 1)<br />
C00C₁₆ = 1100000000001100₂ (negative: MSB = 1)<br />
Sum = 1010111011111010₂ = AEFA₁₆ (negative: MSB = 1)<br />
Result fits in 16-bit signed range --> no saturation<br />
= 0xAEFA

<br>

**29. The 16-bit operation 9EEE + AB0C has a carry (Y or N):**<br />
9EEE₁₆<br />
AB0C₁₆<br />
-------<br />
149FA₁₆<br />

Rightmost: E + C = 14 + 12 = 26 = 1A₁₆ → A with carry 1<br />
Next: E + 0 + 1(carry) = 14 + 0 + 1 = 15 = F (no carry)<br />
Next: E + B = 14 + 11 = 25 = 19₁₆ → 9 with carry 1<br />
Leftmost: 9 + A + 1(carry) = 9 + 10 + 1 = 20 = 14₁₆ → 4 with carry 1<br />
Final carry: 1<br />

Result: 149FA₁₆ (17 bits)<br />
Carry beyond 16th bit<br />
= Y

<br>

**30. The 16-bit operation 9EEE + AB0C has overflow (Y or N):**<br />
9EEE₁₆ = 1001111011101110₂ (negative: MSB = 1)<br />
AB0C₁₆ = 1010101100001100₂ (negative: MSB = 1)<br />
Sum = 0100100111111010₂ = 49FA₁₆ (positive: MSB = 0)<br />
Negative + Negative = Positive → overflow<br />
= Y

<br>

**31. The negation of 16-bit word 0xB00F is:**<br />
B00F₁₆ = 1011000000001111₂<br />
Inverted bits: 0100111111110000₂<br />
W/ 1 added: 0100111111110001₂<br />
= 4FF1₁₆<br />
= 0x4FF1

<br>

**32. The negation of 16-bit word 0x2232 is:**<br />
2232₁₆ = 0010001000110010₂<br />
Inverted bits: 1101110111001101₂<br />
W/ 1 added: 1101110111001110₂<br />
= DDCE₁₆<br />
= 0xDDCE

<br>

**33. The negation of 16-bit word 0x8000 is:**<br />
8000₁₆ = -32,768₁₀ (most negative 16-bit number)<br />
-(-32,768) = +32,768<br />
+32,768 exceeds 16-bit signed range (max = +32,767)<br />
-(32,768) negates to itself (two's complement)<br />
= 0x8000

<br>

**34. The negation of 32-bit word 0xFFF329BA is:**<br />
FFF329BA₁₆ = 11111111111100110010100110111010₂<br />

Inverted bits:<br />
11111111111100110010100110111010₂ → 00000000000011001101011001000101₂<br />

W/ 1 added:<br />
00000000000011001101011001000101₂ + 1₂ = 00000000000011001101011001000110₂<br />

Convert to hex:<br />
00000000000011001101011001000110₂ = 000CD646₁₆<br />

= 0x000CD646

<br>

**35-38. IEEE-754 Float Problems:**<br />
*These require detailed IEEE-754 format knowledge and are quite complex. The format is:*<br />
*Sign (1 bit) | Exponent (8 bits) | Mantissa (23 bits)*

**35. 96.03125 as a 32-bit float, in hex is:**<br />

Convert 96.03125 to binary:<br />
Integer part: 96₁₀ = 1100000₂<br />

Repeated division by 2:<br />
96 ÷ 2 = 48 remainder 0<br />
48 ÷ 2 = 24 remainder 0<br />
24 ÷ 2 = 12 remainder 0<br />
12 ÷ 2 = 6 remainder 0<br />
6 ÷ 2 = 3 remainder 0<br />
3 ÷ 2 = 1 remainder 1<br />
1 ÷ 2 = 0 remainder 1<br />

Reading remainders upward: 1100000₂<br />

Fractional part: 0.03125₁₀ = 0.00001₂<br />
0.03125 × 2 = 0.0625 → integer part: 0<br />
0.0625 × 2 = 0.125 → integer part: 0<br />
0.125 × 2 = 0.25 → integer part: 0<br />
0.25 × 2 = 0.5 → integer part: 0<br />
0.5 × 2 = 1.0 → integer part: 1<br />
Reading integer parts downward: 0.00001₂<br />
Verification: 0.03125 = 1/32 = 1/2⁵ = 0.00001₂<br />

Combined: 96.03125₁₀ = 1100000.00001₂<br />

Normalization:<br />
1100000.00001₂ = 1.10000000001₂ × 2⁶<br />

Determine IEEE-754 components:<br />
Sign bit: 0 (positive)<br />
Exponent: 6 + 127 = 133₁₀ = 10000101₂<br />
Mantissa: 10000000001000000000000₂ (23 bits, leading 1 is dropped)<br />

Combine components:<br />
0 10000101 10000000001000000000000₂<br />

Convert to hex:<br />
01000010 11000000 00010000 00000000₂<br />
= 42C01000₁₆<br />
= 0x42C01000

<br>

**36. -16777216 as a 32-bit float, in hex is:**<br />

Convert 16777216 to binary:<br />
16777216₁₀ = 2²⁴ = 1000000000000000000000000₂<br />

Normalization:<br />
1000000000000000000000000₂ = 1.0₂ × 2²⁴<br />

Determine IEEE-754 components:<br />
Sign bit: 1 (negative)<br />
Exponent: 24 + 127 = 151₁₀ = 10010111₂<br />
Mantissa: 00000000000000000000000₂ (23 bits, all zeros since 1.0)<br />

Combine components:<br />
1 10010111 00000000000000000000000₂<br />

Convert to hex:<br />
11001011 10000000 00000000 00000000₂<br />
= CB800000₁₆<br />
= 0xCB800000

<br>

**37. Hex 43700000, when interpreted as an IEEE-754 pattern, is in decimal:**<br />

Convert hex to binary:<br />
43700000₁₆ = 01000011011100000000000000000000₂<br />

Break into IEEE-754 components:<br />
Sign bit: 0 (positive)<br />
Exponent: 10000110₂ = 134₁₀<br />
Mantissa: 11100000000000000000000₂<br />

Calculate exponent:<br />
134 - 127 = 7<br />

Reconstruct normalized form:<br />
Mantissa with leading 1: 1.11100000000000000000000₂<br />
Scientific notation: 1.111₂ × 2⁷<br />

Convert to decimal:<br />
1.111₂ = 1 + 1/2 + 1/4 + 1/8 = 1 + 0.5 + 0.25 + 0.125 = 1.875₁₀<br />
Final value: 1.875 × 2⁷ = 1.875 × 128 = 240₁₀<br />

= 240

<br>

**38. Hex C0FF0000, when interpreted as an IEEE-754 pattern, is in decimal:**<br />

Convert hex to binary:<br />
C0FF0000₁₆ = 11000000111111110000000000000000₂<br />

Break into IEEE-754 components:<br />
Sign bit: 1 (negative)<br />
Exponent: 10000001₂ = 129₁₀<br />
Mantissa: 11111110000000000000000₂<br />

Calculate exponent:<br />
129 - 127 = 2<br />

Reconstruct normalized form:<br />
Mantissa with leading 1: 1.11111110000000000000000₂<br />
Scientific notation: 1.1111111₂ × 2²<br />

Convert to decimal:<br />
1.1111111₂ = 1 + 1/2 + 1/4 + 1/8 + 1/16 + 1/32 + 1/64 + 1/128<br />
= 1 + 0.5 + 0.25 + 0.125 + 0.0625 + 0.03125 + 0.015625 + 0.0078125<br />
= 1.9921875₁₀<br />
Final value: 1.9921875 × 2² = 1.9921875 × 4 = 7.96875₁₀<br />
Sign bit = 1: -(7.96875₁₀)<br />

= -7.96875

<br>

## Optional Extra Credit Problems

**39. The largest finite IEEE-754 single precision float, in hex is:**<br />
For largest finite positive value:<br />
Sign bit: 0 (positive)<br />
Exponent: 11111110₂ = 254₁₀ (largest: 11111111₂ = 255₁₀)<br />
Mantissa: 11111111111111111111111₂ (all 23 bits set to 1)<br />

Combine components:<br />
0 11111110 11111111111111111111111₂<br />

Convert to hex:<br />
01111111 01111111 11111111 11111111₂<br />
= 7F7FFFFF₁₆<br />

= 0x7F7FFFFF

<br>

**40-46. Additional IEEE-754 Problems:**<br />
*[These are marked as optional extra credit and require advanced IEEE-754 knowledge]*

<br>

## Evaluation Criteria for Homework 03
### "CALCULATION" PROBLEMS
  - All questions worth one point each
  - Total possible points: 46
  - Remember to show your work for partial credit on calculation problems
  - Yes, you can get 0.5 point for trying, even if the answer is wrong
  

















