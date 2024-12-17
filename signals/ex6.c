//Swtiches between Parent and Child processes using kill()
#include <stdio.h>
#include <stdlib.h> 
#include <sys/signal.h> 
#include <unistd.h>

void  action(){  //User defined handler 
	printf("Switching\n");
}

int main(int argc, char *argv[]){ 
	pid_t pid;

	if((pid=fork())>0) //Parent
	{ 
		signal(SIGINT, action);  //Register Handler 
		while(1)
		{
			printf("Parent is running with PID %d and PPID %d\n",getpid(),getppid()); 
			sleep(2);
			kill(pid, SIGINT); //Send signal to child 
			pause(); //Wait for signal from the child process
		}
	}
	else
	{ //Child
			signal(SIGINT, action);  //do I really need this statement?
			while(1)
			{
				pause(); //Wait for signal from the parent process
				printf("Child is running with PID %d and PPID %d\n",getpid(),getppid()); 
				sleep(2);
				kill(getppid(), SIGINT); //Send signal to parent 
		} 
}
} //End main 


