BITS 64
section .text
global strrchr
global rindex

strrchr:
rindex:
    xor rcx, rcx
    xor rax, rax

.loop:
    mov cl, byte [rdi]
    cmp cl, sil
    jne .not_found
    mov rax, rdi

.not_found:
    cmp cl, 0
    je .end
    inc rdi
    jmp .loop

.end:
    cmp sil, 0
    jne .done
    mov rax, rdi

.done:
    ret