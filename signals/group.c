#include <stdio.h>
#include <stdlib.h> 
#include <sys/signal.h>
#include <unistd.h>

int main() 
{ 

	int a;
	int main_pid=getpid();
	printf("Main Process %d,%d,%d\n",getpid(),getppid(),getpgid(0)); 

	a=fork();
	a=fork();
	a=fork();

	printf("PID , PPID and PGID %d %d %d\n",getpid(),getppid(),getpgid(0));
	if(getpid()==main_pid){
		sleep(4);
		printf("Main sends SIGINT to the entire group\n");
		kill(0,SIGINT);
	}
	else 
		for(;;);

} 

