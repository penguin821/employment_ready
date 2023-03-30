%include "io64.inc"

section .text
global main
main:
     mov rbp, rsp; for correct debugging
    
    PRINT_STRING msg
    mov rbp, rsp; for correct debugging

    ; 초기화 된 데이터
    ; 변수이름, 크기, 초기값
    ; db=1,dw=2,dd=4,dq=8
section .data

    ;msg db 'hello world', 0x00 ; 문자열의 끝엔 0x00 = NULL이 들어가야함, 문자가 끝난단 의미
    msg db 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x77, 0x6f, 0x72, 0x6c, 0x64, 0x0
    
    
    a db 0x11
    ;a db 0x11,0x11,0x11,0x11
    
    b dd 0x12345678
    ; 데이터가 거꾸로 저장됨 = 리틀 엔디안 (인텔 라디안 둘다 리틀씀)
    
    ; 리틀 엔디언 : 캐스팅(큰 데이터를 작은 데이터로 변환)에 유리함
    ; 왜? 캐스팅 하면서 작은 단위로 갈때 가까운 주소값에 작은 단위 값이 저장되어 있음
    ; 빅 엔디언이였으면 주소값을 찾은 다음에 작은 단위가 저장되어있는 저 뒤쪽까지 건너건너 가야함 (효율 떨어짐)
    
    ; 빅 엔디언 : 숫자 비교에 유리함
    ; 왜? 큰 단위부터 비교해야하니까, 작은 단위부터 비교하면 계속 윗단위를 타고타고 올라가야함

    ; 초기화 되지 않은 데이터
    ; 변수이름, 크기, 개수
    ; res(리저브)b=1,resw=2,resd=4,resq=8
section .bss
 
    e resb 10
    
    
    
    
    
    
    
    
  