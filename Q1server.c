#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int client_addr_size;
    int n;
    char buffer [256];
    int randomnumber;


    server_socket = socket(PF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(22);
    server_addr.sin_addr.s_addr = INADDR_ANY;


    n = bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(n < 0){
        perror("Binding error");
        exit(1);
    }

    listen(server_socket, 5);
    printf("Waiting for client...\n");



    client_addr_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);


    srand(time(NULL));
    randomnumber = (rand() % 900) + 100;

    sprintf(buffer, "%d", randomnumber);

    printf("Connected to client \n");


    n = write(client_socket, buffer, sizeof(buffer));



    close(client_socket);
    close(server_socket);

   return 0;
}


