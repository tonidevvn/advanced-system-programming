
//bow.c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{

//Reads from check.txt into an array of characters

int fd3=open("check.txt",O_RDWR);
char *buff; 

for(int i=0;i<80;i++)
buff[i]='*';

long int n;

n=write(fd3,buff,80);

printf("\n\nThe number of bytes written were %ld\n",n);

close(fd3);


}
