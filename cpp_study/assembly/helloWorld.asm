%include "io64.inc"

section .text
global main
main:
    ;write your code here
    
    ; 10진수 0 1 2 ...
    ; 10 11 12 ...
    
    ; 2진수 0 1 10 11 100 101...
    ; 0b(바이너리)0, 0b1, 0b10, 0b11, 0b100, ...(표기법)
    
    ; 16진수 0 1 2 3 4...8 9 A B C D E F(15)
    ; D, E, F, 10, 11, .., 19, 1A, 2B, ...
    ; 0x로 표기, 0x00(표기법)
    
    ; 0b10010101 = 0b 1001 0101 = 0x 9 5 = 0x95
    
    
    PRINT_STRING msg
    
    xor rax, rax
    ret
    
section .data
    msg db 'hello world', 0x00