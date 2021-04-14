#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <string.h>
#include <fstream>

#pragma comment(lib,"ws2_32")

SOCKET hxw_connect(const char* ip, int port)
{
    SOCKET sock;
    int res;
    struct sockaddr_in addr;
    struct hostent* host = NULL;
    memset(&addr, 0, sizeof(addr));
    host = gethostbyname(ip);
    if (host == NULL) {
        return -3;
    }
    memcpy(&(addr.sin_addr.s_addr), host->h_addr_list[0], 4);
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == SOCKET_ERROR) {
        return SOCKET_ERROR;
    }
    res = connect(sock, (struct sockaddr*) & addr, sizeof(addr));
    if (res < 0) {
        closesocket(sock);
        return SOCKET_ERROR;
    }
    return sock;
}


int run() {
    SOCKET sock;
    int res;
    char buf[1000];

    sock = hxw_connect("31337.1434.ru", 2122);
    if (sock == SOCKET_ERROR) {
        printf("[-] Can't connect to socket\n");
        return -1;
    }
    printf("[+] Connection successfull\n");

    res = recv(sock, buf, sizeof(buf) - 1, 0);
    if (res < 0) {
        printf("[-] Failed to receive data from remote\n");
        closesocket(sock);
        return -2;
    }
    buf[res] = '\0';
    printf("[+] Successfully received %d bytes: %s\n", res, buf);

    res = send(sock, "pw9USER Grishina_AA\r\n", 21, 0);
    if (res < 0) {
        printf("[-] Failed to send\n");
        closesocket(sock);
        return -4;
    }
    if (res < 21) {
        printf("[-] Sent only %d bytes out of 21\n", res);
        closesocket(sock);
        return -5;
    }
    printf("[+] Successfully sent %d bytes: %s\n", res, "pw9USER Grishina_AA");

    res = recv(sock, buf, sizeof(buf) - 1, 0);
    if (res < 0) {
        printf("[-] Failed to receive data from remote\n");
        closesocket(sock);
        return -2;
    }
    buf[res] = '\0';
    printf("[+] Successfully received %d bytes: %s\n", res, buf);


    res = send(sock, "pw9PASS JwbY7U79x3\r\n", 20, 0);
    if (res < 0) {
        printf("[-] Failed to send\n");
        closesocket(sock);
        return -4;
    }
    if (res < 20) {
        printf("[-] Sent only %d bytes out of 20\n", res);
        closesocket(sock);
        return -5;
    }
    printf("[+] Successfully sent %d bytes: %s\n", res, "pw9USER JwbY7U79x3");

    res = recv(sock, buf, sizeof(buf) - 1, 0);
    if (res < 0) {
        printf("[-] Failed to receive data from remote\n");
        closesocket(sock);
        return -2;
    }
    buf[res] = '\0';
    printf("[+] Successfully received %d bytes: %s\n", res, buf);



    res = send(sock, "pw9TYPE I\r\n", 11, 0);
    if (res < 0) {
        printf("[-] Failed to send\n");
        closesocket(sock);
        return -4;
    }
    if (res < 11) {
        printf("[-] Sent only %d bytes out of 11\n", res);
        closesocket(sock);
        return -5;
    }
    printf("[+] Successfully sent %d bytes: %s\n", res, "pw9TYPE I");

    res = recv(sock, buf, sizeof(buf) - 1, 0);
    if (res < 0) {
        printf("[-] Failed to receive data from remote\n");
        closesocket(sock);
        return -2;
    }
    buf[res] = '\0';
    printf("[+] Successfully received %d bytes: %s\n", res, buf);

    res = send(sock, "pw9PASV\r\n", 9, 0);
    if (res < 0) {
        printf("[-] Failed to send\n");
        closesocket(sock);
        return -4;
    }
    if (res < 9) {
        printf("[-] Sent only %d bytes out of 9\n", res);
        closesocket(sock);
        return -5;
    }
    printf("[+] Successfully sent %d bytes: %s\n", res, "pw9PASV");

    res = recv(sock, buf, sizeof(buf) - 1, 0);
    if (res < 0) {
        printf("[-] Failed to receive data from remote\n");
        closesocket(sock);
        return -2;
    }
    buf[res] = '\0';
    printf("[+] Successfully received %d bytes: %s\n", res, buf);

    char adress[100];
    char k = 0;
    int port = 0;
    int port2 = 0;
    for (int i = 0; i < 24; i++) {
        if (buf[i + 27] == ')') {
            port += port2;
            break;
        }
        if (k == 4) {
            if (buf[i + 27] == ',') {
                port *= 256;
            }
            else {
                port = port * 10 + (int)buf[i + 27] - 48;
            }
        }
        if (k == 5) {
            port2 = port2 * 10 + (int)buf[i + 27] - 48;
        }
        if (buf[i + 27] == ',') {
            if (k == 3) {
                k++;
                adress[i] = '\0';
                continue;
            }
            adress[i] = '.';
            k++;
        }
        else {
            adress[i] = buf[i + 27];
        }
    }

    SOCKET sock2;
    printf("[+] Adress %s, port %d\n", adress, port);
    sock2 = hxw_connect(adress, port);
    if (sock == SOCKET_ERROR) {
        printf("[-] Can't connect to socket\n");
        return -1;
    }
    printf("[+] Connection successfull\n");

    res = send(sock, "pw9CWD gANtdBm6T5bz8K\r\n", 23, 0);
    if (res < 0) {
        printf("[-] Failed to send\n");
        closesocket(sock);
        return -4;
    }
    if (res < 23) {
        printf("[-] Sent only %d bytes out of 23\n", res);
        closesocket(sock);
        return -5;
    }
    printf("[+] Successfully sent %d bytes: %s\n", res, "pw9CWD gANtdBm6T5bz8K");

    res = recv(sock, buf, sizeof(buf) - 1, 0);
    if (res < 0) {
        printf("[-] Failed to receive data from remote\n");
        closesocket(sock);
        return -2;
    }
    buf[res] = '\0';
    printf("[+] Successfully received %d bytes: %s\n", res, buf);

    res = send(sock, "pw9STOR core.c\r\n", 16, 0);
    if (res < 0) {
        printf("[-] Failed to send\n");
        closesocket(sock);
        return -4;
    }
    if (res < 16) {
        printf("[-] Sent only %d bytes out of 16\n", res);
        closesocket(sock);
        return -5;
    }
    printf("[+] Successfully sent %d bytes: %s\n", res, "pw9STOR core.c");

    res = recv(sock, buf, sizeof(buf) - 1, 0);
    if (res < 0) {
        printf("[-] Failed to receive data from remote\n");
        closesocket(sock);
        return -2;
    }
    buf[res] = '\0';
    printf("[+] Successfully received %d bytes: %s\n", res, buf);

    FILE* input = fopen("core.c", "r");
    fseek(input, 0L, SEEK_END);
    int total = ftell(input);
    fseek(input, 0L, SEEK_SET);
    char* buf2 = (char*)malloc(total);
    if (buf2 == NULL) {
        printf("[-] Failed to transfer data from fail to buffer\n");
        closesocket(sock);
        fclose(input);
        return -1;
    }
    res = fread(buf2, 1, total, input);
    if (res < total) {
        printf("[-] Transfered only %d bytes out of %d\n", res, total);
        closesocket(sock);
        fclose(input);
        return -1;
    }

    res = send(sock2, buf2, total, 0);
    if (res < 0) {
        printf("[-] Failed to send\n");
        closesocket(sock);
        return -4;
    }
    if (res < total) {
        printf("[-] Sent only %d bytes out of %d\n", res, total);
        closesocket(sock);
        return -5;
    }
    printf("[+] Successfully sent %d bytes\n", res);

    closesocket(sock);
    return 0;
}

int main(void) {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    int ret = run();

    WSACleanup();
    return ret;
}