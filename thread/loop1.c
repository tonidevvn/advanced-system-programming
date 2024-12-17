#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
void* myThreadFunc1(){
	for(int i=0;i<5;i++){
		printf("First thread\n");
		sleep(1);
	}
	return NULL;
}

void* myThreadFunc2(){
	for(int i=0;i<15;i++){
		printf("Second thread\n");
		sleep(1);
	}
	return NULL;
}

int main (int argc, char *argv[]){

	pthread_t threadId1,threadId2;

	// Create a new thread to run myThreadFunc()
	pthread_create(&threadId1,NULL, myThreadFunc1,NULL);
	pthread_create(&threadId2,NULL, myThreadFunc2,NULL);

	pthread_join(threadId1,NULL);//Main waits until threadId1 completes execution
	pthread_join(threadId2,NULL);//Main waits until threadId2 completes execution

	printf("This is the main thread\n");

	return(0);
} // compile with -lpthread library link

