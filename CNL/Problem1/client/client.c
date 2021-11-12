
//client
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, char **argv){
	int cs, n;
	int buffsize = 1024;
	char *buffer  = (char *) malloc(buffsize);
	char fname[255];
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(3002);
	// The inet_pton() function converts a presentation format address (that is,
    //  printable form as held in a character string) to network format (usually
    //  a struct in_addr or some other internal binary representation, in network
    //  byte order)
	if (argv[1] == NULL)
		address.sin_addr.s_addr = INADDR_ANY; // INADDR_ANY means it will connect to any server, mostly any local ones ie the 0.0.0.0
	else
		inet_pton(AF_INET,argv[1],&address.sin_addr);

	cs = socket(AF_INET,SOCK_STREAM,0);
	connect(cs,(struct sockaddr *) &address,sizeof(address));
	printf("Enter filename :");
	scanf("%s",fname);
	send(cs,fname,255,0);
	while ((recv(cs,buffer, buffsize,0)) > 0){
		printf("%s\n",buffer);	
	}
	printf("\n End of file!  \n");

	close(cs);
}