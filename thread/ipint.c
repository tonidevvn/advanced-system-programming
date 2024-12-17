#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* func(void* p) {
   
   printf("From the thread function\n");
   int *num;
   num=p; 
   printf("The value of the input paramter to the thread function is %d\n",*num);
   //printf("The value of the input paramter to the thread function is %d\n",(int)num);
   sleep(1);
      
   return NULL;
}

int main() {
   int a=3900;
   pthread_t t1;

   pthread_create(&t1, NULL, func, (void *)&a);

   sleep(2);
}
