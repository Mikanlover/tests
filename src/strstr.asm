BITS 64
section .text
global strstr

strstr:
    xor rax, rax
    cmp byte [rsi], 0
    je .done

.loop:
    xor rcx, rcx
    mov al, byte [rsi]
    cmp byte [rdi], 0
    je .end
    cmp byte [rdi], al
    je .loop_check_str
    inc rdi
    jmp .loop

.loop_check_str:
    inc rcx
    mov al, byte [rsi + rcx]
    cmp al, 0
    je .done
    cmp byte [rdi + rcx], al
    jne .inc_rdi
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