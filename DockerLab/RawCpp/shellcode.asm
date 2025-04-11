pop -> top of stack to register -> pop edx
mov -> set data to register -> mov ebx, edx/0
xor -> bitwise xor operator -> xor eax, eax
push -> push data to top of stack/esp -> push eax
add -> add valute to register -> add eax, 5
inc -> increments register by 1 -> inc eax
mul -> multiplies register with eax, stored eax
syscalls -> 

Data 
eax, ebx, ecx, edx 
32 bits
eax
ax
mov al, 0x04 
mov bl, 0x1
push 0x 4f 4c 4c 45 48
mov ecx, esp
mov dl, 0x14

syscall/int 0x80
0000 0000 0000 0000 00000000 00000004 

eax = 4 -> Write(fd, buf, size)
ebx = fd - > bl
ecx = buf
edx = size
char algo = 15
1111 xor 1111
0000     0000



/usr/include/asm/unistd_32.h

libc -> (asm)

exit(0);

socketcall(int call, long args)

_start:
    xor eax, eax
    xor ebx, ebx
    