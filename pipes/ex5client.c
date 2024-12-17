#include <fcntl.h> //Client
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;
	char ch;
	printf("\nIn the client\n");
	while((fd=open("server", O_WRONLY))==-1)
	{
		printf("trying to connect to the server\n");
		sleep(1);
	}
	printf("Connected: type in data to be sent\n");
	
	while((ch=getchar()) != -1) 
		write(fd, &ch, 1);

	close(fd);
}
