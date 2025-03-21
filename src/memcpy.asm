BITS 64
section .text
global memcpy

memcpy:
    xor rcx, rcx

.loop:
    cmp rcx, rdx
    je .done
    mov bl, byte [rsi + rcx]
    mov [rdi + rcx], bl
    inc rcx
    jmp .loop

.done:
    mov rax, rdi
    ret