// C program to demonstrates cancellation of another thread 
// using thread id

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
  
// To Count
int counter = 0; 
  

pthread_t main_thread,tmp_thread2,tmp_thread3; 
int main_pid;  

// thread_one call func
void* func1(void* p) 
{
    while (1) {
  
        printf("thread number one\n");
        sleep(1);   // sleep 1 second
        counter++;   
        
        // for exiting if counter = = 5
        if (counter == 5) {
  
           
            int ret1=pthread_cancel(tmp_thread2);
            printf("\nAttempting to kill thread2, the return value is %d\n", ret1); 
            int ret2=pthread_cancel(tmp_thread3);
            printf("\nAttempting to kill thread3, the return value is %d\n", ret2); 

            // for exit from thread_one 
            //pthread_exit(NULL);  
        }

        if (counter == 15) {
  
           
            int ret3=pthread_cancel(main_thread);
	    printf("\nAttempting to kill the main thread, the return value is %d\n", ret3); 
 
        }
    
  
           if (counter == 25) {
  
            printf("\nThread 1 tries to cancel or kill itself\n"); 
  
            int ret4=pthread_cancel(pthread_self());
 
        }
      


    }
}
  

void* func2(void* p) 
{
  
    // store thread_two id to tmp_thread
    tmp_thread2 = pthread_self(); 
  
    while (1) {
        printf("thread Number two\n");
        sleep(1); // sleep 1 second
    }
}


void* func3(void* p) 
{
  
    // store thread_two id to tmp_thread
    tmp_thread3 = pthread_self(); 
  
    while (1) {
        printf("thread Number three\n");
        sleep(1); // sleep 1 second
    }
}



  

int main()
{
  
    // declare three threads
     main_pid=getpid();

     main_thread=pthread_self();

     pthread_t thread_one, thread_two,thread_three; 

    pthread_create(&thread_one, NULL, func1, NULL);
    
    pthread_create(&thread_two, NULL, func2, NULL);
     
    pthread_create(&thread_three, NULL, func3, NULL); 

     while (1) {
        printf("Main\n");
        sleep(1); // sleep 1 second
    }
}