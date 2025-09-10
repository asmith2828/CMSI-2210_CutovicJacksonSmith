# Problems for Assignment #2
## Learning Objectives
<blockquote>
1. One main learning outcome: drilling in some of the initial concepts from the first and second weeks<br />
2. Ancillary learning outcome: terms, definitions, people, etc. instrumental to computer systems
</blockquote>

Answers to the following questions can be found in the information on the course weekly pages for weeks one and two, or you can look them up on the Internet. If you do that, please include a link to where the answer came from. Try to answer in your own words, though, from your "head knowledge" because that will help you to really remember these rather than just regurgitating them for a grade.

## Questions

**1. What is a computer system?**<br />
A computer system is a set of layers within the computer. Each layer builds upon the functionality in the layer below it and provides functionality to the layer above it. The layers work together to process information, from the lowest hardware level up to high-level applications.

<br>

**2. What are some of the parts of a computer system?**<br />
Some parts include the Digital Logic layer (gates, circuitry, motherboards, chips), the Control layer (microcode and firmware), the Machine layer (binary instructions), and the Assembly Language layer (mnemonics and assembler instructions).

<br>

**3. What is the difference between a compiled language and an interpreted language?**<br />
Compiled languages translate the entire source file to machine code before execution, while interpreted languages translate code line-by-line during program execution.

<br>

**4. Is C a compiled language?**<br />
Yes, C is a compiled language that translates source code directly to binary machine code that the computer can execute.

<br>

**5. Who invented the C language?**<br />
Dennis Ritchie invented the C language.

<br>

**6. How long has C been in use?**<br />
The "C" language was created in 1972. As of 2025, it's been in use for over 50 years.

<br>

**7. Is a compiler a translator?**<br />
Yes, a compiler is a translator. It converts source code into assembly language or machine code that the computer can execute.

<br>

**8. Is an assembler a translator?**<br />
Yes, it translates from assembly language into machine language.

<br>

**9. What is the command to list out the contents of a directory on a mac terminal window?**<br />
The command is `ls`.

<br>

**10. What does the C function `atof()` do?**<br />
The function turns a character string into a floating point value.

<br>

**11. What are the bottom two layers of a computer system? Give a brief description of each.**<br />
- Digital Logic Layer: The actual hardware that the computer runs on (e.g., gates, circuits, and chips)<br />
- Control Layer: Contains low-level instructions built into the CPU that interpret machine language (microcode) that uses the hardware from the layer below it

<br>

**12. What are the three steps of the Von Neumann Architecture?**<br />
1. Fetch: The control unit retrieves the next instruction from memory; the instruction's address is stored in the program counter.<br />
2. Decode: The instruction is then decoded so the microcode can comprehend what it needs to do. This can include more retrievals from main memory to gather any additional data needed, which are then placed into registers in the CPU.<br />
3. Execute: The ALU uses the decoded instruction to execute the operation. The results may end up being placed back in main memory or in another register.

<br>

**13. What is the purpose of an ALU?**<br />
The Arithmetic Logic Unit (ALU) performs mathematical and bit-wise operations on integers.

<br>

**14. What is a register?**<br />
A register is a tiny and quick storage location that is used for immediate processing by the CPU.

<br>

**15. What is one difference between Application software and System software?**<br />
Application software serves human needs by handling everyday tasks like managing finances or playing games, while system software manages the computer's internal operations like memory allocation and hardware communication.

<br>

**16. Is the phrase `cmp rdi, rsi` machine language?**<br />
No, that phrase is assembly language. Machine language would either be the binary or hexadecimal representation of that instruction.

<br>

**17. How many buses are included in the system bus?**<br />
There are three: data bus, address bus, and control bus.

<br>

**18. What is the decimal value of 10010111₂?**<br />
(1×2⁰) + (1×2¹) + (1×2²) + (0×2³) + (1×2⁴) + (0×2⁵) + (0×2⁶) + (1×2⁷)<br />
= 1 + 2 + 4 + 0 + 16 + 0 + 0 + 128<br />
= 151

<br>

**19. What is the decimal value of 11111111₂?**<br />
(1×2⁷) + (1×2⁶) + (1×2⁵) + (1×2⁴) + (1×2³) + (1×2²) + (1×2¹) + (1×2⁰)<br />
= 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1<br />
= 255

 <br>

**20. What is the largest unsigned integer value that will fit into 16 bits?**<br />
16 bits can be represented as 2¹⁶ --> 65,536 different values<br />
Unsigned values --> range from 0 to 65,536<br />
Therefore, the largest unsigned integer value that will fit into 65 bits is 65,536.

<br>

## Evaluation Criteria for Homework 02
### "BOOK" PROBLEMS
- All questions worth one point each
- Total possible points: 20
- Remember to show your work for partial credit on calculation problems





