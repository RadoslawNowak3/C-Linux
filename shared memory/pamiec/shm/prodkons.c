#define NELE 20 // Rozmiar elementu bufora
#define NBUF 5 //liczba elementów bufora
#include "pamdziel.h"
#include "sem.h"
int main(int argc, char * argv[]) {

  if (argc != 3) {
    printf("Niepoprawna liczba argumentow \n");
    printf("Przyklad wywolania \n");
    printf("./prodkons.x in out \n");
    exit(EXIT_FAILURE);
  }
  int shmid;
  const char * prog1 = "kons.x";
  const char * prog2 = "prod.x";
  const char * shmName = "/segmentPD";
  const char * sem1Name = "/sem1";
  const char * sem2Name = "/sem2";
  const char * shmAddr;
  shmid = shmCreate(shmName);
  sem_t * semKons;
  semKons = semCreate(sem1Name);
  sem_t * semProd;
  semProd = semCreate(sem2Name);
  int pid;
  switch (pid = fork()) {
  case -1:
    perror("fork error");
    exit(EXIT_FAILURE);
  case 0:
    execl(prog1, prog1, argv[2], shmName, sem1Name, sem2Name, NULL);
    perror("execl1 error");
  default:
    execl(prog2, prog2, argv[1], shmName, sem1Name, sem2Name, NULL);
    perror("execl2 error");
  }
  semClose(semKons);
  semClose(semProd);
  semRemove(sem1Name);
  semRemove(sem2Name);
  shmClose(shmid);
  shmDelete(shmName);
  return 0;
}
