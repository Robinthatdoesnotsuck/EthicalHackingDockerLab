build-asm:
	nasm -f elf32 shellcode.asm -o shellcode.o
dump-mem-or-o:
	ld -m elf_i386 shellcode.o -o shellcode
