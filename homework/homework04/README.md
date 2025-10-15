# Problems for Assignment #4
## Learning Outcomes
<blockquote>
  1. Practice creating logic diagram models from truth table and text descriptions<br />
  2. Practice with manipulating register contents using various operations<br />
  3. Practice writing and interpreting assembly language programs<br />
</blockquote>

1. Consider the function with three inputs (A,B,C) and two outputs (X,Y) that works like this:
<pre>
               A  B  C | X  Y
              ---------+------
               0  0  0 | 0  1
               0  0  1 | 0  1
               0  1  0 | 0  1
               0  1  1 | 1  1
               1  0  0 | 1  0
               1  0  1 | 1  1
               1  1  0 | 1  0
               1  1  1 | 1  1
</pre>
    Design two logic circuits for this function
       A) one using AND, OR and NOT gates only, and
       B) one using NAND gates only. Do NOT draw the circuit
    Just write two formulas ~ one for computing <code>X</code> and one for computing <code>Y</code>.

***Problem 1 Response***

A) Using AND, OR, and NOT

X = A + (B·C) <br>
Y = A' + C <br>

B) Using NAND Only

X = ( A' · (B·C)' )' <br>
Y = ( A · C' )' <br>

---

2. Draw a logic circuit that compares two 2-bit signed numbers as follows: It should have four inputs a1, a0, b1, and b0. a1a0 is a 2-bit signed number (call it a) and b1b0 is a 2-bit signed number (call it b). The circuit has one output, c, which is 1 if a > b and 0 otherwise.

***Problem 2 Response***

Inputs: a1 a0 b1 b0

Output: c = 1 if (a > b), else 0

c = (a1'·a0'·b1·b0') + (a1'·a0'·b1·b0) + (a1'·a0·b1'·b0') + (a1'·a0·b1·b0') + (a1'·a0·b1·b0) + (a1·a0·b1·b0')

---

3. Given a 32-bit register, write logic instructions to perform the following operations. For parts (c) and (f) assume an unsigned interpretation; for part (d) assume a signed interpretation. <br>

***Problem 3 Responses***

a) Clear all even-numbered bits (bit 0 is LSB) **———>** R = R AND 0xAAAAAAAA

b) Set the last three bits **———>** R = R OR 0x7

c) Compute the remainder when divided by 8 (unsigned) **———>** R = R AND 0x7

d) Make the value -1 (signed) **———>** R = 0xFFFFFFFF

e) Complement the two highest-order bits **———>** R = R XOR 0xC0000000

f) Compute the largest multiple of 8 less than or equal to R (unsigned) **———>** R = R AND 0xFFFFFFF8

---

4. Write a simple C program to play the game fizz-buzz. This game lists all integer numbers from one to N in order, except for the following cases:
- if a number is divisible by 3 the program should print fizz
- if a number is divisible by 5 the program should print buzz
- if a number is divisible by both 3 AND 5 the program should print fizz-buzz
- all other cases should simply print the number

Make your program ask the user for the value of N. Be sure to check for errors in the entry; for example, entering a zero or a negative number.

***Problem 4 Response***

```c
#include <stdio.h>

int main() {
    int N;

    printf("Enter a positive integer N: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("ERROR: Inputted number is NOT a positive integer greater than zero.\n");
        return 1; // Exit
    }

    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("fizz-buzz\n");
        } else if (i % 3 == 0) {
            printf("fizz\n");
        } else if (i % 5 == 0) {
            printf("buzz\n");
        } else {
            printf("%d\n", i);
        }
    }

    return 0;
}
```

---

5. For the sample Stanley/Penguin single-accumulator computer discussed in class, write a complete assembly language program in the Stanley/Penguin language that sends the values 0 through 255 out to port 0x8. NOTE: the machine code for this will be written in the next problem.

***Problem 5 Response***

```assembly
JMP start
counter: 0
one:     1
limit:   256

start:  LOAD [counter]
        WRITE 8
        ADD [one]
        STORE [counter]
        SUB [limit]
        JLZ start
end:    JMP end
```

