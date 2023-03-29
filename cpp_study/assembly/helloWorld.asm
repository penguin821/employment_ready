%include "io64.inc"

section .text
global main
main:
    mov rbp, rsp; for correct debugging
    ;msg db 'hello world', 0x00
    ;PRINT_STRING msg
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
    ;mov rax, rdx
    
    ; 메모리 <-> 레지스
    
    ;mov rax, a ; a의 주소값을 rax에 복사   
    ;mov rax, [a] ; a의 값을 복사 (그러나 a 뒤의 값까지 다 가져옴)
    mov al, [a]
    mov [a], byte 0x55
    mov [a], word 0x6666
    mov [a], cl
           
    xor rax, rax
    ret
    
    ; 변수의 선언 및 사용
    ; 변수는 그냥 데이터를 저장하는 바구니
    ; 처음에 바구니 사용하겠다 선언
    
    ; 메모리에는 구분할 수 있는 주소값이 있음

    ; 초기화 된 데이터
    ; 변수이름, 크기, 초기값
    ; db=1,dw=2,dd=4,dq=8
    
section .data
    a db 0x11
    b dw 0x2222
    c dd 0x33333333
    d dq 0x4444444444444444

    ; 초기화 되지 않은 데이터
    ; 변수이름, 크기, 개수
    ; res(리저브)b=1,resw=2,resd=4,resq=8
    
    
    
section .bss
    e resb 10
    
    
    
    
    
    
    
    
  