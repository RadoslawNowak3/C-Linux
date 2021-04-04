#define NELE 20 // Rozmiar elementu bufora
#define NBUF 5 //liczba elementów bufora
#include "pamdziel.h"
#include "sem.h"
# define MAX 200
int main(int argc, char * argv[]) {
  int shmid, fd, counter; // id pamieci, deskryptor pliku
  char tab[MAX];
  printf("Z tej strony konsument \n");
  //otwieranie pamieci dzielonej i semaforow //
  shmid = shmOpen(argv[2]);
  SegmentPD * buf;
  buf = (SegmentPD * ) shmMap(NULL, shmid); // odwzorowanie pamieci //
  buf->wyjmij = 0;
  sem_t * semProd;
  semProd = semOpen(argv[4]);
  sem_t * semKons;
  semKons = semOpen(argv[3]);
  //otwieranie pliku wyjsciowego //
  if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1) {
    perror("File open error");
    exit(EXIT_FAILURE);
  };
  while (1) {
    semP(semKons); // opuszczam semafor konsumenta
    k=0;
    while ((buf->bufor[buf->wyjmij][k]) && k < 20) {
      tab[k]=(buf->bufor[buf->wyjmij][k]);
      k++;
    };
    if (counter=(write(fd, tab, k)) == -1) {
      perror("Write error");
      exit(EXIT_FAILURE);
    }
    (buf->wyjmij) = (buf->wyjmij+1)%NBUF;
    if(counter!=0)
    break;	
    sleep(1);
    semV(semProd); // podnosze semafor producenta
  };
  semClose(semKons);
  semClose(semProd);
  shmClose(shmid);
  shmUnmap(buf);	
  return 0;
}
