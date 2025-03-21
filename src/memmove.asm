BITS 64
section .text
global memmove

memmove:
    xor rcx, rcx
    xor r11b, r11b
    cmp rdi, rsi
    jg .copy_backward
    jl .copy_forward
    je .done

.copy_backward:
    cmp rdx, 0
    je .done
    mov r11b, byte [rsi + rdx - 1]
    mov [rdi + rdx - 1], r11b
    dec rdx
    jmp .copy_backward

.copy_forward:
    cmp rcx, rdx
    je .done
    mov r11b, byte [rsi + rcx]
    mov [rdi + rcx], r11b
    inc rcx
    jmp .copy_forward

.done:
    mov rax, rdi
    ret