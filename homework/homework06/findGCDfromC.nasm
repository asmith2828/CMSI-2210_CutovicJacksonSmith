; findGCDfunc.nasm
; Provides: uint32_t gcd(uint32_t a, uint32_t b)
; callable from C version of findGCD.nasm

global gcd

section .text

; gcd(a, b) → eax
; C calling convention: a = [esp+4], b = [esp+8]
gcd:
    push ebp
    mov  ebp, esp

    mov eax, [ebp+8]     ; a
    mov ebx, [ebp+12]    ; b

again:
    cmp ebx, 0
    je  done
    xor edx, edx         ; clear edx before div
    div ebx              ; eax ÷ ebx → quotient in eax, remainder in edx
    mov eax, ebx         ; a = b
    mov ebx, edx         ; b = remainder
    jmp again

done:
    pop ebp
    ret
