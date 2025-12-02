; ————————————————————————————————————————————————————————————————————————————————
; filename: findGCD.nasm
; A 64-bit program for x86 MacOS that reads two positive integers and computes their GCD
;
; Group Members:
; Stefan Cutovic
; Caroline Jackson
; Aidan Smith
;
; to assemble:    nasm -f macho64 findGCD.nasm
; to link:        gcc findGCD.o -o findGCD
; to run:         ./findGCD
; ————————————————————————————————————————————————————————————————————————————————

global _main
extern _printf
extern _scanf
extern _exit

section .data
    inputFormat   db "%lld", 0
    outputFormat  db "%lld", 10, 0

section .bss
    firstNumber    resq 1
    secondNumber    resq 1

section .text

gcd:
    push rbp
    mov rbp, rsp
    
    mov rax, rdi                       ; rax --> a
    mov rbx, rsi                       ; rbx --> b
    
loop:
    cmp rbx, 0                         ; if b is 0
    je done                            ; we've reached the end
    
    xor rdx, rdx                       ; clears rdx for division
    div rbx                            ; rax = rax/rbx, rdx is now remainder
    
    mov rax, rbx                       ; a --> b
    mov rbx, rdx                       ; b --> remainder
    jmp loop
    
done:
    pop rbp
    ret

_main:
    push rbp
    mov rbp, rsp
    sub rsp, 16                        ; 16-byte alignment, supposedly required by MacOS(?)
    
    lea rsi, [rel firstNumber]         ; destination for input
    lea rdi, [rel inputFormat]         ; format specifier
    xor rax, rax                       ; sets rax to 0 --> not passing any floating-point numbers
    call _scanf
    
    lea rsi, [rel secondNumber]        ; address of secondNumber
    lea rdi, [rel inputFormat]         ; formats string
    xor rax, rax
    call _scanf
    
    mov rdi, [rel firstNumber]
    mov rsi, [rel secondNumber]
    
    call gcd
    
    mov rsi, rax                       ; moves result for printf purposes
    lea rdi, [rel outputFormat]
    xor rax, rax
    call _printf
    
    xor rdi, rdi                       ; exit code 0
    call _exit