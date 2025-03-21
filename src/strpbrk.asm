BITS 64
section .text
global strpbrk

strpbrk:
    xor rax, rax

.loop:
    xor rcx, rcx
    cmp byte [rdi], 0
    je .end
    jne .loop_check_str
    inc rdi
    jmp .loop

.loop_check_str:
    mov al, byte [rsi + rcx]
    cmp al, 0
    je .inc_rdi
    cmp byte [rdi], al
    je .done
    inc rcx
    jmp .loop_check_str

.inc_rdi:
    inc rdi
    jmp .loop

.end:
    xor rax, rax
    ret

.done:
    mov rax, rdi
    ret