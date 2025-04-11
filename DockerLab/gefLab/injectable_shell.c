

char code [] = "\x31\xc0\xb0\x01\xcd\x80";

int main(int argc, char *argv[])
{
  int (*func)();
  func = (int (*)()) code;
  (int)(*func)();
  
  // If our shellcode goes south the return shall be 0
  return 1;
}
