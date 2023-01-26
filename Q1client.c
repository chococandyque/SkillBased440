#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[256];
    int n;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0)
        perror("Error opening socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(22);
    server_addr.sin_addr.s_addr = inet_addr("192.168.234.9");

    if(connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    printf("Connected to server\n");


    bzero(buffer, sizeof(buffer));


    n = read(client_socket, buffer, sizeof(buffer)-1);
    if(n < 0)
        perror("Error read from socket");


    printf("Hello User!\n");
    printf("The generated number is: %s\n", buffer);


    close(client_socket);
    return 0;
}

