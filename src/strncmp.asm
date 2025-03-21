BITS 64
section .text
global strncmp

strncmp:
    xor rcx, rcx

.loop:
    cmp rcx, rdx
    je .end
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

.end:
    xor rax, rax
    ret

.done:
    sub bl, r11b
    movsx rax, bl
    ret