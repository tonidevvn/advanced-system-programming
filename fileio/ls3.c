#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

//ls2.c with SEEK_CUR

main()
{

int fd3=open("check.txt",O_RDWR);

int long n;

char * buff1="COMP 8567";

n=lseek(fd3,10000000,SEEK_END);

printf("\nThe resulting offset is %d\n",n);

n=write(fd3,buff1,9);
printf("\nThe no of bytes written from the resulting offset is %d\n",n);
 
close(fd3);

}
