#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[32];

int main(int argc, char* argv[], char* envp[]) {
    if(argc < 2) {
        printf("pass argv[1] a number \n");
        return 0;
    }

    int fd = atoi(argv[1]) - 0x1234; // 4660

    int len = 0;
    len = read(fd, buf, 32);
    if(!strcmp("LETMEWIN\n", buf)) {
        printf("Good job: \n");
        system("/bin/bash");
        exit(0);
    }

    printf("learn about linux files and IO\n");
    return 0;
}