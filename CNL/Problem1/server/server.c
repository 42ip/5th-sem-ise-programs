//server 
#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>

#include<netinet/in.h>

// unistd has the O_RDONLY constant
#include<unistd.h>
#include<fcntl.h>

#include<arpa/inet.h>

int main(int argc, char **argv){
	int cs, ns , fd, n;
	int buffsize = 1024;
	char * buffer = (char *) malloc(buffsize);
	struct sockaddr_in address;
	char fname[255];
	address.sin_family = AF_INET;
	address.sin_port = htons(3002);
	address.sin_addr.s_addr = INADDR_ANY;

	cs = socket(AF_INET,SOCK_STREAM,0);
	bind(cs,(struct sockaddr * ) &address,sizeof(address));
	printf("Will listen now \n ");

	listen(cs,3);
	ns = accept(cs,(struct sockaddr * ) NULL,NULL);
	recv(ns,fname,255,0);
	printf("file name asked is %s \n", fname);
	fd = open(fname,O_RDONLY);
	// printf("Fd is %d",fd); : if the file doesn't exist then
	//  fd is -1. we send error message then.
	if (fd == -1)
		fd = open("error.txt",O_RDONLY);
	n = read(fd, buffer, buffsize);
	send(ns,buffer,n,0);
	close(ns);
}

