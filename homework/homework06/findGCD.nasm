; findGCD.nasm
; reads two decimal integers from keyboard (stdin)
; computes their gcd and prints the result
; answers problem 1, but not callable from C
; Problem 2 code that is callable from C in file called "findGCDfromC.nasm"

global _main
extern printf
extern gets
extern atoi

section .bss
    buf1    resb 32
    buf2    resb 32

section .data
    fmtOut  db "%d", 10, 0

section .text

; gcd(a, b) → eax
gcd:
    push ebp
    mov  ebp, esp

    mov eax, [ebp+8]     ; a
    mov ebx, [ebp+12]    ; b

again:
    cmp ebx, 0
    je  done
    xor edx, edx
    div ebx
    mov eax, ebx
    mov ebx, edx
    jmp again

done:
    pop ebp
    ret

; main program
_main:
    push ebp
    mov  ebp, esp

    ; read first number
    push buf1
    call gets
    add esp, 4

    ; read second number
    push buf2
    call gets
    add esp, 4

    ; convert to ints
    push buf1
    call atoi
    add esp, 4
    mov esi, eax

    push buf2
    call atoi
    add esp, 4
    mov edi, eax

    ; compute gcd(esi, edi)
    push edi
    push esi
    call gcd
    add esp, 8

    ; print result
    push eax
    push fmtOut
    call printf
    add esp, 8

    mov esp, ebp
    pop ebp
    ret

