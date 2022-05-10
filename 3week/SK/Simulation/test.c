#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void *p_function(void * data)
{
  int* value = (int *)data;
  int i = 0;

  while(i++ < 10000)
  {
    *value += 1;
		// usleep(1);
    printf("%d", *value);
  }
	return (void *)value;
}


int main(void)
{
  pthread_t pthread[2];
  int thr_id;
  int status;
  int value = 0;

  thr_id = pthread_create(&pthread[0], NULL, p_function, (void*)&value); //2
  if(thr_id < 0)
  {
    perror("pthread0 create error");
    exit(EXIT_FAILURE);
  }

  thr_id = pthread_create(&pthread[1], NULL, p_function, (void *)&value); //2
  if(thr_id < 0)
  {
    perror("pthread1 create error");
    exit(EXIT_FAILURE);
  }

  pthread_join(pthread[0], (void **)&status);
  pthread_join(pthread[1], (void **)&status);

  printf("\n Final Value: %d\n", value);
  return 0;
}