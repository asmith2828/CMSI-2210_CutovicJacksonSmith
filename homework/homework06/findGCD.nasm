; ————————————————————————————————————————————————————————————————————————————————
; A 64-bit program for MacOS that reads two integers and computes their GCD
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
    input_fmt   db "%lld", 0          ; format for reading 64-bit integers
    output_fmt  db "%lld", 10, 0      ; format for output with newline

section .bss
    num1    resq 1                     ; reserve space for first number
    num2    resq 1                     ; reserve space for second number

section .text

; GCD function using Euclidean algorithm
; Input: rdi = a, rsi = b
; Output: rax = gcd(a, b)
gcd:
    push rbp
    mov rbp, rsp
    
    mov rax, rdi                       ; rax = a
    mov rbx, rsi                       ; rbx = b
    
.loop:
    cmp rbx, 0                         ; if b == 0
    je .done                           ; we're done
    
    xor rdx, rdx                       ; clear rdx for division
    div rbx                            ; rax = rax / rbx, rdx = remainder
    
    mov rax, rbx                       ; a = b
    mov rbx, rdx                       ; b = remainder
    jmp .loop
    
.done:
    pop rbp
    ret

_main:
    push rbp
    mov rbp, rsp
    sub rsp, 16                        ; align stack (macOS requires 16-byte alignment)
    
    ; Read first number
    lea rsi, [rel num1]                ; address of num1
    lea rdi, [rel input_fmt]           ; format string
    xor rax, rax                       ; no floating point args
    call _scanf
    
    ; Read second number
    lea rsi, [rel num2]                ; address of num2
    lea rdi, [rel input_fmt]           ; format string
    xor rax, rax
    call _scanf
    
    ; Load the two numbers
    mov rdi, [rel num1]                ; first argument in rdi
    mov rsi, [rel num2]                ; second argument in rsi
    
    ; Call gcd function
    call gcd
    
    ; Print the result (result is in rax)
    mov rsi, rax                       ; move result to rsi for printf
    lea rdi, [rel output_fmt]          ; format string
    xor rax, rax                       ; no floating point args
    call _printf
    
    ; Exit cleanly
    xor rdi, rdi                       ; exit code 0
    call _exit