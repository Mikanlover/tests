BITS 64
section .text
global strlen

strlen:
    xor rcx, rcx

.loop:
    cmp byte [rdi + rcx], 0
    je .done
    inc rcx
    jmp .loop

.done:
    mov rax, rcx
    ret