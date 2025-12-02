; ————————————————————————————————————————————————————————————————————————————————
; filename: paritygen.nasm
; A 64-bit program for x86 MacOS that displays the odd parity bit for a byte
;
; Group Members:
; Stefan Cutovic
; Caroline Jackson
; Aidan Smith
;
; to assemble:    nasm -f macho64 paritygen.nasm
; to link:        gcc paritygen.o -o paritygen
; to run:         ./paritygen
; ————————————————————————————————————————————————————————————————————————————————

global _main
extern _printf
extern _scanf
extern _exit

section .data
    outputFormat  db "%d", 10, 0
    inputFormat   db "%d", 0
    
section .bss
    inputByte  resq 1

section .text

calculateParity:
    push rbp
    mov rbp, rsp
    
    xor rax, rax                       ; counter for 1 bits
    mov rcx, 8                         ; 8 bits to check
    mov rbx, rdi                       ; copies byte to rbx
    
countLoop:
    test rbx, 1                        ; tests least significant bit
    jz skip                            ; if 0, skip increment
    inc rax                            ; increment counter if bit is 1
    
skip:
    shr rbx, 1                         ; shifts right to check next bit
    loop countLoop                     ; decrements rcx and loop
    
    test rax, 1                        ; checks if count is odd
    jnz oddCount                       ; if odd, jump
    
    mov rax, 1                         ; even count, parity bit = 1
    jmp done
    
oddCount:
    xor rax, rax                       ; odd count, parity bit = 0
    
done:
    pop rbp
    ret

_main:
    push rbp
    mov rbp, rsp
    sub rsp, 16                        ; 16-byte alignment (per MacOS regulations)
    
    lea rsi, [rel inputByte]           ; destination for input
    lea rdi, [rel inputFormat]         ; format specifier
    xor rax, rax
    call _scanf
    
    mov rdi, [rel inputByte]
    call calculateParity
    
    mov rsi, rax                       ; moves result for printf purposes
    lea rdi, [rel outputFormat]
    xor rax, rax
    call _printf
    
    xor rdi, rdi                       ; exit code 0
    call _exit