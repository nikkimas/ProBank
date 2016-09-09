#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "global_vars.h"

#define BUF 1024

int create_socket;
char *buffer = malloc(BUF);
struct sockaddr_in address;
int size;

void b_close()
{
    b_send("EOK\n");
    close(create_socket);
}

void loop()
{
    do
    {
        b_send();
        b_recive();
    }while(strcmp(buffer, "EOT\n") != 0);
}

void b_send(char msg)
{
    send(create_socket, msg, strlen(msg), 0);
}

char b_recive()
{
    size = recv(create_socket, buffer, BUF-1, 0);
    if(size > 0)
    {
        buffer[size] = '\0';
    }
    return buffer;
}

int createClient(char server_addr)
{
    printf("\e[2J");
    if((create_socket = socket(AF_INET, SOCK_STREAM, 0)) > 0)
    {
        #ifdef DEBUG
        printf("Das Socket wurde angelegt!\n");
        #endif // DEBUG
    }
    address.sin_addr = AF_INET;
    address.sin_port = htons(15000);
    inet_aton(server_addr, &address.sin_addr);
    if(connect(create_socket, (struct sockaddr *) &address, sizeof(address)) == 0)
    {
        #ifdef DEBUG
        printf("Verbindung mit dem Server (%s) hergestellt\n", inet_ntoa(address.sin_addr));
        #endif // DEBUG
    }
}