---

6. Translate your Stanley/Penguin language program in the previous problem to machine language.

***Problem 6 Response***

```
Assembly:                 Address:  Machine Code:
JMP start                   0x0:     C0000004
counter: 0                  0x1:     00000000
one: 1                      0x2:     00000001
limit: 256                  0x3:     00000100
start: LOAD [counter]       0x4:     00000001
WRITE 8                     0x5:     30000008
ADD [one]                   0x6:     40000002
STORE [counter]             0x7:     10000001
SUB [limit]                 0x8:     50000003
JLZ start                   0x9:     E0000004
end: JMP end                0xA:     C000000A
```

---

7. For the sample single-accumulator computer discussed in class, write a complete assembly language program in the stanley/penguin language that computes a greatest common divisor. Assume the two inputs are read in from port 0x100. Write the result to port 0x200. You do not need to write machine code for this problem.

***Problem 7 Response***

```assembly
JMP start
firstnum: 0
secondnum: 0
tempstorage: 0

start:  READ 0x100
        STORE [firstnum]
        READ 0x100
        STORE [secondnum]

loop:   LOAD [secondnum]
        JZ done
        STORE [tempstorage]
        LOAD [firstnum]
        MOD [secondnum]
        STORE [secondnum]
        LOAD [tempstorage]
        STORE [firstnum]
        JMP loop

done:   LOAD [firstnum]
        WRITE 0x200
end:    JMP end
```

---

8. For the sample single-accumulator computer discussed in class, give a code fragment, in assembly language of the stanley/penguin language, that swaps the accumulator and memory address 0x30AA. You do not need to write machine code for this problem.

***Problem 8 Response***

```assembly
saved_accum: 0
saved_mem: 0

        STORE [saved_accum]
        LOAD [0x30AA]
        STORE [saved_mem]
        LOAD [saved_accum]
        STORE [0x30AA]
        LOAD [saved_mem]
```

---

9. For the sample single-accumulator computer discussed in class, give a code fragment, in assembly language of the stanley/penguin language that has the effect of jumping to the code at address 0x837BBE1 if the value in the accumulator is greater than or equal to 0. You do not need to write machine code for this problem.

***Problem 9 Response***

```assembly
        JGZ 0x837BBE1
        JZ 0x837BBE1
                            ; If A < 0 --> continues to next instruction
```

---

10a. Explain, at a high-level, what the following sequence of instructions does. In other words, suppose a programmer has stored data in r8 and r9. After executing these instructions, what does the programmer notice about the data?

***Problem 10a Response***

The values in r8 and r9 have been swapped without using any temporary storage location/register, leaving r8 holding the original value of r9 and r9 holding the original value of r8.

---

10b. Also state as briefly as possible why that effect happens.

***Problem 10b Response***

This effect happens because the first XOR combines both values into one register; the following XORs use the property that XOR'ing with the same value twice cancels out, allowing each original value to be extracted and placed into the opposite register.

---


## Evaluation Criteria for Homework 04
#### LOGIC DESIGN
  - Question 1a: logic design           10 pts.
  - Question 1b: logic design            5 pts.
  - Question 2: logic design            10 pts.
#### REGISTER OPERATIONS
  - Question 3a: Reg. clear even         2 pts.
  - Question 3b: Reg. set last 3         2 pts.
  - Question 3c: Reg./8 remainder        2 pts.
  - Question 3d: Reg. set to -1          2 pts.
  - Question 3e: Reg. invert 2 MSBs      2 pts.
  - Question 3f: Register computation    2 pts.
#### ASSEMBLY PROGRAMS
  - Question 4: asm program 1a          11 pts.
  - Question 5: asm program 1b          11 pts.
  - Question 6: asm GCD prog.           11 pts.
  - Question 7: asm swap code fragment   5 pts.
  - Question 8: asm jmp to address       5 pts.
  - Question 9a: explain what it does    5 pts.
  - Question 9b: explain why it happens  5 pts.

Total possible points: 90
