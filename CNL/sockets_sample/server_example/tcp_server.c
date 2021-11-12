// this program is a documented version of the program in the video https://www.youtube.com/watch?v=LtXEMwSG5-8

// On the server end , we need to create a socket, and then bind that socket to an ip
// address and port, where it can listen() for connections , and accept() a connection and 
// send() or recv() data to the other sockets it is connected to
#include <stdio.h>
#include <stdlib.h>

// for definitions of sockets and stuff
#include <sys/types.h>
#include <sys/socket.h>

// structures to store address information are in the following import
#include  <netinet/in.h>

#include <unistd.h>
int main(){
    char server_message[256] = "You have reached the server!!";
    // create server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM,0);

    // define server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;
    // we use bind just like connect()
    bind(server_socket,(struct sockaddr_in * ) &server_address,sizeof(server_address));
    // listen(socket of server, backlog - how many active connections can wait for the port : must be at least 1 ,  )
    listen(server_socket,5);
    int client_socket;
    // accept(socket,structure of address of client, sizeof client)
    // we dont need address and sizeof here since it is a local machine
    client_socket = accept(server_socket,NULL,NULL);
    // send(socket,data,size, flag)
    send(client_socket,server_message,sizeof(server_message),0);
    close(server_socket);
    return 0;
}