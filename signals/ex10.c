#include <stdio.h>
#include <stdlib.h> 
#include <sys/signal.h> 

#include <stdio.h>
#include <stdlib.h> 
#include <sys/signal.h> 
#include <unistd.h>
//Changing process group id

void CTR_handler(){
	printf("Process %d received CTR-C, exit\n", getpid());
	exit(2);
}

int main(int argc, char *argv[]){ 
	int i;
	printf("First process, PID= %d, PPID= %d, PGID= %d\n", getpid(), getppid(), getpgid(0));
	//getpgid(0) 0 indicates that the calling process' pgid will be returned
	signal(SIGINT, CTR_handler); //Register the handler

	for(i=1; i<=4; i++)
		fork();
	setpgid(0,getpid());
	printf("PID=%d PGID= %d\n", getpid(), getpgid(0)); 
	pause();
}
