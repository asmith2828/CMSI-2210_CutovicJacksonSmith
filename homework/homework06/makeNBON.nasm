; ————————————————————————————————————————————————————————————————————————————————
; filename: makeNBON.nasm
; A 64-bit program for x86 MacOS that calls and tests the C-based makeNBO function
;
; Group Members:
; Stefan Cutovic
; Caroline Jackson
; Aidan Smith
;
; to assemble:    nasm -f macho64 makeNBON.nasm
; to link:        gcc makeNBON.o makeNBOC.c -o makeNBON
; to run:         ./makeNBON
; ————————————————————————————————————————————————————————————————————————————————

global _main
extern _makeNBO
extern _printf
extern _exit

section .data
    header      db "Testing makeNBO program (Problem 5) from assembly:", 10, 10, 0
    testFormat  db "Test %d: 0x%08X -> 0x%08X", 10, 0
    newline     db 10, 0

section .text

_main:
    push rbp
    mov rbp, rsp
    sub rsp, 16                        ; 16-byte alignment
    
    lea rdi, [rel header]
    xor rax, rax
    call _printf
    
    ; Test 1: 0x12345678
    mov rdi, 0x12345678
    call _makeNBO
    mov r12, rax                       ; save result
    
    lea rdi, [rel testFormat]
    mov rsi, 1
    mov rdx, 0x12345678
    mov rcx, r12
    xor rax, rax
    call _printf
    
    ; Test 2: 0x87654321
    mov rdi, 0x87654321
    call _makeNBO
    mov r12, rax
    
    lea rdi, [rel testFormat]
    mov rsi, 2
    mov rdx, 0x87654321
    mov rcx, r12
    xor rax, rax
    call _printf
    
    ; Test 3: 0xDEADBEEF
    mov rdi, 0xDEADBEEF
    call _makeNBO
    mov r12, rax
    
    lea rdi, [rel testFormat]
    mov rsi, 3
    mov rdx, 0xDEADBEEF
    mov rcx, r12
    xor rax, rax
    call _printf
    
    ; Test 4: 0xBEEFCAFE
    mov rdi, 0xBEEFCAFE
    call _makeNBO
    mov r12, rax
    
    lea rdi, [rel testFormat]
    mov rsi, 4
    mov rdx, 0xBEEFCAFE
    mov rcx, r12
    xor rax, rax
    call _printf
    
    ; Test 5: 0x00000001
    mov rdi, 0x00000001
    call _makeNBO
    mov r12, rax
    
    lea rdi, [rel testFormat]
    mov rsi, 5
    mov rdx, 0x00000001
    mov rcx, r12
    xor rax, rax
    call _printf
    
    ; Test 6: 0x10000000
    mov rdi, 0x10000000
    call _makeNBO
    mov r12, rax
    
    lea rdi, [rel testFormat]
    mov rsi, 6
    mov rdx, 0x10000000
    mov rcx, r12
    xor rax, rax
    call _printf
    
    ; Test 7: 0xFFFFFFFF
    mov rdi, 0xFFFFFFFF
    call _makeNBO
    mov r12, rax
    
    lea rdi, [rel testFormat]
    mov rsi, 7
    mov rdx, 0xFFFFFFFF
    mov rcx, r12
    xor rax, rax
    call _printf
    
    ; Test 8: 0xABCD1234
    mov rdi, 0xABCD1234
    call _makeNBO
    mov r12, rax
    
    lea rdi, [rel testFormat]
    mov rsi, 8
    mov rdx, 0xABCD1234
    mov rcx, r12
    xor rax, rax
    call _printf
    
    ; Test 9: 0x1234ABCD
    mov rdi, 0x1234ABCD
    call _makeNBO
    mov r12, rax
    
    lea rdi, [rel testFormat]
    mov rsi, 9
    mov rdx, 0x1234ABCD
    mov rcx, r12
    xor rax, rax
    call _printf
    
    lea rdi, [rel newline]
    xor rax, rax
    call _printf
    
    xor rdi, rdi                       ; exit code 0
    call _exit