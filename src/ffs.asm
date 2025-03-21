BITS 64
section .text
global ffs

ffs:
    cmp rdi, 0
    je .done
    bsf rax, rdi
    inc rax
    ret

.done:
    xor rax, rax
    ret