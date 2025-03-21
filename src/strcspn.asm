BITS 64
section .text
global strcspn

strcspn:
    xor rax, rax
    xor rcx, rcx
    xor r11, r11
    cmp byte [rsi], 0
    je .cout_len

.loop:
    xor rcx, rcx
    cmp byte [rdi], 0
    je .done
    jne .loop_check_str

.loop_check_str:
    mov al, byte [rsi + rcx]
    cmp al, 0
    je .inc_r11
    cmp byte [rdi], al
    je .done
    inc rcx
    jmp .loop_check_str

.inc_r11:
    inc r11
    inc rdi
    jmp .loop

.cout_len:
    cmp byte [rdi + rcx], 0
    je .end
    inc rcx
    jmp .cout_len

.end:
    mov rax, rcx
    ret

.done:
    mov rax, r11
    ret