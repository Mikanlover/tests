BITS 64
section .text
global strcasecmp

; A 65 Z 90 a 97 z 122

strcasecmp:
    xor r11b, r11b
    xor r12b, r12b
    xor rcx, rcx

.loop:
    ; first take a char from each string
    mov r11b, byte [rdi + rcx]
    mov r12b, byte [rsi + rcx]

    cmp r11b, 0
    je .done
    cmp r12b, 0
    je .done

    ; third check if first char is in uppercase, if yes lower him
    cmp r11b, 'A'
    jb .compare_char
    cmp r11b, 'Z'
    ja .check_second_char
    add r11b, 32

.check_second_char:
    ; fourth check if second char is in uppercase, if yes lower him
    cmp r12b, 'A'
    jb .compare_char
    cmp r12b, 'Z'
    ja .compare_char
    add r12b, 32

.compare_char:
    ; fifth compare two char
    cmp r11b, r12b
    jne .done

    inc rcx
    jmp .loop

.done:
    ; sixth sub the difference between two char and return
    sub r11b, r12b
    movsx rax, r11b
    ret