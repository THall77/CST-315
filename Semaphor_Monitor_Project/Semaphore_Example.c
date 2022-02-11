/*


Tyler Allen Hall
CST-315
Ricardo Citro
Feb 10, 2022

The purpose of this program is to
provide an example of how Semaphores work.



*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

#define THREAD_ID 5

sem_t sem;

void* routine(void* n){
    //Calls wait to only have this thread run.
    sem_wait(&sem);
    // Waits a second, showing how no other thread will run.
    // Then, it prints the name of which thread is currently running.
    sleep(1);
    printf("Greetings from thread: %d\n", *(int*)n);
    // Increments the semaphore so that the next thread will run.
    sem_post(&sem);
    free(n);

}


int main(){

  // Creates the Threads, 5 in total.
  pthread_t t[THREAD_ID];
  sem_init(&sem, 0, 1);
  int i;
  
  // A loop for each thread to go and print its message.
  for(i = 0; i < THREAD_ID; i++){
      // Create a variable to be passed into routine().
       int* n = malloc(sizeof(int));
        *n = i;
       // Checks to see if thread was made correctly.
      if(pthread_create(&t[i], NULL, &routine, n) != 0){
        perror("Couldn't make thread.");
        }
} 

  // Checks if the threads could join.
  for(i = 0; i < THREAD_ID; i++){

      if(pthread_join(t[i], NULL) !=0){

          perror("Can't join thread.");

      }

  }

  // Deletes semaphroe to free up memory.
  sem_destroy(&sem);
  return 0;  
}



