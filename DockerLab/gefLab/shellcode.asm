
section .data
  msg: db '/bin/sh'

section .bss

section .text
  global _start ; 

_start:
  xor eax, eax ; 0 the eax
  mov al, 1 ; sys_exit 
  int 0x80 ; Call

_start:
  xor eax, eax
  xor ebx, ebx
  xor ecx, ecx
  xor edx, edx
  

  push eax
  push 0x68732f6e ; "h s / n"
  push 0x69622f2f ; "i b / /"
  mov ebx, esp
  mov al, 0xb ; 11 = execve
  int x80
