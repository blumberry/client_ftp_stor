#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <string.h>
#include <fstream>

/*int main(void) {

    char buf2[10000];

    FILE* input = fopen("core.c", "r");

    fseek(input, 0L, SEEK_END);
    int total1 = ftell(input);
    fseek(input, 0L, SEEK_SET);
    printf("%d", sizeof(buf2));

    int res = fread(buf2, 1, sizeof(buf2) - 1, input);
    int total = res;
    if (feof(input)) {
        printf("[+] Premature end of file\n");
        fclose(input);
    }
    else {
        printf("[-] Transfered only %d bytes out of %d\n", res, total1);
        fclose(input);
        return -1;
    }
    printf("[-] Transfered only %d bytes out of %d\n", res, total1);
    fclose(input);
    buf2[res] = '\0';
    FILE* x = fopen("x.txt", "w");
    fprintf(x, "%s", buf2);
    fclose(x);

    return 1;
}*/