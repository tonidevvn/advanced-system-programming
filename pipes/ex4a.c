#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
 
 //equivalent of $ls|wc|wc -w 

int main(int argc, char *argv[]){
	int p1[2];

	if(pipe(p1)==-1) //pipe (p1) between ls|wc 
		exit(1);

	if(fork() > 0)//parent 
	{
		close(p1[0]);
		dup2(p1[1], 1); 
		execlp("ls","ls", NULL);
	}
	else 
	{
		close(p1[1]);
		dup2(p1[0], 0);
		int p2[2];
		pipe(p2); //Pipe (p2) between wc|wc-w 
		int pid2=fork(); 
		if(pid2>0){
			close(p2[0]);
			dup2(p2[1],1);
			execlp("wc","wc",NULL);
		} 
		else //Child's child 
		{
		close(p2[1]);
		dup2(p2[0],0);
		execlp("wc","wc","-w",NULL);
		} 
	 
	}
}//End main
