BITS 64
section .text
global strchr
global index

strchr:
index:

.loop:
    cmp byte [rdi], 0
    je .end
    cmp byte [rdi], sil
    je .end
    inc rdi
    jmp .loop

.end:
    cmp byte [rdi], sil
    je .done
    xor rax, rax
    ret

.done:
    mov rax, rdi
    ret