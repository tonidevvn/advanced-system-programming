#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
//f44.c

int main() 
{ 

	int a;
	int fd[2];

	pipe(fd);

	int k=write(fd[1],"ABCDEFGHIJKLMNOPQRSTUVWXYZ",26);  

	a=fork();
	a=fork();
	a=fork();

	char br[3];
	read(fd[0],br,3);
	printf("%s\n",br); 
}

