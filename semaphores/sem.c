#include <stdio.h>
#include <string.h> // string //
#include <stdlib.h>
#include <semaphore.h> // biblioteka z semaforami //
#include <unistd.h> // fork //
#include <sys/types.h> // pid //
#include <sys/wait.h> // wait //
#include <sys/stat.h> // o_creat //
#include <fcntl.h> // o_creat //
#include "sem.h"

sem_t *semCreate(const char *nazwa)
{
  sem_t *sem;
  if((sem=(sem_open(nazwa,O_CREAT,0666,1)))==SEM_FAILED)
    {
      perror("Blad tworzenia semafora \n");
      exit(EXIT_FAILURE);
    }
  return sem;
}

sem_t *semOpen(const char *nazwa)
{
  sem_t *sem;
  if((sem=(sem_open(nazwa,0)))==SEM_FAILED)
    {
      perror("Blad otwierania semafora \n");
      exit(EXIT_FAILURE);
    }
  return sem;
}

void semP(sem_t *semafor)
{
  if((sem_wait(semafor))==-1)
    {
      perror("Blad opuszczania semafora \n");
      exit(EXIT_FAILURE);
    }
  printf("Opuszczono semafor \n");
}
void semV(sem_t *semafor)
{
  if((sem_post(semafor))==-1)
    {
      perror("Blad podnoszenia semafora \n");
      exit(EXIT_FAILURE);	
    }
  printf("Podniesiono semafor \n");	
}
void semRemove(const char *nazwa)
{
  if((sem_unlink(nazwa))==-1)
    {
      perror("Blad usuwania semafora \n");
      exit(EXIT_FAILURE);
    }
  printf("Usunieto semafor \n");
}

int semClose(sem_t *semafor)
{
  int x;
  if((x=(sem_close(semafor)))==-1)
    { 
      perror("Blad zamykania semafora \n");
      exit(EXIT_FAILURE);	
    }
  printf("Zamknieto semafor \n");
  return x;
}

int semInfo(sem_t *semafor)
{
  int sval;
  int z;
  printf("Informacje o semaforze o pid: %d \n",getpid());
  if((z=(sem_getvalue(semafor, &sval)))==-1)
    {
      perror("Blad uzyskiwania wartosci semafora");
      exit(EXIT_FAILURE);
    }
  return z;
}
