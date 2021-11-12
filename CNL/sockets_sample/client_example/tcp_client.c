// This program is a documented version of the program in the video https://www.youtube.com/watch?v=LtXEMwSG5-8

#include <stdio.h>
#include <stdlib.h>

// for definitions of sockets and stuff
#include <sys/types.h>
#include <sys/socket.h>

// structures to store address information are in the following import
#include  <netinet/in.h>
// close() comes from unistd
#include <unistd.h>
int main(){
    // we use an integer to create the socket descriptor :- something that describes the socket
    int network_socket;
    // socket(domain,type,protocol)
    // SOCK_STREAM means it is a socket of tcp type
    // protocol = 0 here means we are using the default protocol, ie tcp
    network_socket = socket(AF_INET,SOCK_STREAM,0);
    // All these are already defined in the header files. 
    // netinet contains a structure with which we can know the address and port number of the socket 
    // so we can connect to another remote socket
    // specify an address for the socket : 
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    // here we use a conversion function which puts the integer port number into appropriate data format
    server_address.sin_port = htons(/* we choose a port that isnt used by the operating system here */ 9002);
    //  u can use the address 0.0.0.0 if you are running the thing locally 
    // server_address.sin_addr is a structure in itself and that contains one field holding the address of itself,
    // the server we want to connect to 
    server_address.sin_addr.s_addr = INADDR_ANY; // INADDR_ANY means it will connect to any server, mostly any local ones ie the 0.0.0.0
    //  connect(our_socket,server address cast as a sockaddr pointer, and size of the address)
    int connection_status = connect(network_socket,(struct sockaddr * ) &server_address,sizeof(server_address));
    if (connection_status != -1)
        printf("Error in making a connection to the remote socket\n");
    // if the connection succeeds 
    char server_response[250];
    // recv(socket,recieving_buffer,size_of_data/buffer),optional flags)
    recv(network_socket,&server_response,sizeof(server_response),0);
    // print out the data:
    printf("The server returned data : %s\n",server_response);
    // we close the socket next to end the program
    close(network_socket);
    return 0;

    return 0;
}
