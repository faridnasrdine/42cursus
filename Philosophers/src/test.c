#include <stdio.h>
#include <pthread.h>

# define NC "\e[1m"
# define YELLOW "\e[1;33m"

void *thread_routine(void *data)
{
 pthread_t tid;

 tid = pthread_self();
 printf("%sThread [%ld]: The heaviest burden is to exist without living.%s\n",
  YELLOW, tid, NC);
 return (NULL);
}

int main(void)
{
 pthread_t tid1; 
 pthread_t tid2;

 pthread_create(&tid1, NULL, thread_routine, NULL);
 printf("Main: Created first thread [%ld]\n", tid1);
 pthread_create(&tid2, NULL, thread_routine, NULL);
 printf("Main: Created second thread [%ld]\n", tid2);
 pthread_join(tid1, NULL);
 printf("Main: Joining first thread [%ld]\n", tid1);
 pthread_join(tid2, NULL);
 printf("Main: Joining second thread [%ld]\n", tid2);
 return (0);
}