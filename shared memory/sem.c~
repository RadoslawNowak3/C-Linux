#include "sem.h"

sem_t *semCreate(const char *nazwa)
{
  sem_t *sem;
  if((sem=sem_open(nazwa,O_CREAT | O_EXCL,0666,1))==SEM_FAILED)
{
	perror("Blad tworzenia semafora");
	exit(EXIT_FAILURE);
}
  printf("Utworzono semafor \n");
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
  printf("Otwarto semafor \n");
  return sem;
}
void semP(sem_t *semafor)
{
  if((sem_wait(semafor))==-1)
    {
      perror("Blad opuszczania semafora \n");
      exit(EXIT_FAILURE);
    }
}
void semV(sem_t *semafor)
{
  if((sem_post(semafor))==-1)
    {
      perror("Blad podnoszenia semafora \n");
      exit(EXIT_FAILURE);	
    }
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
  if((sem_getvalue(semafor, &sval))==-1)
    {
      perror("Blad uzyskiwania wartosci semafora");
      exit(EXIT_FAILURE);
    }
  return sval;
}
