#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "sem.h"
int main(int argc, char *argv[])
{
  if(argc!=3){
    printf("Niepoprawna liczba argumentow\n");
    printf("Przyklad wywolania \n");
    printf("./sekcja.x /mysem 3\n");
    exit(EXIT_FAILURE);
  }
  sem_t *semafor;
  semafor=semOpen(argv[1]);
  int i;
  int ilosc=atoi(argv[2]);
  for(i=0;i<ilosc;i++)
    {
      printf("Proces o pid %d rozpoczyna sekcje krytyczna \n",getpid());
      semP(semafor);
      printf("Sekcja krytyczna %d \n", semInfo(semafor));
      sleep(1);
      semV(semafor);
      printf("Koniec sekcji krytycznej procesu o pid %d\n",getpid());
    }
  semClose(semafor);	
  return 0;
}

