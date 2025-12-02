; ————————————————————————————————————————————————————————————————————————————————
; filename: findGCDfunc.nasm
; A C-callable 64-bit function for x86 MacOS that computes the GCD of two positive integers
;
; Group Members:
; Stefan Cutovic
; Caroline Jackson
; Aidan Smith
;
; to assemble:    nasm -f macho64 findGCDfunc.nasm
; ————————————————————————————————————————————————————————————————————————————————

global _findGCD

section .text

_findGCD:
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