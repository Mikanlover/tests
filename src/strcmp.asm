BITS 64
section .text
global strcmp

strcmp:
    xor rcx, rcx

.loop:
    mov bl, byte [rdi + rcx]
    mov r11b, byte [rsi + rcx]
    cmp bl, r11b
    jne .done
    cmp bl, 0
    je .done
    cmp r11b, 0
    je .done
    inc rcx
    jmp .loop

.done:
    sub bl, r11b
    movsx rax, bl
    ret