//A client/server application(within a use and without sockets) where a server (this program) 
//accepts data from clients using the FIFO whose name is "server"
//Server program runs on one terminal 
//Client program/s run on other terminal/s 
#include <fcntl.h>
#include <stdio.h> // This is the server
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char *argv[]){
	int fd;
	char ch;
	unlink("server"); // delete the FIFO file if it exists
	
	if(mkfifo("server", 0777)!=0)//Create the FIFO file 
		exit(1);

	printf("Waiting for a client\n");
	fd = open("server", O_RDONLY);

	printf("Got a client: ");

	// The read call blocks until data is written to the pipe,

	while(read(fd, &ch, 1) == 1) 
		printf("%c", ch);
}//End main
