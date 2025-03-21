BITS 64
section .text
global memfrob

memfrob:
    xor rcx, rcx

.loop:
    cmp rcx, rsi
    je .done
    xor byte [rdi + rcx], 42
    inc rcx
    jmp .loop

.done:
    mov rax, rdi
    ret