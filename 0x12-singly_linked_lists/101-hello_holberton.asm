section .data
    hello db 'Hello, Holberton', 0
    newline db 10  ; Newline character
    format db '%s', 0

section .text
    global main
    extern printf, exit

main:
    ; Call printf function
    mov rdi, format
    mov rsi, hello
    xor rax, rax  ; Clear RAX register (no vector register is needed)
    call printf

    ; Print a newline
    mov rdi, newline
    xor rax, rax
    call printf

    ; Exit the program
    mov rdi, 0
    call exit

