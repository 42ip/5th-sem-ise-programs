#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include <unistd.h>

int main(){
    int network_socket;
    char filename[20];
    network_socket = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;
    int connection_status = connect(network_socket,(struct sockaddr * ) &server_address,sizeof(server_address));
    printf("Enter filename to send: ");
    scanf("%s",filename);
    send(network_socket,&filename,sizeof(filename),0);
    // if (connection_status != -1){
    //     printf("error in making connection to socket\n");
    // }
    char server_response[250];
    recv(network_socket,&server_response,sizeof(server_response),0);
    printf("The server data is %s\n",server_response);
    close(network_socket);
    return 0;

}
int main(){
    int network_socket;
    char filename[20];
    network_socket = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_stat = connect(network_socket,(struct sockaddr_in * ) &server_address,sizeof(server_address) );
    if (connection_stat == -1);
    // print error
    scanf("%s",filename);
    send(network_socket,filename,sizeof(filename),0);
    char server_response[250];
    recv(network_socket,&server_response,sizeof(server_response),0);
    printf("response");
    close(network_socket);
    return 0;
}
 