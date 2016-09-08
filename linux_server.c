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

int create_socket, new_socket;
socklen_t addrlen;
char *buffer = malloc(BUF);
ssize_t size;
struct sockaddr_in address;
const int y = 1;

char b_recive()
{
    ssize_t t_size = recv(new_socket, buffer, BUF-1, 0);
    if(buffer[size] == '\0')
    {
        return buffer;
    }
}

void b_send(char msg)
{
    send(new_socket, buffer, strlen(buffer), 0);
}

void Communication()
{
    #ifdef DEBUG
    printf("Nachricht zum Versenden: ");
    #endif // DEBUG
    do
    {
        b_recive();
        #ifdef DEBUG
        printf("Nachricht empfangen: 5s\n", buffer);
        #endif // DEBUG
    }while(strcmp(buffer, "EOT\n") != 0);
}

void listenOnServer()
{
    while(1)
    {
        new_socket = accept(create_socket, (struct sockaddr *) &address, &addrlen);
        if(new_socket > 0)
        {
            #ifdef DEBUG
            printf("Ein Client (%s) ist verbunden ... \n", inet_ntoa(adress.sin_addr));
            #endif
            Communication();
        }
    }
}

int createServer(void)
{
    printf("\e[2J");
    if((create_socket=socket (AF_INET, SOCK_STREAM, 0)) > 0)
    {
        printf("Das Socket wurde angelegt!\n");
    }
    setsockopt(create_socket, SOL_SOCKET, SO_REUSEADDR, &y, sizeof(int));
    address.sin_family = AF_INET;
    address.sin_addr.S_addr = INADDR_ANY;
    address.sin_port = htons(15000);
    if(bind(create_socket, (struct sockaddr *) &address, sizeof(address)) != 0)
    {
        printf("Der Port ist belegt!\n");
    }
    listen(create_socket, 5);
    addrlen = sizeof(struct sockaddr_in);
    listenOnServer();
}
