BITS 64
section .text
global memset

memset:
    xor rcx, rcx

.loop:
    cmp rcx, rdx
    je .done
    mov [rdi + rcx], sil
    inc rcx
    jmp .loop

.done:
    mov rax, rdi
    ret