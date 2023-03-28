%include "io64.inc"

section .text
global main
main:
    mov rbp, rsp; for correct debugging
    ;write your code here
    
    ; 10진수 0 1 2 ...
    ; 10 11 12 ...
    
    ; 2진수 0 1 10 11 100 101...
    ; 0b(바이너리)0, 0b1, 0b10, 0b11, 0b100, ...(표기법)
    
    ; 16진수 0 1 2 3 4...8 9 A B C D E F(15)
    ; D, E, F, 10, 11, .., 19, 1A, 2B, ...
    ; 0x로 표기, 0x00(표기법)
    
    ; 0b10010101 = 0b 1001 0101 = 0x 9 5 = 0x95
    
    ; 32bit = 4byte = 2word = 1dword(double word)
    ; 64bit = 8byte = 4word = 2dword = 1qword(quad word)
    
    ; mov 레지스터, 값 (오른쪽에서 왼쪽으로 명령 수행)
    ; mov 레지스터, 레지스터
    
    mov eax, 0x1234
    mov rbx, 0x12345678
    mov cl,0xff
    
    mov al, 0x00
    mov rax, rdx
    
    PRINT_STRING msg
    
    xor rax, rax
    ret
    
section .data
    msg db 'hello world', 0x00