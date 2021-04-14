#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <string.h>
#include <fstream>

int main(void) {


    char buf[1000];
    FILE* input = fopen("to.txt", "r");
    int total = 0;
    int res;
    FILE* output = fopen("x.txt", "w");
    while (res = fread(buf, 1, sizeof(buf)-2, input) > 0) {
        
        buf[sizeof(buf) - 1] = '\0';
        if (fprintf(output, buf) < res) {
            printf("[-] Transfered only %d bytes\n", res);

            fclose(input);
            fclose(output);
            return -2;
        }
        total += res;
        
        printf("[+] %s", buf);
    }
    if (res < 0) {
        printf("[-] Faild to read data from file\n");
        fclose(input);
        fclose(output);
        return -3;
    }
    printf("[+] Successfully sent %d bytes\n", total);
    fclose(input);
    fclose(output);

    /*int res = fread(buf2, 1, sizeof(buf2) - 1, input);
    int total = res;
    if (feof(input)) {
        printf("[+] Premature end of file.");
        fclose(input);
    }
    else {
        printf("[-] Transfered only %d bytes out of %d\n", res, 10000);
        fclose(input);
        return -1;
    }
    FILE* x = fopen("x.xtx", "w");
    fprintf(x, buf2);
    fclose(x);*/


    return 1;
}