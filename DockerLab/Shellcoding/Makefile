compile-nasm:
	nasm -f elf32 -o tcp.o tcp_connect.asm

linking-park:
	ld -m elf_i386 -o tcp tcp.o

object-dump:
	objdump -M intel -D tcp
smart-object-dump:
	objdump -D ./tcp |grep '[0-9a-f]:'|grep -v 'file'|cut -f2 -d:|cut -f1-6 -d' '|tr -s ' '|tr '\t' ' '|sed 's/ $//g'|sed 's/ /\\x/g'|paste -d '' -s |sed 's/^/"/'|sed 's/$/"/g'
