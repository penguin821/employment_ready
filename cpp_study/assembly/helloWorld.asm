%include "io64.inc"

section .text
global main
main:
    ;write your code here
    
    PRINT_STRING msg
    
    xor rax, rax
    ret
    
section .data
    msg db 'hello world', 0x00